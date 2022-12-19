### 解题思路
这道题是对二分查找的应用，我对于解题的看法就是，我们只要找出了主要矛盾，然后看看能否找到解决办法就可以解决问题了。

先看完说明，得出结论，不能用hash，只能用O（nlogn）以及以下的时间复杂度，那么肯定就是用二分了，当然也许其他的办法也行，但是二分这里是能够立马想得到的。

但是这里和普通的二分查找有所不同，我们是在一个数组中查找一个重复的元素，那么就有两个问题
```
1.有一个元素出现超过1次

2.这个目标值是数组中的
```
解决方案：
```
1.我们对于每一个元素均作为目标值来查找一次

2.我们在查找的时候需要对查找到他本身进行分析
```
这里详细说明一下如果找到了相同元素
```
我们其实可以发现，如果我们找到了一个元素等于目标值，
要么是它本身要么是它左边或者右边(如果两边至少又一边存在)，
所以我们只需要判断一下目标值旁边是否还有即可。
```




### 代码

```c
int cmp(const void *_a,const void* _b)
{
    return *(int *)_a-*(int *)_b;
}
int findDuplicate(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cmp);
    int mark,target;

    int low=0,high=numsSize-1,mid;
    int i;
    for(i=0;i<numsSize-1;i++)
    {
        target=nums[i];
        low=0,high=numsSize-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]==target) 
                if(mid-1>-1&&nums[mid-1]==target||mid+1<numsSize&&nums[mid+1]==target)
                return target;
                else 
                break;
            if(nums[mid]<target)low=mid+1;
            else
            high=mid-1;
        }
    }
    return 0;
}
```