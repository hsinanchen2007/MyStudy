### 解题思路
参考网友的解题思路，很实用。假设两个数不同就同时“剔除”一次，剩下的肯定就是结果了。不过“剔除”指的是计数减一。

### 代码

```c
int majorityElement(int* nums, int numsSize){
    int value,count=0;
    value=nums[0];
    for(int i=0;i<numsSize;i++)
    {
        if(value==nums[i])
            count++;
        else
            count--;
        if(count<=0)
            value=nums[i+1];
    }
    return value;
}
```