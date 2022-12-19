### 解题思路
第一次在leetcode上做题，没想到还有内存限制和运算时间限制，这对于加深编程的理解非常有好处。
使用一个临时字符数组(char内存消耗最少，要不就得用bitmap)，使用nums数组中的数据作为tmp的下标进行初始化，遇到第二次
出现数组中的数据的时候就可以返回了。

### 代码

```c
int findRepeatNumber(int* nums, int numsSize){
    char tmp[numsSize];
    int i;
    memset(tmp, 0, numsSize);
    for(i=0;i<numsSize;i++){
        if(tmp[nums[i]])
            return nums[i];
        tmp[nums[i]] = 1;
    }
    return -1;
}
```