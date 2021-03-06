// Copyright 2014 Technical Machine, Inc. See the COPYRIGHT
// file at the top-level directory of this distribution.
//
// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

#include <fortuna.h>
#include <internal.h>
#include <stdint.h>

// int tm_entropy_seed (void);
// Reseeds entropy with a default (system-defined) mechanism.

// Builtin mechanism uses /dev/null, only on PC.
#ifdef COLONY_PC
int tm_entropy_seed (void)
{
	system_reseed();

	// Doesn't fail, by default.
	return 0;
}
#endif


// int tm_entropy_add (const uint8_t* buf, size_t buf_size);
// Adds custom entropy to system.

int tm_entropy_add (const uint8_t* buf, size_t buf_size)
{
	fortuna_add_entropy(buf, buf_size);

	// Doesn't fail, by default.
	return 0;
}


// int tm_random_bytes (uint8_t* buf, size_t buf_size, size_t* read);
// Retrieve random bytes into a buffer.

int tm_random_bytes (uint8_t* buf, size_t buf_size, size_t* read)
{
	fortuna_get_bytes(buf_size, buf);
	*read = buf_size;

	// Doesn't fail, by default.
	return 0;
}