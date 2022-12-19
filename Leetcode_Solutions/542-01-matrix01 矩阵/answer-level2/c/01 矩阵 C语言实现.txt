C总是很难， 因为少很多标准库。

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MY_DEBUG
#ifdef MY_DEBUG
#define LOG(fmt, args...) fprintf(stdout, fmt, ##args)
#define BREAKER(a, b, c) breaker(a, b, c)
#define LOG_INT_ARRAY(arr, len, pre) IntArray_Display(arr, len, pre)
#else
#define LOG(fmt,...)
#define BREAKER(a, b, c)
#define LOG_INT_ARRAY(pre, arr, len)
#endif
#define TRUE        1
#define FALSE       0
#define INVALID     (-1)

#define SWAP(a, b, temp)    do{(temp) = (a); (a) = (b); (b) = (temp);}while(0)
#define ARRAY_COUNT(arr)    (sizeof(arr) / sizeof((arr)[0]))
#define IN_RANGE(v, a, b)   ((v) >= (a) && (v) < (b))

#define _MUL_OVERFLOW(a, b) (((a) * (b)) / (b) != (a))
#define MUL_OVERFLOW(a, b)  (((b) == 0) ? FALSE : _MUL_OVERFLOW(a, b))

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
    if (array == NULL || array->p == NULL) {
        LOG("IntArray2_Destroy: invalid args.\n");
        return;
    }
    for (int r = 0; r < array->size.row; r++) {
        if (array->p[r] != NULL) {
            free(array->p[r]);
        }
    }
    array->size.col = 0;
    array->size.row = 0;
    free(array->p);
}

