

借用 元仲辛的题解代码与题解：
https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/dong-tai-gui-hua-si-yao-su-by-a380922457-3/

状态

    f[i][j] 表示 s 的第 i 个字符到第 j 个字符组成的子串中，最长的回文序列长度是多少。

转移方程

    如果 s 的第 i 个字符和第 j 个字符相同的话
        f[i][j] = f[i + 1][j - 1] + 2
    如果 s 的第 i 个字符和第 j 个字符不同的话
        f[i][j] = max(f[i + 1][j], f[i][j - 1])

    然后注意遍历顺序，i 从最后一个字符开始往前遍历，j 从 i + 1 开始往后遍历，这样可以保证每个子问题都已经算好了。

初始化

    f[i][i] = 1 单个字符的最长回文序列是 1

结果

    f[0][n - 1]

展示

    为了能够直观的描述展现每一步骤的计算过程，每次计算后都打印计算过程。
    以 BABA为例，从后往前计算过程。
```c
    last value: r=3,c=3
    BABA (4, 4) = [
    [0, 0, 0, 0, ],
    [0, 0, 0, 0, ],
    [0, 0, 0, 0, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=2,c=2
    BABA (4, 4) = [
    [0, 0, 0, 0, ],
    [0, 0, 0, 0, ],
    [0, 0, 1, 0, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=2,c=3
    BABA (4, 4) = [
    [0, 0, 0, 0, ],
    [0, 0, 0, 0, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=1,c=1
    BABA (4, 4) = [
    [0, 0, 0, 0, ],
    [0, 1, 0, 0, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=1,c=2
    BABA (4, 4) = [
    [0, 0, 0, 0, ],
    [0, 1, 1, 0, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=1,c=3
    BABA (4, 4) = [
    [0, 0, 0, 0, ],
    [0, 1, 1, 3, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=0,c=0
    BABA (4, 4) = [
    [1, 0, 0, 0, ],
    [0, 1, 1, 3, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=0,c=1
    BABA (4, 4) = [
    [1, 1, 0, 0, ],
    [0, 1, 1, 3, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=0,c=2
    BABA (4, 4) = [
    [1, 1, 3, 0, ],
    [0, 1, 1, 3, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];
    last value: r=0,c=3
    BABA (4, 4) = [
    [1, 1, 3, 3, ],
    [0, 1, 1, 3, ],
    [0, 0, 1, 1, ],
    [0, 0, 0, 1, ],
    ];

    result=3
```

以上就是迭代的完整过程。注意：1，左下角初始化为0，依次迭代计算，第一行中不但可以计算值，还可以获取最长子串。
以下为完整C语言代码实现


