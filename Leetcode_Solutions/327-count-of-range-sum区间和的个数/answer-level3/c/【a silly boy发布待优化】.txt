```
void SubFuncDFS(int* nums, int numsSize, int lIndex, int rIndex, int lower, int upper, long long int sum, int *outputNum)
{
    int i;
    if (rIndex > numsSize - 1) {
        return;
    }
    sum = sum + nums[rIndex];
    //printf("lIndex: %d, rIndex: %d, lower: %d, upper: %d, sum: %d, outputNum: %d\n", lIndex, rIndex, lower, upper, sum, *outputNum);
    if ((sum >= lower) && (sum <= upper)) {
        (*outputNum)++;
    }

    i = rIndex + 1;
    SubFuncDFS(nums, numsSize, lIndex, i, lower, upper, sum, outputNum);
}

int countRangeSum(int* nums, int numsSize, int lower, int upper){
    if ((nums == NULL) || (numsSize == 0)) {
        return 0;
    }
    int outputNum = 0;

    int i;
    long long int sum;

    for (i = 0; i < numsSize; i++) {
        sum = 0;
        SubFuncDFS(nums, numsSize, i, i, lower, upper, sum, &outputNum);
    }
    //printf("outputNum: %u", outputNum);
    //二维怎么变一维

    return outputNum;
}
```
