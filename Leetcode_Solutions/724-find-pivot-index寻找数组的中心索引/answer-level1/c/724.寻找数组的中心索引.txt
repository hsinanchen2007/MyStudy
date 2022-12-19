### 解题思路
数组类问题首要考虑索引值问题，本题中，容易想到，优先考虑数组为空和只有一个元素的情况，求中心索引，两侧元素累加相等，则可以考虑先累加求和一次，再在第二次累加循环中考虑中心元素问题，两侧元素相等则两倍的单侧元素累加和=sum-中心元素。
时间复杂度为O(n);
### 代码

```c
int pivotIndex(int* nums, int numsSize){
    int i,j;
    int s=0,t=0;
    if(NULL == nums||numsSize < 2){
        return -1;
    }
    for(i=0;i<numsSize;i++)
    {
        s+=nums[i];
    }
    for(i=0;i<numsSize;i++)
    {
        
        if(t*2+nums[i]==s)
        {
            return i;
        }
        t+=nums[i];
    }
    return -1;
}
```