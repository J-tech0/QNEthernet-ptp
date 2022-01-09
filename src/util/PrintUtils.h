// SPDX-FileCopyrightText: (c) 2022 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: MIT

// PrintUtils.h declares Print utility functions.
// This file is part of the QNEthernet library.

// C++ includes
#include <cstddef>
#include <cstdint>
#include <functional>

#include <Print.h>

namespace qindesign {
namespace network {
namespace util {

// Attempts to completely write the specified bytes. This loops until everything
// is written or `breakf` returns true. If `breakf` is NULL then it is assumed
// to never return true.
//
// In other words, the `breakf` function is the stopping condition.
//
// This returns the number of bytes actually written. If `breakf` never returns
// true then this will have written all the bytes upon return.
size_t writeFully(Print &p, const uint8_t *buf, size_t size,
                  std::function<bool()> breakf = nullptr);

// Writes "magic packet" bytes to the given Print object. This passes `breakf`
// to `writeFully()`.
//
// This utilizes `writeFully()` under the covers, meaning this loops until
// all bytes are written or `breakf` returns true.
size_t writeMagic(Print &p, uint8_t mac[6],
                  std::function<bool()> breakf = nullptr);

}  // namespace util
}  // namespace network
}  // namespace qindesign
