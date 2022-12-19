基础方案：单调递减栈
1、栈底元素是最大值；
2、优化点：新增bottom指针，如果栈底元素已经在滑窗移动时，已处于窗口外，则bottom++丢弃栈底元素
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(nums == NULL || numsSize < 1 || k < 1 || k > numsSize) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = (numsSize - (k - 1));
    int *ret = (int *)malloc((numsSize - (k - 1)) * sizeof(int));
    memcpy(ret, nums, (numsSize - (k - 1)) * sizeof(int));
    if (k == 1) { // 窗口长度为1时，结果为原数组值
        return ret;
    }

    int *stack = (int *)malloc(numsSize * sizeof(int));
    memset(stack, 0, numsSize * sizeof(int));
    int top = -1;
    int bottom = 0;
    /* 初始化滑窗内 k - 1个元素,形成单调递减栈 */
    for(int i = 0; i < k - 1; i++) {
        while(top >= bottom && nums[i] > nums[stack[top]]) {
            top--;
        }
        stack[++top] = i;
    }
    /* 向栈内添加元素 */
    for(int i = k - 1; i < numsSize; i++) {        
        while(top >= bottom && nums[i] > nums[stack[top]]) { // 单调递减栈
            top--;
        }        
        stack[++top] = i; // 新元素进栈
        if (stack[bottom] == i - k) {  // 如果栈底是窗口最左边的元素，则丢弃
            bottom++;
        }
        ret[i - (k - 1)] = nums[stack[bottom]]; // 取栈底元素作为最大值        
    }
    free(stack);    
    return ret;
}