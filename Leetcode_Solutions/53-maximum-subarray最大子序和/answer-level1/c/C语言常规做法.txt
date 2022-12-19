鉴于此题是很多数据结构和算法分析课程第一课提到的例子，不再赘述。
该算法的时间复杂度为O(N)，分治法待更。
```c
int maxSubArray(int* nums, int numsSize){
    int i=0,maxSum=-2147483647,currentSum=0;
    while(i<numsSize){
        currentSum+=nums[i++];
        if(currentSum>maxSum) maxSum=currentSum;
        if(currentSum<0) currentSum=0;
    }
    return maxSum;
}
```