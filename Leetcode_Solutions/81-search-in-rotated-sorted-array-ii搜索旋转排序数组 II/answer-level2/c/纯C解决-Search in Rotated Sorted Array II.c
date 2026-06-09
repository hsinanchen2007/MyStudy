### 解题思路
这道题的难度是可以的，个人感觉给个HARD都不为过，一共做了四五天才算是捋清楚了。

这里的基础条件就是我们对于一个不递减的数组进行了右移K个单位，这样也是旋转数组的本质，所以，其实它的原数组是一个不递减的，那么我们毫无疑问，如果原数组中查找一个值是否存在，我们大可以直接直接用二分查找。
这边可以参考一下这位大佬的题解[Search in Rotated Sorted Array](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-35/)
灵感来源于他的解法一
所以问题所在：
```
数组发生了右移，且右移的单位未知
```
所以我们这里可以考虑一下，我们能否知道发生偏移的长度，然后我们的二分查找就可以从逻辑上回归正常了
这边举个例子来帮助理解一下


```
                               右移3个单位
                0,0,1,2,2,5,6   --------->     2,5,6,0,0,1,2     target=0
二分查找：      mid=3  num=2                    mid=3+3=6 num=2

               mid=1  num=0                    mid=1+3   num=0
```
所以我们只需要求出它的右移的步长，就可以从逻辑上把这个数组恢复正常
寻找步长的方法其实就查找一个元素在右移之后的位置和原位置的对比即可

方便起见，我这里查找的是最小值的地址
为了确保时间的O(logn)这里用的也是二分查找。

这里的二分需要讨论一下二分的判断条件，有两个方式：
```
1.mid和low对比

2.mid和high对比
```
对应的：
```
0 1 2 4 5 6 7    mid>low 最小值在左半部分

8 9 0 2 3 4 5    mid<low 最小值在左半部分

6 7 8 9 0 1 2    mid>low 最小值在右半部分
```
所以这里发现无论mid是大于还是小于low,值均在左半部分

那么mid和high对比呢？
```
0 1 2 4 5 6 7    mid<high 最小值在左半部分

8 9 0 2 3 4 5    mid>high 最小值在左半部分

6 7 8 9 0 1 2    mid>high 最小值在右半部分
```
所以得出结论和mid和high进行对比

仔细观察，以上的例子均是在讨论无重复值的，那么我们只需要略去掉重复的即可，其实重复如果出现在数组中间，其实是无所谓的，关键是出现在数组的两端，那么我就直接去除两端重复即可。




### 代码

```c
int SearchMin(int *nums,int numsSize)
{
    int low=0,high=numsSize-1;
    int mid;
    while(high>low)
    {
        if(nums[low]<nums[high])return low;
        while(low<high&&nums[low]==nums[high])low++;//去除两端重复的
        mid=low+(high-low)/2;
        if(nums[mid]<nums[high])high=mid;
        else if(nums[mid]>nums[high])low=mid+1;
        else
        high--;
    }
    return high;
}
bool search(int* nums, int numsSize, int target){
    if(numsSize==0)
    return false;
    int dif=SearchMin(nums,numsSize);//找到最小值
    int len=numsSize-dif;//相对步长

    int low=0,high=numsSize-1,mid;
    while(high>=low)
    {
        mid=low+(high-low)/2;
        if(nums[(mid+dif)%numsSize]==target)return true;
        if(nums[(mid+dif)%numsSize]<target)low=mid+1;
        else
        high=mid-1;
    }
    return false;
}
```