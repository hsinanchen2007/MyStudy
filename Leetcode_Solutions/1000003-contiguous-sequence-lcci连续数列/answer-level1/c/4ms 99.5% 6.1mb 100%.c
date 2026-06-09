### 解题思路
弱者代码 注意可能每一个数都小于0

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int i=0,max=0;
    for(i=1;i<numsSize;i++){
        if(nums[i]>nums[max]){
            max=i;
        }
    }
    if(nums[max]<0){
        return nums[max];
    }
    max=0;
    int sum=0;
    for(i=0;i<numsSize;i++){
        sum+=nums[i];
        if(sum>max){
            max=sum;
        }
        if(sum<=0){
            sum=0;
        }
    }
    return max;
}
```