
#include <mmplayer/mmplayerclient.h>


/**
 * @brief Connect to mm-player and obtain a handle.
 *
 * @param [out] hdl			a mm-player connection handle on success
 * @param [in] flags		reserved for future use
 * @return handle on success or NULL on failure
 */
mmplayer_hdl_t *mm_player_connect(int flags)
{
    return 0;
}

/**
 * @brief Disconnect from mm-player.
 *
 * @param [in] hdl	The mm-player connection handle
 * @return 0 on success
 *         -1 if any resources could not be fully released
 */
int mm_player_disconnect(mmplayer_hdl_t *hdl)
{
    return 0;
}

/**
 * Open a connection to a player with name specified by player_name. if the
 * player is not existed, it will be created. Otherwise the client will be
 * connected to the existed player named player_name. All the following
 * commands issued by the client will be directed to this player.
 *
 * @param hdl			The mm-player connection handle
 * @param player_name	A specific player to be connected.
 * @param oflag			Flags that specify the status and access modes of the file.
 * 						Not used for the moments. It should be set to 0.
 * @return 0 on success or -1 on failure
 */
int mm_player_open(mmplayer_hdl_t *hdl, const char* player_name, int oflag)
{
    return 0;
}

/**
 * Close a connection to a player with name specified by player_name. If the
 * client wants to control the player named player_name again, it should call
 * mm_player_open first.
 *
 * @param hdl			The mm-player connection handle
 * @param player_name	A specific player to be disconnected.
 * @return 0 on success or -1 on failure
 */
int mm_player_close(mmplayer_hdl_t *hdl, const char* player_name)
{
    return 0;
}

/**
 * Get info of media sources connected to the target. The library will
 * allocate memory for media_sources. However, it is the responsibility
 * of the client to deallocate them.
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [out] media_sources	array of currently connected media sources
 * @param [out] len				size of array
 * @return 0 on success or -1 on failure
 */
int mm_player_get_media_sources(mmplayer_hdl_t *hdl, mmp_ms_t **media_sources, int *len)
{
    return 0;
}

/**
 * Get info of media nodes within a trksession
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] tsid				trksession id
 * @param [in] offset			offset within the session
 * @param [in, out] limit		maximum items to be returned
 * 								and actually found node counts on success
 * @param [out] media_nodes		array of found nodes
 * @return 0 on success or -1 on failure
 */
int mm_player_get_trksession_tracks(mmplayer_hdl_t *hdl, const uint64_t tsid,
        const int offset, int *limit, mmp_ms_node_t **media_nodes)
{
    return 0;
}


/**
 * Get the current connected Player's state. The library will
 * allocate memory for state. However, it is the responsibility
 * of the client to deallocate them.
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [out] state	current player state
 * @return 0 on success or -1 on failure
 */
int mm_player_get_current_state(mmplayer_hdl_t *hdl, mmp_state_t **state)
{
    return 0;
}

/**
 * Get the current connected Player's trksession information. The library will
 * allocate memory for trksession_info. However, it is the responsibility
 * of the client to deallocate them.
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [out] trksession_info	current trksession info
 * @return 0 on success or -1 on failure
 */
int mm_player_get_current_trksession_info(mmplayer_hdl_t *hdl, mmp_trksession_info_t **trksession_info)
{
    return 0;
}

/**
 * Get the current playing track information. The library will
 * allocate memory for track_info. However, it is the responsibility
 * of the client to deallocate them.
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [out] track_info	current playing track info
 * @return 0 on success or -1 on failure
 */
int mm_player_get_current_track_info(mmplayer_hdl_t *hdl, mmp_track_info_t **track_info)
{
    return 0;
}

/**
 * Get the position of currently playing or paused track. The call fails if
 * there is no active trksession or track. It is suggested that the position
 * of the playing should be retrieved through the event delivery instead of
 * using this function call.
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [out] position	current position of the track
 * @return 0 on success or -1 on failure
 */
int mm_player_get_current_track_position(mmplayer_hdl_t *hdl, int *position)
{
    return 0;
}

/**
 * Browse a media node in a media source
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] media_source_id	unique media source id
 * @param [in] media_node_id	unique media node id
 * @param [in] offset			offset within the node
 * @param [in, out] limit		maximum items to be returned
 * 								and actually found item counts on success
 * @param [out] media_nodes		array of found media nodes
 * @return 0 on success or -1 on failure
 */
int mm_player_browse(mmplayer_hdl_t *hdl, const int media_source_id,
		const char * media_node_id, const int offset, int *limit,
        mmp_ms_node_t **media_nodes)
{
    return 0;
}

/**
 * Get metadata associated with a media node. The library will
 * allocate memory for metadata. However, it is the responsibility
 * of the client to deallocate them.
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] media_source_id	media source id
 * @param [in] media_node_id	media node id
 * @param [out] metadata		metadata associated with media node
 * @return 0 on success or -1 on failure
 */
