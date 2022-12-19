```
int dominantIndex(int* nums, int numsSize){
    int max = 0;    /* 最大值*/
    int max2 = 0;   /* 第二大值*/
    int i = 0;      /* 循环标志位*/
    int index = 0;
    for (; i < numsSize; i++) {
        if (max < nums[i]) {            /* 如果最大值小于当前值，最大值为但当前值*/
            max2 = max;
            max = nums[i];
            index = i;
        } else if (max2 < nums[i]) {    /* 当前数也可能是第二大的数*/
            max2 = nums[i];
        }
    }
    if (max >= max2 * 2) {
        return index;
    }
    return -1;
}
```




