/* MateConf
 * Copyright (C) 1999, 2000 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef MATECONF_MATECONFD_H
#define MATECONF_MATECONFD_H

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "mateconf-error.h"
#include "MateConfX.h"
#include "mateconf-database.h"

PortableServer_POA mateconf_get_poa (void);

/* return TRUE if the exception was set, clear err if needed */
gboolean mateconf_set_exception (GError** err, CORBA_Environment* ev);

gboolean mateconfd_logfile_change_listener (MateConfDatabase *db,
                                         gboolean add,
                                         guint connection_id,
                                         ConfigListener listener,
                                         const gchar *where,
                                         GError **err);

gboolean mateconfd_check_in_shutdown (CORBA_Environment *ev);

void mateconfd_notify_other_listeners (MateConfDatabase *modified_db,
				    MateConfSources  *modified_sources,
                                    const char    *key);

void
mateconfd_clear_cache_for_sources (MateConfSources *sources);

void mateconfd_need_log_cleanup (void);

#ifdef __cplusplus
}
#endif

#endif



