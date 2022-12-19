```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    int i,head,rear;
    int *queue,*rslt;
    
    *returnSize = 0;

    if (nums == NULL || numsSize == 0){
        return NULL;
    }

    head = rear = 0;
    rslt = (int*)malloc(numsSize*sizeof(int));
    queue = (int*)malloc(numsSize*sizeof(int));

    for (i=0;i<numsSize;i++) {

        // 保持最大值在队首，单调递减队列
        while (head!=rear && nums[queue[rear-1]] < nums[i]) {
            rear--;    
        }
        queue[rear++] = i;        

        // 窗滑满
        if ( i>=k-1 ){
            // 最大值在队首
            rslt[(*returnSize)++] = nums[queue[head]];

            // 队首出窗，则出队
            if (head!=rear && queue[head] <= i-k+1) {
                head++;    
            }           
        }
    }

    free(queue);

    return rslt;
}
```
