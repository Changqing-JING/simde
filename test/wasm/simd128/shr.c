/* Copyright (c) 2021 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TEST_WASM_SIMD128_INSN shr
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"

static int
test_simde_wasm_i8x16_shr(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_i16x8_shr(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_i32x4_shr(SIMDE_MUNIT_TEST_ARGS) {
 return 0;
}

static int
test_simde_wasm_i64x2_shr(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_u8x16_shr(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_u16x8_shr(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_u32x4_shr(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_u64x2_shr(SIMDE_MUNIT_TEST_ARGS) {
 return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u8x16_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u16x8_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u32x4_shr)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_u64x2_shr)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
