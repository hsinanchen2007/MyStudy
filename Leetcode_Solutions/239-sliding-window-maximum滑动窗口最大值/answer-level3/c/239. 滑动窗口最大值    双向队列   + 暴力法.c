### 解题思路
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

进阶：

你能在线性时间复杂度内解决此题吗？

 

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7



### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 10000

typedef struct queue{
    int *datas;
    int capacity;
    int size;
    int front;
    int rear;
}Que;

Que* createQue(int maxsize){
    Que* q = malloc(sizeof(Que));
    q->datas = malloc(maxsize * sizeof(int));
    q->capacity = maxsize;
    q->size = 0;
    q->front = 0;
    q->rear = maxsize - 1;
    
    return q;
}

void enqueue (Que * queue, int val) {
    if (queue->size < queue->capacity) {
         queue->datas[queue->front] = val;
        if (queue->front == queue->capacity)
            queue->front = 0;
        else
            queue->front++;
        queue->size++;
    }
}

int dequeue(Que *queue){
    if (queue->size > 0) {
        if (queue->front == 0)
            queue->front = queue->capacity - 1;
        else
            queue->front--;
        queue->size--;
        return queue->datas[queue->front];
    }
    return -1;
}

int getHead(Que *queue){
    if (queue->size == 0)
        return -1;

    if(queue->front == 0)
        return queue->datas[queue->capacity - 1];
    else
        return queue->datas[queue->front - 1];
}

void enqueueTail(Que *queue, int val){
    if (queue->size < queue->capacity) {
        queue->datas[queue->rear] = val;
        if (queue->rear == 0)
            queue->rear = queue->capacity;
        else
            queue->rear--;
        queue->size++;  
    }
}

int dequeueTail(Que* queue){
    if (queue->size > 0) {
        if (queue->rear == queue->capacity)
            queue->rear = 0;
        else
            queue->rear++;
        queue->size--;
        return queue->datas[queue->rear];
    }
    return -1;
}

int getHeadTail(Que* queue){
    if (queue->size == 0)
        return -1;
    if (queue->rear == queue->capacity)
        return queue->datas[0];
    else
        return queue->datas[queue->rear + 1];
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *res = malloc((numsSize - k + 1) * sizeof(int));
    int i,j = 0;

#if 1
    Que* queue = createQue(numsSize);
    for (i = 0; i < numsSize; i++) {
        while (queue->size && nums[getHeadTail(queue)] < nums[i])
            dequeueTail(queue);

        enqueueTail(queue, i);

        if (getHead(queue) < i - k + 1)
            dequeue(queue);

        if (i >= k - 1)
            res[j++] = nums[getHead(queue)];        
    }
    *returnSize = j;
#else
    int max;    
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i <= numsSize - k; i++) {
        max = nums[i];
        for (j = i + 1; j < i + k; j++)
            max = (max > nums[j] ? max : nums[j]);
        res[i] = max;
    }

    *returnSize = i;
#endif
    return res;
}
```