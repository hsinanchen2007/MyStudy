我们要的最终结果就是把0元素都干掉。
然后再把最后差了多长，全部用0补齐。
所以，先遍历，将非0元素逐个存在数组中，
然后，将剩下的空间，全都采0补齐就好了。
`void moveZeroes(int* nums, int numsSize){
    
    /* 先将数组里面都放上非零的数字 */
    int notZeroNum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[notZeroNum++] = nums[i];
        }
    }

    for (int i = notZeroNum; i < numsSize; i++) {
        nums[i] = 0;
    }

    return ;
}`