int mm_player_get_metadata(mmplayer_hdl_t *hdl, const int media_source_id,
        const char *media_node_id, mmp_ms_node_metadata_t **metadata)
{
    return 0;
}

/**
 * Get extended metadata associated with a media node.
 * The last member of keyv must be a NULL pointer. The size of keyv and
 * valuev must be the same.
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] media_source_id	media source id
 * @param [in] media_node_id	media node id
 * @param [in] keyv				Interested metadata fields' array
 * @param [out] valuev			Value of the interested fields' array
 * @return 0 on success or -1 on failure
 */
int mm_player_get_extended_metadata(mmplayer_hdl_t *hdl, const int media_source_id,
        const char *media_node_id, char * const keyv[], char * valuev[])
{
    return 0;
}

/**
 * Search a media source given a key string and a filter.
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] media_source_id	media source to be searched
 * @param [in] filter			filter for the search (can be NULL)
 * @param [in] search_term		string to be searched
 * @param [in] offset			offset within the node
 * @param [in, out] limit		maximum items to be returned
 * 								and actually found item counts on success
 * @param [out] media_nodes		array of found media nodes
 * @return 0 on success or -1 on failure
 */
int mm_player_search(mmplayer_hdl_t *hdl, const int media_source_id,
		const char* filter, const char * search_term,
        const int offset, int *limit, mmp_ms_node_t **media_nodes)
{
    return 0;
}

/**
 * Create a trksession for a given media node
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] media_source_id	media source id
 * @param [in] media_node_id	media node id
 * @param [in, out] limit		maximum media nodes in the trksession
 * 								and actual media nodes on success
 * @param [in] index			The index respected to the offset to
 * 								be set as the current track
 * @param [out] tsid			trksession id
 * @return 0 on success or -1 on failure
 */
int mm_player_create_trksession(mmplayer_hdl_t *hdl, const int media_source_id,
        const char* media_node_id, int *limit, const int index, uint64_t* tsid)
{
    return 0;
}

/**
 * Delete a trksession
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] tsid				trksession id
 * @return 0 on success or -1 on failure
 */
int mm_player_destroy_trksession(mmplayer_hdl_t *hdl, const uint64_t tsid)
{
    return 0;
}


/**
 * Start to play
 *
 * @param [in] hdl				The mm-player connection handle
 * @return 0 on success or -1 on failure
 */
int mm_player_play(mmplayer_hdl_t *hdl)
{
    return 0;
}

/**
 * Stop the playing of the current track
 *
 * @param [in] hdl				The mm-player connection handle
 * @param [in] index			index of media node within trksession to be played
 * @return 0 on success or -1 on failure
 */
int mm_player_stop(mmplayer_hdl_t *hdl)
{
    return 0;
}

/**
 * Pause the current playing track
 *
 * @param [in] hdl	The mm-player connection handle
 * @return 0 on success or -1 on failure
 */
int mm_player_pause(mmplayer_hdl_t *hdl)
{
    return 0;
}

/**
 * Play the next track
 *
 * @param [in] hdl	The mm-player connection handle
 * @return 0 on success or -1 on failure
 */
int mm_player_next(mmplayer_hdl_t *hdl)
{
    return 0;
}

/**
 * Play the previous track
 *
 * @param [in] hdl	The mm-player connection handle
 * @return 0 on success or -1 on failure
 */
int mm_player_previous(mmplayer_hdl_t *hdl)
{
    return 0;
}

/**
 * Set index of track within the active trksession to be played
 *
 * @param hdl [in]				The mm-player connection handle
 * @param index [in]			The index respected to the offset to
 * 								be set as the current track
 * @return 0 on success or -1 on failure
 */
int mm_player_jump(mmplayer_hdl_t *hdl, const int index)
{
    return 0;
}

/**
 * Seek to a position
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [in] position	in milliseconds
 * @return 0 on success or -1 on failure
 */
int mm_player_seek(mmplayer_hdl_t *hdl, const int position)
{
    return 0;
}

/**
 * Set playback rate
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [in] rate	playback rate relative a normal playback being 1.0
 * @return 0 on success or -1 on failure
 */
int mm_player_set_playback_rate(mmplayer_hdl_t *hdl, const float rate)
{
    return 0;
}

/**
 * Set shuffle mode
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [in] mode	SHUFFLE_*
 * @return 0 on success or -1 on failure
 */
int mm_player_shuffle(mmplayer_hdl_t *hdl, const shuffle_e mode)
{
    return 0;
}

/**
 * Set repeat mode
 *
 * @param [in] hdl	The mm-player connection handle
 * @param [in] mode	REPEAT_*
 * @return 0 on success or -1 on failure
 */
int mm_player_repeat(mmplayer_hdl_t *hdl, const repeat_e mode)
{
    return 0;
}

