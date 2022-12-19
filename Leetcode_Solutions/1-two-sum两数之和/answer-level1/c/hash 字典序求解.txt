
hash 字典序求解，需要注意的是，要找到数组中最小的元素或者target-nums[index]最小值作为字典序的起始位置，不然当nums里面数字很大的时候，会造成内存申请超出限制
```
#define UNFIND (-1)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    (*returnSize) = 0;
    if ((nums == NULL) || (numsSize == 0) || (numsSize == 1)) {
        return NULL;
    }
    
    /* 为了避免申请的内存超出限制，因此可以采用相对大小的方式申请长度
       min 为数组中最小的元素或者target-nums[index]最小的元素 */
    int min = nums[0] < (target - nums[0]) ? nums[0] : target - nums[0];
    for (int index = 1; index < numsSize; index++) {
        min = (min < nums[index]) ? min : nums[index];
        min = (min < (target - nums[index])) ? min : target - nums[index];   
    }
    int max = target - min;
    int len = max - min + 1;
    //printf("min=%d", min);
    //printf("max=%d", max);
    //printf("len=%d\n", len);
    
    int *flag = (int *)malloc(sizeof(int)*len);
    for (int index = 0; index < len; index++) {
        /* 此次不能设置为0， 因为下标为0 是有意义的*/
        flag[index] = UNFIND;
    }

    int *res = (int *)malloc(sizeof(int)*2);
    res[0] = UNFIND;
    res[1] = UNFIND;
    bool match = false;
    for (int index = 0; index < numsSize; index++) {
        int current = nums[index];
        int require = target - current;
        //printf("current=%d\n", current);
        //printf("require=%d\n", require);

        //printf("flag[%d]=%d", current - min, flag[current - min]);
        if (flag[current - min] != UNFIND) {
            match = true;
            res[0] = flag[current - min];
            res[1] = index;
            (*returnSize) = 2;
            break;
        }

        flag[require - min] = index;
        //printf("set require: flag[%d]=%d", require - min, index);
    }

    if (match == false) {
        free(res);
        res == NULL;
    }

    return res;
}
```

