int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int count[10001] = {0};
    int *new = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++){
            count[nums[i]]++;
    }
    for(int i = 1; i <= numsSize; i++){
        if(count[i] == 2)
             new[0] = i;
        if(count[i] == 0)
            new[1] = i;
    }
    
    return new;
}