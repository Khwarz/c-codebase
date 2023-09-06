#include "base.h"
#include <stdio.h>

#define EVAL_PRINT(x) printf("%s = %d\n", #x, (int)(x))

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
    return 0;
}
