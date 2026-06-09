采用hash映射
```C []
int arrayPairSum(int* nums, int numsSize){
    int *hash = (int*)malloc(20001 * sizeof(int));
    memset(hash, 0, 20001 * sizeof(int));
    int i, sum = 0, flag = 0;
    for (i = 0; i < numsSize; ++i) hash[nums[i] + 10000]++;
    for (i = 0; i < 20001; ++i){
        if (hash[i]) {
            sum += (hash[i] + 1 - flag) / 2 * (i - 10000);
            flag = (hash[i] - flag) & 1;
        }
    }
    free(hash);
    return sum;
}
```
