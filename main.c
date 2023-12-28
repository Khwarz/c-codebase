#include "base.h"
#include <stdio.h>

#define EVAL_PRINT(x) printf("%s = %d\n", #x, (int)(x))
#define EVAL_PRINTLL(x) printf("%s = %d\n", #x, (i32)(x))

#define EVAL_PRINTU(x) printf("%s = %u\n", #x, (u32)(x))
#define EVAL_PRINTULL(x) printf("%s = %lu\n", #x, (u64)(x))

typedef struct TestStruct {
    int a;
    int b;
    int c;
    int d;
} TestStruct;

int main()
{
    int foo[100];
    for (int i = 0; i < 100; i++) {
        foo[i] = i;
    }

    EVAL_PRINT(ARRAY_COUNT(foo));
    int bar[100];
    MEMORY_COPY_ARRAY(bar, foo);
    EVAL_PRINT(bar[50]);
    EVAL_PRINT(MEMORY_COMPARE(foo, bar, sizeof(foo)));
    MEMORY_ZERO_ARRAY(bar);
    EVAL_PRINT(bar[50]);
    EVAL_PRINT(MEMORY_COMPARE(foo, bar, sizeof(foo)));

    EVAL_PRINT(OFFSET_OF_MEMBER(TestStruct, a));
    EVAL_PRINT(OFFSET_OF_MEMBER(TestStruct, b));
    EVAL_PRINT(OFFSET_OF_MEMBER(TestStruct, c));
    EVAL_PRINT(OFFSET_OF_MEMBER(TestStruct, d));

    TestStruct t = {1, 2, 3, 4};

    EVAL_PRINT(t.a);
    MEMORY_ZERO_STRUCT(&t);
    EVAL_PRINT(t.a);

    EVAL_PRINT(MIN(1, 10));
    EVAL_PRINT(MIN(100, 10));
    EVAL_PRINT(MAX(1, 10));
    EVAL_PRINT(MAX(100, 10));
    EVAL_PRINT(CLAMP(1, 10, 100));
    EVAL_PRINT(CLAMP(1, 0, 100));
    EVAL_PRINT(CLAMP(1, 500, 100));

    EVAL_PRINT(min_i8);
    EVAL_PRINT(min_i16);
    EVAL_PRINT(min_i32);
    EVAL_PRINT(min_i64);

    EVAL_PRINT(max_i8);
    EVAL_PRINT(max_i16);
    EVAL_PRINT(max_i32);
    EVAL_PRINTLL(max_i64);

    EVAL_PRINTU(max_u8);
    EVAL_PRINTU(max_u16);
    EVAL_PRINTU(max_u32);
    EVAL_PRINTULL(max_u64);
    return 0;
}
