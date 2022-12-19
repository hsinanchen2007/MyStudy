```
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int count = 0;
    //1.获得返回数组的长度
    for (int i = 0; i < numsSize; i += 2)
    {
        count += nums[i];
    }
    *returnSize = count;

    int * res = (int *)malloc(sizeof(int) * count);

    //2.填充返回数组
    count = 0;
    for (int i = 0; i * 2 < numsSize; i++)
    {
        for (int j = 0; j < nums[2 * i]; j++)
        {
            res[count++] = nums[2 * i + 1];
        }
    }

    return res;
}
```

