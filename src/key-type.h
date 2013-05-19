/* Copyright (C) 2013 Artyom V. Poptsov <poptsov.artyom@gmail.com>
 *
 * This file is part of libguile-ssh
 * 
 * libguile-ssh is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * libguile-ssh is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libguile-ssh.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __KEY_TYPE_H__
#define __KEY_TYPE_H__

#include <libguile.h>
#include <libssh/libssh.h>

extern scm_t_bits key_tag;

/* Possible key types. */
enum KEY_TYPE {
  KEY_TYPE_NONE,
  KEY_TYPE_PRIVATE,
  KEY_TYPE_PUBLIC
};

/* Smob data. */
struct key_data {
  uint8_t key_type;		/* Type of the key. */
  union {
    ssh_private_key ssh_private_key;
    ssh_public_key  ssh_public_key;
    ssh_key         ssh_key;
  };
};


/* Procedures */

SCM guile_ssh_is_key_p (SCM obj);
SCM guile_ssh_is_public_key_p (SCM key_smob);
SCM guile_ssh_is_private_key_p (SCM key_smob);

void init_key_type (void);

#endif	/* ifndef __KEY_TYPE_H__ */
