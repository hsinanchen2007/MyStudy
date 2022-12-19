int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int i;
    bool pos[1 + numsSize];
    int sum = (1 + numsSize) * numsSize /2;
    int sum1 = 0;
    int *outData = (int *)calloc(1, sizeof(int)*3);
    memset(pos, false, sizeof(pos));

    for(i=0; i<numsSize; i++){
        if (pos[nums[i]] == true){
            outData[0] = nums[i];
            continue;
        }
        pos[nums[i]] = true;
        sum1 += nums[i];
    }
    outData[1] = sum - sum1;
    *returnSize = 2;

    return outData;
}