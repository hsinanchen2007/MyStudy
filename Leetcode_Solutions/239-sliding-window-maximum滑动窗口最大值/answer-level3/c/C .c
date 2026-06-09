### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int *result = (int *)calloc(numsSize - k + 1, sizeof(int)); /* malloc 数组保存返回值 */   
    int *queue = (int *)calloc(numsSize, sizeof(int));
    int front = 0, rear = 0;  /* 模拟双端队列 */
       
    int i = 0;
    while (i < numsSize) {
        /* 队尾元素 < 未入队元素 ， 弹出队尾元素 */
        while (front != rear && nums[queue[rear - 1]] < nums[i]) {
            --rear;
        }

        /* 新元素下标入队 */
        queue[rear++] = i;        
        /* 开始滑动窗口 */
        if (i >= k - 1){
            /* 当前窗口最大值加入结果 */
            result[i - k + 1] = nums[queue[front]];
            /* 队头元素出窗(出队) */
            if (front != rear && queue[front] <= i - k + 1) {
                ++front;
            }
        }
        ++i;
    }
    free(queue);
    /* 返回数组大小为 numsSize - k + 1 */
    *returnSize = numsSize - k + 1;
    return result;
}
```