### 解题思路
关键在于求因子的速度，开始用j<nums[i]作为判定，但一般因子不会超过它的一半，于是用j<=nums[i]/2作为判定，通过了时间限制。
当然这么做也有一定侥幸心理，因为如果是一个超级大的素数的话，还是会用很长时间的。
### 代码

```c
int sumFourDivisors(int* nums, int numsSize){
    int sum=0,count,j,tempsum;
    for(int i=0;i<numsSize;i++){
        count = 2;
        j=2;
        tempsum=nums[i]+1;
        while(j<=nums[i]/2){
            if(nums[i]%j==0){
                tempsum+=j;
                if(++count>4)break;
            }
            j++;
        }
        if(count==4)sum+=tempsum;
    }
    return sum;
}
```