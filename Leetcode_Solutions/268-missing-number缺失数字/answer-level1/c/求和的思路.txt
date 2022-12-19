### 解题思路
先从1加到n，再把数组里的每一个元素都减一遍，剩下的就是缺的那个

### 代码

```c
int missingNumber(int* nums, int numsSize)
{
    //用求和的方法
    int y=0;
    for(int i=1;i<=numsSize;i++) y+=i;
    for(int i=0;i<numsSize;i++) y-=nums[i];
    return y;
}
```