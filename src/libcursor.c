/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
/*
 * Copyright 2024 Saso Kiselkov. All rights reserved.
 */

#include <acfutils/assert.h>
#include <acfutils/cursor.h>
#include <acfutils/helpers.h>

#include "libcursor.h"

static const char *cursor_filenames[NUM_LIBCURSORS] = {
    [LIBCURSOR_HAND_INDEX] = "cursor_click.png",
    [LIBCURSOR_HAND_OPEN] = "cursor_grab_open.png",
    [LIBCURSOR_HAND_CLOSED] = "cursor_grab_closed.png",
    [LIBCURSOR_ARROW_UP] = "cursor_up.png",
    [LIBCURSOR_ARROW_DOWN] = "cursor_down.png",
    [LIBCURSOR_ARROW_LEFT] = "cursor_left.png",
    [LIBCURSOR_ARROW_RIGHT] = "cursor_right.png",
    [LIBCURSOR_WHEEL_SMALL] = "cursor_wheel.png",
    [LIBCURSOR_WHEEL_SMALL_UP] = "cursor_wheel_up.png",
    [LIBCURSOR_WHEEL_SMALL_DOWN] = "cursor_wheel_down.png",
    [LIBCURSOR_WHEEL_SMALL_LEFT] = "cursor_wheel_left.png",
    [LIBCURSOR_WHEEL_SMALL_RIGHT] = "cursor_wheel_right.png",
    [LIBCURSOR_WHEEL_LARGE] = "cursor_wheel_large.png",
    [LIBCURSOR_WHEEL_LARGE_UP] = "cursor_wheel_up_large.png",
    [LIBCURSOR_WHEEL_LARGE_DOWN] = "cursor_wheel_down_large.png",
    [LIBCURSOR_WHEEL_LARGE_LEFT] = "cursor_wheel_left_large.png",
    [LIBCURSOR_WHEEL_LARGE_RIGHT] = "cursor_wheel_right_large.png"
};

static cursor_t *cursors[NUM_LIBCURSORS] = { NULL };

static char *datadir = NULL;

void
libcursor_init(const char *datadir_in)
{
	ASSERT(datadir_in != NULL);
	ASSERT3P(datadir, ==, NULL);
	datadir = safe_strdup(datadir_in);
}

void
libcursor_fini(void)
{
	for (int i = 0; i < NUM_LIBCURSORS; i++) {
		if (cursors[i] != NULL) {
			cursor_free(cursors[i]);
			cursors[i] = NULL;
		}
	}
	free(datadir);
	datadir = NULL;
}

bool
libcursor_set(libcursor_t cursor)
{
	ASSERT(datadir != NULL);
	ASSERT3U(cursor, <, NUM_LIBCURSORS);
	/*
	 * This must only be called from the main thread, so we can
	 * safely manipulate the shared array without risking corruption.
	 */
	if (cursors[cursor] == NULL) {
		char *filename = mkpathname(datadir,
		    cursor_filenames[cursor], NULL);

		cursors[cursor] = cursor_read_from_file(filename);
		lacf_free(filename);
		if (cursors[cursor] == NULL)
			return (false);
	}
	cursor_make_current(cursors[cursor]);
	return (true);
}
