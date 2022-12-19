### 解题思路
因为不同的值相互消耗，最后剩下的maj便是出现次数最多的数
### 代码

```c
int majorityElement(int* nums, int numsSize){
    int c=1;
    int maj=nums[0];
    for(int i=1;i<numsSize;++i){
        if(maj==nums[i])
            ++c;
        else
            --c;
        if(c==0)
            maj=nums[i+1];
    }
    return maj;
}
```