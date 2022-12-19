
1、获取数据中出现次数最多的值，把该值依次填入奇数位
2、填满奇数位
3、填满偶数位
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int getMaxIndex(int *nums, int size)
{
    int i, max = 0, index = 0;
    for (i = 0; i < size; i++) {
        if (nums[i] > max) {
            index = i;
            max = nums[i];
        }
    }
    return index;
}
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize){
    int i, j, index;
    int *ans = NULL;
    int nums[10001] = {0};
    ans = calloc(barcodesSize, sizeof(int));
    if (barcodes == NULL || barcodesSize == 0) {
        *returnSize = 0;
        return ans;
    }
    if (barcodesSize == 1) {
        *returnSize = 1;
        ans[0] = barcodes[0];
        return ans;
    }    
    for (i = 0; i < barcodesSize; i++) {
        nums[barcodes[i]]++;
    }  
  
    *returnSize = barcodesSize;
    /* 出现次数最多的填奇数位置 */
    index = getMaxIndex(nums, 10000); /* size应该是10000,而不是barcodesSize */
    i = 0;
    while (nums[index] > 0 && i < barcodesSize) {
        ans[i] = index;
        i += 2;
        nums[index]--;
    }
    /* 填满奇数位置 */
    for (j = 0; j < barcodesSize && i < barcodesSize; j++) {
        if (nums[barcodes[j]] == 0) { /* nums的下表是barcodes[j]， 而不是j */
            continue;
        }
        while (nums[barcodes[j]] > 0 && i < barcodesSize) {
            ans[i] = barcodes[j];
            i += 2;
            nums[barcodes[j]]--;
        }
    }
    /* 剩余的填满偶数数位置 */
    i = 1;
    for (j = 0; j < barcodesSize && i < barcodesSize; j++) {
        if (nums[barcodes[j]] == 0) {
            continue;
        }
        while (nums[barcodes[j]] > 0 && i < barcodesSize) {
            ans[i] = barcodes[j];
            i += 2;
            nums[barcodes[j]]--;
        }     
    }
    return ans;
}