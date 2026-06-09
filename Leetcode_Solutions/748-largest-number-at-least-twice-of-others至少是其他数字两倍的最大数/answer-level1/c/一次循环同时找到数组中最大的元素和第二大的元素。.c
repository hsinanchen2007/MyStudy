通过一次循环遍历，同时找到最大的元素和第二大的元素，如果最大的元素大于等于第二大元素的2倍，则返回最大的元素的索引，否则返回-1.

int dominantIndex(int* nums, int numsSize){
    int i = 0;
    int max = 0;
    int index = 0;
    int max2 = 0;   /* 第二大的元素 */
    int index2 = 0;
    
    if (nums == NULL || numsSize < 1) {
        return -1;
    }
    if (numsSize == 1) {
        return 0;
    }
    
    max = nums[0];
    max2 = 0;
    
    for (i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max2 = max;     /* 更新第二大的值 */
            max = nums[i];
            index = i;
            continue;       /* 不能同时将nums[i]赋值给max和max2，所以此处需要continue */
        }
        
        /* 虽然nums[i] 不大于max，但也可能是第二大的元素 */
        if (nums[i] > max2) {
            max2 = nums[i];
            index2 = i;
        }
    }
    
    if (max < max2 * 2) {
        index = -1;
    }
    
    return index;
}