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

#define SIMDE_TEST_WASM_SIMD128_INSN shl
#include "../../../simde/wasm/simd128.h"
#include "test-simd128.h"
#include <string.h>

static int
test_simde_wasm_i8x16_shl(SIMDE_MUNIT_TEST_ARGS) {
 return 0;
}

static int
test_simde_wasm_i16x8_shl(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static int
test_simde_wasm_i32x4_shl(SIMDE_MUNIT_TEST_ARGS) {
  return 0;
}

static void printV128(const char* prefix, simde_v128_t* x){
  uint8_t buff[16];
  memcpy(buff, x, 16);
  printf("value of %s is:\n", prefix);
  for(int i = 0;i<16;i++){
    int num = buff[i];
    printf("%x, ", num);
  }

  printf("\n");
}

static void compareV128(simde_v128_t* v1, simde_v128_t* v2){
   uint8_t buff1[16];
   uint8_t buff2[16];
   memcpy(buff1, v1, 16);
   memcpy(buff2, v2, 16);

   int success = 1;

  for(int i = 0;i<16;i++){
    if(buff1[i]!=buff2[i]){
      success = 0;
      break;
    }
  }

  if(success){
    printf("compareV128 success\n");
  }else{
    printf("compareV128 failed\n");

    printV128("v1",  v1);
    printV128("v2",  v2);
  }


}

static int
test_simde_wasm_i64x2_shl(SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    SIMDE_TEST_STRUCT_MODIFIERS struct {
      int64_t a[sizeof(simde_v128_t) / sizeof(int64_t)];
      uint32_t count;
      int64_t r[sizeof(simde_v128_t) / sizeof(int64_t)];
    } test_vec[] = {
      { { INT64_C( 6198146708162311554), INT64_C( 6606809925307964581) },
        UINT32_C(          64),
        { INT64_C( 6198146708162311554), INT64_C( 6606809925307964581) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_v128_t a = simde_wasm_v128_load(test_vec[i].a);
      simde_v128_t r = simde_wasm_i64x2_shl(a, 0);

      printf("compare r and a\n");
      compareV128(&r, &a);

      simde_test_wasm_i64x2_assert_equal(r, a);

      printf("shl 0 assert r a success\n");

      printf("compare r and test_vec.r\n");
      simde_v128_t r0 = simde_wasm_v128_load(test_vec[i].r);

      compareV128(&r, &r0);


      simde_test_wasm_i64x2_assert_equal(r, simde_wasm_v128_load(test_vec[i].r));
      printf("shl 0 assert r r0 success\n");
       simde_v128_t r2 = simde_wasm_i64x2_shl(a, 64);

      printf("compare r and r2\n");
       compareV128(&r, &r2);

       simde_test_wasm_i64x2_assert_equal(r, r2);
       printf("shl 0 assert r r2 success\n");
    }
    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_v128_t a = simde_test_wasm_i64x2_random();
      uint32_t count = simde_test_codegen_random_u32() & 63;
      simde_v128_t r;

      r = simde_wasm_i64x2_shl(a, count);

      simde_test_wasm_i64x2_write(3, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_u32(3, count, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_wasm_i64x2_write(3, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i8x16_shl)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i16x8_shl)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i32x4_shl)
  SIMDE_TEST_FUNC_LIST_ENTRY(wasm_i64x2_shl)
SIMDE_TEST_FUNC_LIST_END

#include "test-simd128-footer.h"