int IntArray2_Create(INT_ARRAY2 *array, int row, int col, int defValue)
{
    if (array == NULL || row <= 0 || col <= 0) {
        LOG("IntArray2_Create: invalid args: %d, %d\n", row, col);
        return -1;
    }
    array->p = (int **) calloc(sizeof(int *), row);
    if (array->p == NULL) {
        LOG("IntArray2_Create: out of memory: %d, %d\n", row, col);
        return -1;
    }
    array->size.row = row;
    array->size.col = col;
    for (int r = 0; r < row; r++) {
        array->p[r] = IntArray_Create(col, defValue);
        if (array->p[r] == NULL) {
            LOG("IntArray2_Create: out of memory: %d/%d, %d\n", r, row, col);
            return -1;
        }
    }
    return 0;
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

typedef struct _POS_QUEUE {
    int front;
    int tail;
    int count;
    POSITION *p;
}POS_QUEUE;

void Queue_Destroy(POS_QUEUE *queue) {
    if (queue->p != NULL)
        free(queue->p);
    memset(queue, 0, sizeof(POS_QUEUE));
}

int Queue_Create(POS_QUEUE *queue, int count) {
    queue->p  = (POSITION *)calloc(sizeof(POSITION), count);
    if (queue->p == NULL) {
        return -1;
    }
    queue->count = count;
    queue->front = queue->tail = 0;
    return 0;
}

int Queue_IsEmpty(POS_QUEUE *queue)
{
    if (queue->tail - queue->front == 0)
        return 1;
    return 0;
}

int Queue_Push(POS_QUEUE *queue, const POSITION *pos)
{
    if (queue->tail >= queue->count) {
        LOG("Queue is Full\n");
        return -1;
    }
    queue->p[queue->tail++] = *pos;
    return 0;
}

int Queue_Pop(POS_QUEUE *queue, POSITION *pos)
{
    if (Queue_IsEmpty(queue)){
        LOG("Queue_Pop: Queue is empty\n");
        return -1;
    }
    *pos = queue->p[queue->front++];
    return 0;
}

#define MAX_DIR 4
int Array2_NextPosition(const POSITION *cur, POSITION *next, int direction)
{
    static POSITION pos[MAX_DIR] = {
            {0,1}, {1,0}, {0, -1}, {-1, 0}
    };
    direction %= MAX_DIR;
    next->row = cur->row + pos[direction].row;
    next->col = cur->col + pos[direction].col;
    return 0;
}

int GetMinStep(const INT_ARRAY2 *step, const POSITION *pos)
{
    int dir, minStep, nextStep;
    POSITION next;
    minStep = INVALID;
    for (dir =0; dir < MAX_DIR; dir++) {
        Array2_NextPosition(pos, &next, dir);
        if (!ARRAY2_VALID_POS(step,&next)) {
            continue;
        }
        nextStep = ARRAY2_VAL_P(step,&next);
        if (nextStep == INVALID) {
            continue;
        }
        if (minStep == INVALID || nextStep < minStep) {
            minStep = nextStep;
        }
    }
    return minStep + 1;
}

int UpdateZeroPosition(int **matrix, INT_ARRAY2 *step, INT_ARRAY2 *visited, POS_QUEUE *queue) {
    int ret = -1;
    POSITION pos;
    for (pos.row = 0; pos.row < step->size.row; pos.row++) {
        for (pos.col = 0; pos.col < step->size.col; pos.col++) {
            if (matrix[pos.row][pos.col] == 0) {
                Queue_Push(queue, &pos);
                ARRAY2_VAL_P(step,&pos) = 0;
                ARRAY2_VAL_P(visited,&pos) = 1;
                ret++;
            }
        }
    }
    return ret;
}

// 核心算法
int BfsFill(INT_ARRAY2 *step, int **matrix, int row, int col)
{
    int ret, vis;
    POS_QUEUE queueData, *queue = &queueData;
    POSITION cur, next;
    INT_ARRAY2 visitedData, *visited = &visitedData;
// BFS辅助数组，用于判断是否遍历过
    ret = IntArray2_Create(visited, row,  col, 0);
    if (ret < 0) {
        LOG("visited array create failed\n");
        return -1;
    }
// BFS辅助队列，
    ret = Queue_Create(queue, row*col + 1);
    if (ret < 0) {
        LOG("Queue_Create failed\n");
        IntArray2_Destroy(visited);
        return -1;
    }
// 所有0值都入队，类似池塘下雨，同时多个雨滴落点
    ret = UpdateZeroPosition(matrix, step, visited, queue);
    if (ret < 0) {
        LOG("matrix has no item '0' \n");
        IntArray2_Destroy(visited);
        Queue_Destroy(queue);
        return -1;
    }
// 循环出队，修改周围的步数。类似雨滴波纹周边扩散
    while(!Queue_IsEmpty(queue)) {
        Queue_Pop(queue, &cur);
// 遍历四周的格子，合法且没有遍历过的周边就入队吧。
        for (int dir =0; dir < MAX_DIR; dir++) {
            Array2_NextPosition(&cur, &next, dir);
            if (!ARRAY2_VALID_POS(step,&next)) {
                continue;
            }
            if (ARRAY2_VAL_P(visited,&next)) {
                continue;
            }
// 步数为当前步数 +1
            Queue_Push(queue, &next);
            ARRAY2_VAL_P(step,&next) = ARRAY2_VAL_P(step,&cur) + 1;
            ARRAY2_VAL_P(visited,&next) = 1;
        }
    }
    Queue_Destroy(queue);
    IntArray2_Destroy(visited);
    return 0;
}

// LT函数主入口
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int ret;
    INT_ARRAY2 step;
// 创建返回数组
    ret = IntArray2_Create(&step, matrixSize,  *matrixColSize, INVALID);
    if (ret < 0) {
        return NULL;
    }
// BFS算法获取各个步数
    ret = BfsFill(&step, matrix, matrixSize,  *matrixColSize);
    if (ret < 0) {
        IntArray2_Destroy(&step);
        return NULL;
    }
// LT要求返回值总是很神奇，大概知道是咋回事儿，问题是太不方便。
    int* cols = (int *)calloc(sizeof(int), matrixSize);
    for (int i = 0; i< matrixSize; i++){
        cols[i] = *matrixColSize;
    }
    *returnSize = matrixSize;
    *returnColumnSizes = cols;
    return step.p;
}

// 测试代码不用看
int updateMatrix_tester(void)
{
    int row, col, ret, *returnColumnSizes;
    INT_ARRAY2 array, step;
    row = col = 3;
    ret = IntArray2_Create(&array, row, col, 0);
    if (ret < 0) {
        return -1;
    }
    IntArray2_FillRand(&array, 0, 1);
    array.p[row-1][col-1] = 0;
    returnColumnSizes = NULL;
    IntArray2_Display(&array,"Input");
    step.size = array.size;
    step.p = updateMatrix(array.p, array.size.row, &array.size.col, &row, &returnColumnSizes);
    IntArray2_Display(&step,"Result");
    IntArray2_Destroy(&array);
    IntArray2_Destroy(&step);
    return 0;
}

```
