/*
Open Asset Import Library (assimp)
----------------------------------------------------------------------

Copyright (c) 2006-2012, assimp team
All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the 
following conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/

/** @file  FBXImportSettings.h
 *  @brief FBX importer runtime configuration
 */
#ifndef INCLUDED_AI_FBX_IMPORTSETTINGS_H
#define INCLUDED_AI_FBX_IMPORTSETTINGS_H

namespace Assimp {
namespace FBX {

/** FBX import settings, parts of which are publicly accessible via their corresponding AI_CONFIG constants */
struct ImportSettings 
{
	ImportSettings()
		: readAllLayers(true)
		, readAllMaterials()
		, readMaterials(true)
		, readCameras(true)
		, readLights(true)
		, readAnimations(true)
	{}

	/** specifies whether all geometry layers are read and scanned for
	  * usable data channels. The FBX spec indicates that many readers
	  * will only read the first channel and that this is in some way
	  * the recommended way- in reality, however, it happens a lot that 
	  * vertex data is spread among multiple layers. The default
	  * value for this option is true.*/
	bool readAllLayers;

	/** specifies whether all materials are read, or only those that
	 *  are referenced by at least one mesh. Reading all materials
	 *  may make FBX reading a lot slower since all objects
	 *  need to be processed .
	 *  This bit is ignored unless readMaterials=true*/
	bool readAllMaterials;


	/** import materials (true) or skip them and assign a default 
	 *  material. The default value is true.*/
	bool readMaterials;

	/** import cameras? Default value is true.*/
	bool readCameras;

	/** import light sources? Default value is true.*/
	bool readLights;

	/** import animations (i.e. animation curves, the node
	 *  skeleton is always imported)? Default value is true. */
	bool readAnimations;
};


} // !FBX
} // !Assimp

#endif

