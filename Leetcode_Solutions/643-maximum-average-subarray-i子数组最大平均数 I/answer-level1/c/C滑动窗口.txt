### 解题思路
滑动窗口

### 代码

```c
double findMaxAverage(int* nums, int numsSize, int k){
    if(numsSize<k) return 0;
    double sum=0,maxsum;
    double ave=0;
    int i,j;
    for(i=0;i<k;i++){
        sum+=nums[i];
    }
    maxsum=sum;
    for(j=k;j<numsSize;j++){
        sum += nums[j]-nums[j-k];
        maxsum=fmax(sum,maxsum);
    }
    ave=maxsum/k;
    return ave;    

}
```