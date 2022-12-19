### 解题思路
此处撰写解题思路

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    //sum取一个最小的数
    //b用来a保存记录，当b>0时，说明最大字段和还可以延续，如果b<0,则要重新开始，并且令b=当前的nums[i]
    double sum = -999999999999;
    int b=0;
    for(int i=0;i<numsSize;i++){
        if(b>0){
            b+=nums[i];
        }else{
            b=nums[i];
        }
        if(b>sum){
            sum = b;
        }
    }
    return sum;

}
```