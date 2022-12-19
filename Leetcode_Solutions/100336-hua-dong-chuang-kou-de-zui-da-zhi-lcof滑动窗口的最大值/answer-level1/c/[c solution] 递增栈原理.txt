### 解题思路

时间复杂度：近似O(n)
空间复杂度：O(n)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(numsSize <= 0){
        *returnSize = numsSize;
        return nums;
    }

    *returnSize = numsSize - k + 1;
    int* stack = (int*)malloc(sizeof(int)*numsSize);  // 栈里存储nums数组的下标 ， 对应的下标值是递增关系
    int* res = (int*)malloc(sizeof(int)*(*returnSize));
    memset(stack,0,sizeof(int)*numsSize);
    memset(res,0,sizeof(int)*(*returnSize));

    int stackBar = 0 , stackTop = -1 , idx = 0;  
    for(int i = 0 ; i < numsSize ; i++){
        while(i - k + 1 > stack[stackBar] && stackTop >= stackBar){
            stackBar++;
        }
        if(stackTop != -1 && nums[stack[stackTop]] >= nums[i]){
            stack[++stackTop] = i;
        }else{
            while(stackTop != -1 && stackTop >= stackBar && nums[stack[stackTop]] < nums[i]){
                stackTop--;
            }
            stack[++stackTop] = i;
        }
        if(i - k + 1 == idx){
            res[idx++] = nums[stack[stackBar]];
        }
    }

    return res;
}
```