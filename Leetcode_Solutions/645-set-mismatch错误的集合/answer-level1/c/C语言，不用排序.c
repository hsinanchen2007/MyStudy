虽然所给数组是无序的，但除了重复出现的数和丢失的数以外，其余数出现的次数均为1
所以我们可以用一个O(n)的数组来记录各个数字出现的次数，次数为2的即为重复出现的整数，次数为0的即为丢失的整数
```
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *count=(int *)malloc(sizeof(int)*(numsSize+1));
    memset(count,0,sizeof(int)*(numsSize+1));
    int *result=(int *)malloc(sizeof(int)*2);
    int i;
    for(i=0;i<numsSize;i++){
        count[nums[i]]++;
    }
    for(i=1;i<=numsSize;i++){
        if(count[i]==2)
            result[0]=i;
        if(count[i]==0)
            result[1]=i;
    }
    *returnSize=2;
    free(count);
    return result;
}
```
