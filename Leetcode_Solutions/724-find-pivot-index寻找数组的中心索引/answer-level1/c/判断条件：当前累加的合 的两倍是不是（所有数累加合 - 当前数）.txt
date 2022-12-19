/**************************************************
*判断条件：当前累加的合 的两倍是不是（所有数累加合 - 当前数）
***************************************************/
```
int pivotIndex(int* nums, int numsSize) {
    if(NULL == nums || numsSize < 2){
        return -1;
    }
    int sum = 0,temp = 0,i = 0;
    /* 遍历累加总和 */
    for(i = 0;i < numsSize;i++)
        sum += nums[i];
    /* 处理判断 */
    for(i = 0;i < numsSize;i++){
        if(temp * 2 + nums[i] == sum)
            return i;
        temp += nums[i];
    }
    return -1;
}
```
