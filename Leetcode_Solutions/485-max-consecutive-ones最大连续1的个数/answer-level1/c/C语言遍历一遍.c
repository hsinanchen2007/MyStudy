### 解题思路
count记录1的个数，maxCount记录最大的序列和。遍历一次遇到1就count++，遇到0就让maxCount保存max(count，maxCount)值，让count重新等于0

### 代码

```c
int max(int a,int b){
    return a>b? a:b;
}

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int j,i,count = 0,maxCount = 0;
    for(i=0;i<numsSize;i++){
        if(nums[i]!=0)
           count++;
        else{
           maxCount = max(count,maxCount);
           count = 0;
        }
    }
    return maxCount = max(count,maxCount);
}

```