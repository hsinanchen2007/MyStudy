队列法
C语言的痛苦在于队列的pop和push等操作需要自行创建
解题思路：
1、构建队列的Push, Pop等方法
2、主函数中对特例输入操作：
    1] 输入的数组为NULL，直接返回NULL
    2] k == 1 时，啥也不说直接返回nums即可
    3] 当numsSize <= k 时，直接找出数组内的最大值即可
3、主函数中对于非特例，即普适条件时
    1] 创建一个队列queue，数据长度为k+1
    2] i < k时在nums[0] : nums[k] 之间找出第一个maxValue
    3] i < k时将nums[0] : nums[k]每个值push到queue中
    4] 对于i >= k时最大值求法：
        1> num[i] > maxValue时，直接将队列头pop出去然后把nums[i] push进去
        2> num[i] <= maxValue时，取出队列头值tmp，然后把队列头pop出去然后把nums[i] push进去
        3> 如果tmp == maxValue时，需要遍历求出queue中最大值重新给maxValue
4、每一步移动i均把最大值给data指针，最后返回data

下面是C代码实现

```
#define NULL ((void *)0)
#define false 0
#define true 1
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Queue {
    int *data;
    int head;
    int tail;
    int size;
};

struct Queue *queueCreate(void)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (!q) {
        return NULL;
    }
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

int queueEmpty(struct Queue *q)
{
    if (q->head == q->tail) {
        return false;
    }
    return true;
}

int queueFull(struct Queue *q)
{
    if (q->head == (q->tail + 1) % q->size) {
        return false;
    }
    return true;
}

void queuePush(struct Queue *q, int e)
{
    if (!queueFull(q)) {
        return;
    }
    q->tail = (q->tail + 1) % q->size;
    q->data[q->tail] = e;
}

int queuePop(struct Queue *q)
{
    if (!queueEmpty(q)) {
        return 0;
    }
    q->head = (q->head + 1) % q->size;
    return q->data[q->head];
}

int queueMax(struct Queue *q)
{
    int max = q->data[(q->head + 1) % q->size];
    for (int i = (q->head + 1) % q->size; i != (q->tail + 1) % q->size; i = (i + 1) % q->size) {
        max = MAX(max, q->data[i]);
    }
    return max;
}

void queueFree(struct Queue *q)
{
    if (q) {
        if (q->data) {
            free(q->data);
            q->data = NULL;
        }
        free(q);
        q = NULL;
    }
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }
    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }
    int maxValue = nums[0];
    if (numsSize <= k) {
        *returnSize = 1;
        int *data = (int *)malloc(sizeof(int) * (*returnSize));
        for (int i = 1; i < numsSize; i++) {
            maxValue = MAX(maxValue, nums[i]);
        }
        data[0] = maxValue;
        return data;
    }
    *returnSize = numsSize - k + 1;
    struct Queue *q = queueCreate();
    q->data = (int *)malloc(sizeof(int) * (k + 1));
    q->size = k + 1;
    int *data = (int *)malloc(sizeof(int) * (*returnSize));
    int i;
    int idx = 0;
    int tmp;
    for (i = 0; i < k; i++) {
        maxValue = MAX(maxValue, nums[i]);
        queuePush(q, nums[i]);
    }
    data[idx++] = maxValue;
    for (; i < numsSize; i++) {
        if (nums[i] >= maxValue) {
            queuePop(q);
            maxValue = nums[i];
            queuePush(q, maxValue);
        } else {
            tmp = queuePop(q);
            queuePush(q, nums[i]);
            if (tmp == maxValue) {
                maxValue = queueMax(q);
            }
        }
        data[idx++] = maxValue;
    }
    queueFree(q);
    return data;
}
```

