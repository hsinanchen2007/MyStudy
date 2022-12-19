### 解题思路
如题，另外，还尝试了一下位数组。

### 代码

执行用时 : 40 ms
内存消耗 : 11.7 MB

```c
int findRepeatNumber(int* nums, int numsSize){
    unsigned char remark[numsSize];
    memset(remark, 0, numsSize);
    for(int i=0; i<numsSize; ++i){
        if(remark[nums[i]]) return nums[i];
        remark[nums[i]] = 1;
    }
    return -1;
}
```

执行用时 : 48 ms  
内存消耗 : 11.6 MB

``` c
int findRepeatNumber(int* nums, int numsSize){
    int byteSize = numsSize/CHAR_BIT+(numsSize%CHAR_BIT!=0);
    unsigned char remark[byteSize];
    memset(remark, 0, byteSize);
    for(int i=0; i<numsSize; ++i){
        if(remark[nums[i]/CHAR_BIT] & ((unsigned char){1} << (CHAR_BIT-nums[i]%CHAR_BIT-1))) return nums[i];
        remark[nums[i]/CHAR_BIT] ^= ((unsigned char){1} << (CHAR_BIT-nums[i]%CHAR_BIT-1));
    }
    return -1;
}
```