```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MY_DEBUG
#ifdef MY_DEBUG
#define LOG(fmt, args...) fprintf(stdout, fmt, ##args)
#define BREAKER(a, b, c) breaker(a, b, c)
#else
#define LOG(fmt,...)
#define BREAKER(a, b, c)
#endif

#define TRUE        1
#define FALSE       0

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

#define _MUL_OVERFLOW(a, b) (((a) * (b)) / (b) != (a))
#define MUL_OVERFLOW(a, b)  (((b) == 0) ? FALSE : _MUL_OVERFLOW(a, b))

#define IN_RANGE(v, a, b)   ((v) >= (a) && (v) < (b))

#define ARRAY2_VALID_INDEX(arr, r, c)   \
    (IN_RANGE(r, 0, (arr)->size.row) && IN_RANGE(c, 0, (arr)->size.col))

#define ARRAY2_VALID_POS(arr, pos)    ARRAY2_VALID_INDEX(arr, (pos)->row, (pos)->col)

#define ARRAY2_VAL(arr, row, col) (arr)->p[row][col]
#define ARRAY2_VAL_P(arr, pos) (arr)->p[(pos)->row][(pos)->col]

typedef struct _POSITION {
    int col;
    int row;
} POSITION, SIZE;

typedef struct _INT_ARRAY2 {
    int **p;
    SIZE size;
} INT_ARRAY2;

void IntArray_Display(const int *array, int count, const char *prefix)
{
    printf("%s length=%d, [", (prefix == NULL) ? "" : prefix, count);
    for (int i = 0; i < count; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}

void IntArray_Fill(int *array, int count, int value)
{
    if (array == NULL) {
        LOG("IntArray_Fill: invalid args\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        array[i] = value;
    }
}

void IntArray_FillRand(int *array, int count, int minValue, int maxValue)
{
    int mod = maxValue - minValue + 1;
    if (array == NULL) {
        LOG("IntArray_FillRand: invalid args.\n");
        return;
    }
    if (mod <= 1) {
        return IntArray_Fill(array, count, minValue);
    }
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        array[i] = (rand() % mod) + minValue;
    }
}

void IntArray_Destroy(int *array)
{
    if (array == NULL) {
        LOG("IntArray_Destroy: invalid args.\n");
        return;
    }
    free(array);
}

int *IntArray_Create(int count, int defValue)
{
    int *array;
    if (count <= 0 || MUL_OVERFLOW(sizeof(int), count)) {
        LOG("IntArray_Create: invalid args: %d\n", count);
        return NULL;
    }
    array = (int *) malloc(sizeof(int) * count);
    IntArray_Fill(array, count, defValue);
    return array;
}


void IntArray2_Destroy(INT_ARRAY2 *array)
{
    if (array == NULL) {
        LOG("IntArray2_Destroy: invalid args.\n");
        return;
    }
    if (array->p != NULL) {
        for (int r = 0; r < array->size.row; r++) {
            if (array->p[r] != NULL) {
                IntArray_Destroy(array->p[r]);
            }
        }
        free(array->p);
    }
    free(array);
}

INT_ARRAY2 *IntArray2_Create(int row, int col, int defValue)
{
    INT_ARRAY2 *array = calloc(sizeof(INT_ARRAY2), 1);
    if (array == NULL || row <= 0 || col <= 0) {
        LOG("IntArray2_Create: invalid args: %d, %d\n", row, col);
        return NULL;
    }
    array->p = (int **) calloc(sizeof(int *), row);
    if (array->p == NULL) {
        LOG("IntArray2_Create: out of memory: %d, %d\n", row, col);
        free(array);
        return NULL;
    }
    array->size.row = row;
    array->size.col = col;
    for (int r = 0; r < row; r++) {
        array->p[r] = IntArray_Create(col, defValue);
        if (array->p[r] == NULL) {
            LOG("IntArray2_Create: out of memory: %d/%d, %d\n", r, row, col);
            IntArray2_Destroy(array);
            return NULL;
        }
    }
    return array;
}

void IntArray2_FillRand(INT_ARRAY2 *array, int minValue, int maxValue)
{
    if (array == NULL || array->p == NULL) {
        LOG("IntArray2_FillRand: invalid args.\n");
        return;
    }
    for (int r = 0; r < array->size.row; r++) {
        IntArray_FillRand(array->p[r], array->size.col, minValue, maxValue);
    }
}

void IntArray2_Display(const INT_ARRAY2 *array, const char *prefix)
{
    if (array == NULL || array->p == NULL) {
        LOG("IntArray2_FillRand: invalid args.\n");
    }
    printf("%s (%d, %d) = [\n", (prefix == NULL) ? "" : prefix, array->size.row, array->size.col);
    for (int r = 0; r < array->size.row; r++) {
        printf("[");
        for (int c = 0; c < array->size.col; c++) {
            printf("%d, ", ARRAY2_VAL(array, r, c));
        }
        printf("],\n");
    }
    printf("];\n");
}




void Input_PromptWaitEnter(const char *prompt)
{
    char buf[20];
    if (prompt != NULL){
        printf("%s", prompt);
    }
    fgets(buf, sizeof(buf), stdin);
}

void DebugSetArrary(INT_ARRAY2 *l, int r, int c, const char*s)
{
    printf("last value: r=%d,c=%d\n", r, c);
    IntArray2_Display(l, s);
    //Input_PromptWaitEnter("press enter:");
}

int GetLongestPalindromeSubseq(const char* s, INT_ARRAY2 *l)
{
    for (int r = l->size.row-1; r >= 0; r--) {
        l->p[r][r] = 1;
        DebugSetArrary(l, r, r, s);
        for (int c = r + 1; c < l->size.col; c++) {
            if (s[r] == s[c]) {
                l->p[r][c] = l->p[r + 1][c - 1] + 2;
            } else {
                l->p[r][c] = MAX(l->p[r + 1][c], l->p[r][c - 1]);
            }
            DebugSetArrary(l, r, c, s);
        }
    }
    return l->p[0][l->size.col - 1];
}

int longestPalindromeSubseq(char *s)
{
    INT_ARRAY2 *lenths;
    int ret, len;
    len = strlen(s);
    lenths = IntArray2_Create(len, len, 0);
    if (lenths == NULL) {
        return -1;
    }
    ret = GetLongestPalindromeSubseq(s, lenths);
    //IntArray2_Display(lenths, s);
    IntArray2_Destroy(lenths);
    return ret;
}

int longestPalindromeSubseq_tester(void)
{
    int ret = longestPalindromeSubseq("BABA");
    printf("\nresult=%d\n", ret);
    return 0;
}
```

