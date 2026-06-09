### 解题思路
从头遍历整个数据并累加数组求和，如果发现和比最大值要大，那么直接赋值给最大值。
如果发现累加值为负数，则丢弃当前累加组，从下一个项开始重新累加求和。
对于全部都为复数的情况，选出的应该是一个最大的负数。

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int i,sum=0,max;
    max=nums[0];
    for(i=0;i<numsSize;i++){
        sum+=nums[i];
        if(sum>max) max=sum;
        if(sum<0) sum=0;
    }
    return max;
}
```