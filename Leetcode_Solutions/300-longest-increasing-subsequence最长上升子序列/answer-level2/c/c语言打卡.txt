### 解题思路


### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int i, j, maxleni, maxlen = 1, *memorize = (int*)calloc(numsSize, sizeof(int));
    memorize[0] = 1;
    for(i = 1;i < numsSize;i ++){
        maxleni = 0;
        for(j = 0;j < i;j ++)
            if(nums[j] < nums[i] && memorize[j] > maxleni)
                maxleni = memorize[j];
        memorize[i] = maxleni + 1;
        maxlen = (memorize[i] > maxlen ? memorize[i] : maxlen);
    }
    free(memorize);
    return maxlen;
}
```