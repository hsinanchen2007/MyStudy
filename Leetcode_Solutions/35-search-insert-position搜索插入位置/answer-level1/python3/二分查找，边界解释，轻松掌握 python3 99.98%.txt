# 题解
由于是排序不重复数组，本题实质上为二分查找
## 二分法
 1. 初始化左指针$l=0$，右指针$r=n-1$，其中$n$为数组长度。$res=-1$，用来保存$target$不在数组中的情况。
 2. 当$l<=r$时，执行循环：（**注意！**，因为初始化$r=n-1$，所以搜索区间为闭合区间$[l,r]$，因此结束条件为$l>r$，所以是$l<=r$）
 	* 定义$mid=(l+r)//2$，当$nums[mid]==target$时，返回$mid$,。
 	* 当$nums[mid]>target$时，说明$target$在搜索区间$[l,mid-1]$中，令$r=mid-1$。。
 	* 当$nums[mid]<target$时，说明$target$在搜索区间$[mid+1,r]$中，令$l=mid+1$。
 
 3. 此时，返回$l$，即为插入位置，三种情况：
 	* $[2,3,5,6,7],target=4$，此时$l=2$，满足。
 	* $[2,3,4,5,6],target=0$，此时$l=0$，满足。
 	* $[2,3,4,5,6],target=7$，此时$l=5$，满足。
 	



### 复杂度分析
 - 时间复杂度：$O(\log n)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if(not nums):
            return 0
        n=len(nums)
        l=0
        r=n-1
        res=-1
        while(l<=r):
            mid=(l+r)//2
            if(nums[mid]==target):
                return mid
            elif(nums[mid]>target):
                r=mid-1
            else:
                l=mid+1
        res=l
        return res