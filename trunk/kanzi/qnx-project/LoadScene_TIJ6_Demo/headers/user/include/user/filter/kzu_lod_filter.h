/**
* \file
* Specifies level of detail filter.
* Level of detail filter filters any undesired level of detail object nodes that occur.
*
* Basic functionality for LOD filter:
*
* 1) Loop through scene graph, search for LOD nodes.
* 2) Add child nodes recursively to hash map.
* 3) When applying filter
*   - If node was not found from hash map, nothing is filtered.
*   - If node was found, see the hash map value and if LOD constraint is fulfilled, nothing is filtered,
*      otherwise node is selected away.
* 
* Copyright 2008-2014 by Rightware. All rights reserved.
*/
#ifndef KZU_LOD_FILTER_H
#define KZU_LOD_FILTER_H


#include <system/kzs_types.h>
#include <system/debug/kzs_error.h>
#include <system/kzs_header.h>


KZ_HEADER_BEGIN


/* Forward declarations */
struct KzcMemoryManager;
struct KzuUIDomain;
struct KzuObjectSource;


/** Creates level of detail filter. */
kzsError kzuLODFilterCreate(const struct KzcMemoryManager* memoryManager,  struct KzuUIDomain* uiDomain,
                            struct KzuObjectSource* input, kzString name, struct KzuObjectSource** out_objectSource);


KZ_HEADER_END


#endif
