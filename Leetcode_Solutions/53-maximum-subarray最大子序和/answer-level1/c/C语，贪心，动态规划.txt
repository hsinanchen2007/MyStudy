### 解题思路

### 代码

```c

//动态规划
int maxSubArray(int* nums, int numsSize){
    int *dp = (int *)malloc(sizeof(int)*numsSize);
    int i;
    int sum=0 , max= -2147483648;
    if(!numsSize)return max;
    if(numsSize==1)return *nums;
    for(i =0 ; i<numsSize ; i++){
        if(sum < 0)sum =0 ;
        sum += *(nums+i);
        *(dp+i) = *(dp+i) > sum ? *(dp+i):sum;
        max = *(dp+i) > max ? *(dp+i) :max;
    }
    return max;
}
//贪心算法

int maxSubArray(int* nums, int numsSize){
    int *dp = (int *)malloc(sizeof(int)*numsSize);
    int i;
    int sum=0,max=-2147483648;
    if(!numsSize)return max;
    for(i =0 ; i<numsSize ; i++){
        if(sum < 0)sum=0;
        sum += *(nums+i);
        if(sum > max )max = sum;
    }
    return max;
}
```