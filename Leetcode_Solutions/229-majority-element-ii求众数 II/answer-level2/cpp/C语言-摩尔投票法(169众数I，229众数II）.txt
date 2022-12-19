
//169 求众数I
```
int majorityElement(int* nums, int numsSize){

if(numsSize==0) return 0;
int cnt=0,major=0;

for(int i=0;i<numsSize;i++)
{
    if(cnt==0)
    {
        major=nums[i];
        cnt++;
        continue;
    }
    if(nums[i]==major)
    {
        cnt++;
        continue;
    }  
    cnt--;
}
return major;
}

```
//229 求众数II
```
int* majorityElement(int* nums, int numsSize, int* returnSize){
    
    if (numsSize==0){
        *returnSize = numsSize;
        return nums;
    }
    int cadidateA = nums[0];
    int cadidateB = nums[0];
    int countA = 0;
    int countB = 0;
    for (int i = 0; i<numsSize; i++)
    {
        if (nums[i]==cadidateA){
            countA++;
            continue;
        }
        if (nums[i]==cadidateB){
            countB++;
            continue;
        }
        if (countA==0){
            cadidateA = nums[i];
            countA++;
            continue;
        }
        if (countB==0){
            cadidateB = nums[i];
            countB++;
            continue;
        }
        countA--;
        countB--;
    }
    countA = 0;
    countB = 0;
    for (int i = 0; i<numsSize; i++){
        if (nums[i]==cadidateA){
            countA++;
        }
        else if (nums[i]==cadidateB){
            countB++;
        }
    }
    int *res = (int*)malloc(sizeof(int)*2);

    if (countA>numsSize/3 && countB>numsSize/3){
        res[0] = cadidateA;
        res[1] = cadidateB;
        *returnSize = 2;
        return res;
    }
    else if (countA>numsSize/3){
        res[1] = cadidateA;
        *returnSize = 1;
        return &res[1];
    }
    else if (countB>numsSize/3){
        res[1] = cadidateB;
        *returnSize = 1;
        return &res[1];
    }
    *returnSize = 0;
    return nums;
}
```
