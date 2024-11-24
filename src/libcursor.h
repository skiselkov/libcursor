/*
 * CONFIDENTIAL
 *
 * Copyright 2021 Saso Kiselkov. All rights reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property
 * of Saso Kiselkov. The intellectual and technical concepts contained
 * herein are proprietary to Saso Kiselkov and may be covered by U.S. and
 * Foreign Patents, patents in process, and are protected by trade secret
 * or copyright law. Dissemination of this information or reproduction of
 * this material is strictly forbidden unless prior written permission is
 * obtained from Saso Kiselkov.
 */

#ifndef	_LIBCURSOR_H_
#define	_LIBCURSOR_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	LIBCURSOR_HAND_INDEX,		/* hand with index finger extended */
	LIBCURSOR_HAND_OPEN,		/* open hand with all fingers ext'd */
	LIBCURSOR_HAND_CLOSED,		/* closed hand */
	LIBCURSOR_ARROW_UP,		/* arrow pointing up */
	LIBCURSOR_ARROW_DOWN,		/* arrow pointing down */
	LIBCURSOR_ARROW_LEFT,		/* arrow pointing left */
	LIBCURSOR_ARROW_RIGHT,		/* arrow pointing left */
	LIBCURSOR_WHEEL_SMALL,		/* small mouse wheel symbol */
	LIBCURSOR_WHEEL_SMALL_UP,	/* small mouse wheel + up arrow */
	LIBCURSOR_WHEEL_SMALL_DOWN,	/* small mouse wheel + down arrow */
	LIBCURSOR_WHEEL_SMALL_LEFT,	/* small mouse wheel + left arrow */
	LIBCURSOR_WHEEL_SMALL_RIGHT,	/* small mouse wheel + right arrow */
	LIBCURSOR_WHEEL_LARGE,		/* mouse wheel large */
	LIBCURSOR_WHEEL_LARGE_UP,	/* large mouse wheel + up arrow */
	LIBCURSOR_WHEEL_LARGE_DOWN,	/* large mouse wheel + down arrow */
	LIBCURSOR_WHEEL_LARGE_LEFT,	/* large mouse wheel + left arrow */
	LIBCURSOR_WHEEL_LARGE_RIGHT,	/* large mouse wheel + right arrow */
	NUM_LIBCURSORS
} libcursor_t;

void libcursor_init(const char *datadir);
void libcursor_fini(void);

bool libcursor_set(libcursor_t cursor);

#ifdef __cplusplus
}
#endif

#endif	/* _LIBCURSOR_H_ */
