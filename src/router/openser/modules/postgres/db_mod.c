/* 
 * $Id: db_mod.c,v 1.1.1.1 2005/06/13 16:47:43 bogdan_iancu Exp $ 
 *
 * Postgres module interface
 *
 * Copyright (C) 2001-2003 FhG Fokus
 *
 * This file is part of openser, a free SIP server.
 *
 * openser is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * openser is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 * --------
 *  2003-03-11  updated to the new module exports interface (andrei)
 *  2003-03-16  flags export parameter added (janakj)
 */

#include <stdio.h>
#include "../../sr_module.h"
#include "../../db/db_con.h"
#include "dbase.h"

MODULE_VERSION

static int mod_init(void);


/*
 * MySQL database module interface
 */


static cmd_export_t cmds[]={
	{"db_use_table",   (cmd_function)use_table,     2, 0, 0},
	{"db_init",        (cmd_function)db_init,       1, 0, 0},
	{"db_close",       (cmd_function)db_close,      2, 0, 0},
	{"db_query",       (cmd_function)db_query,      2, 0, 0},
	{"db_raw_query",   (cmd_function)db_raw_query,  2, 0, 0},
	{"db_free_result", (cmd_function)db_free_query, 2, 0, 0},
	{"db_insert",      (cmd_function)db_insert,     2, 0, 0},
	{"db_delete",      (cmd_function)db_delete,     2, 0, 0},
	{"db_update",      (cmd_function)db_update,     2, 0, 0},
	{0,0,0,0,0}
};



struct module_exports exports = {	
	"postgres",
	cmds,
	0,   /*  module parameters */

	mod_init, /* module initialization function */
	0,        /* response function*/
	0,        /* destroy function */
	0,        /* oncancel function */
	0         /* per-child init function */
};


static int mod_init(void)
{
	fprintf(stderr, "postgres - initializing\n");
	return 0;
}
