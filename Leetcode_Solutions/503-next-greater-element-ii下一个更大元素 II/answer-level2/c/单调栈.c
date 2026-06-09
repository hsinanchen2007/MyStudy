### 解题思路
第一次写单调栈，根据自己的理解，代码不太简洁

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *stack = NULL;
    int *visit = NULL;
    int top = 0;
    int findmin = -1;
    int debug = 0;
    *returnSize = numsSize;
    if (numsSize == 0) {
        return NULL;
    }
    if (numsSize == 1) {
        nums[0] = -1;
        return nums;
    }

    stack = (int*)malloc(numsSize * sizeof(int));
    memset(stack, -1, numsSize * sizeof(int));
    visit = (int*)calloc(numsSize, sizeof(int));
    stack[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        if (top > -1 && nums[stack[top]] < nums[i]) {
            for (int j = top; j >= 0; j--) {
                if(debug) printf("top:%d val %d\n",j,stack[j]);
                if (nums[stack[j]] < nums[i] ) {
                    if(debug) printf("repleace: %d:%d by %d\n",stack[j],nums[stack[j]],nums[i]);
                    // 已经找到下一个更大值,出栈
                    visit[stack[j]] = nums[i];
                    top--;
                } else {
                    break;
                } 
            }
        } 
        top++;
        stack[top] = i;       
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[stack[top]] < nums[i]) {
            for (int j = top; j >= 0; j--) {
                if(debug) printf("top2:%d val %d\n",j,stack[j]);
                if (nums[stack[j]] < nums[i] ) {
                    if(debug) printf("repleace2: %d:%d by %d\n",stack[j],nums[stack[j]],nums[i]);
                    // 已经找到下一个更大值,出栈
                    visit[stack[j]] = nums[i];
                    top--;
                } else {
                    break;
                } 
            }
        }   
    }
    for (int i = 0; i <= top; i++) {
        visit[stack[i]] = -1;
    }
    free(stack);
    return visit;
}
```