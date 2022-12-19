# 题解
本题为二分查找的一种应用，寻找排序数组中指定$target$的左右边界
## 二分法
### 寻找左侧边界算法流程：

 1. 初始化左指针$l=0$，右指针$r=n-1$，其中$n$为数组长度。
 2. 当$l<=r$时，执行循环：（**注意！**，因为初始化$r=n-1$，所以搜索区间为闭合区间$[l,r]$，因此结束条件为$l>r$，所以是$l<=r$）
 	* 定义$mid=(l+r)//2$，当$nums[mid]==target$时，将搜索区间置为$[l,mid-1]$，令$r=mid-1$。
 	* 当$nums[mid]>target$时，说明$target$在搜索区间$[l,mid-1]$中，令$r=mid-1$。。
 	* 当$nums[mid]<target$时，说明$target$在搜索区间$[mid+1,r]$中，令$l=mid+1$。
 
 3. 此时，返回$l$，但是注意有两种特殊情况：
 	* 如$[3,4,4,5,5,6],target=2$，按照上述算法，此时$l=0$，但是并不是下界，因此需要增加一个判定：$nums[l]==target$,如果满足，返回$l$，否则返回$-1$。
 	* 另一种情况$[1,2,3,4,5],target=6$，按照上述算法，会发现终止时，$l=5$，此时数组越界，增加特判：$l==n$，若满足，返回$-1$。

### 寻找右侧边界算法流程：

 1. 初始化左指针$l=0$，右指针$r=n$，其中$n$为数组长度，**注意** 这里右指针初始化$n$。
 2. 当$l<r$时，执行循环：（**注意！**，因为初始化$r=n$，所以搜索区间为右开区间$[l,r)$，因此结束条件为$l>=r$，所以是$l<r$）
 	* 定义$mid=(l+r)//2$，当$nums[mid]==target$时，将搜索区间置为$[mid+1,r)$，令$l=mid+1$。
 	* 当$nums[mid]<target$时，说明$target$在搜索区间$[mid+1,r)$中，令$l=mid+1$。。
 	* 当$nums[mid]<target$时，说明$target$在搜索区间$[l,mid)$中，令$r=mid$。
 3. 此时，返回$l-1$，因为终止条件为$l==r$，所以$l$为最后一个$target$的下一个索引。**注意！**，这里不需要特判的原因在于，若存在左界则一定存在右界，$-1$的情况在左界就过滤掉了，具体见代码。


### 复杂度分析
 - 时间复杂度：$O(\log n)$+$O(\log n)$,$O(\log n)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def left_bound(l,r):
            while(l<=r):
                mid=(l+r)//2
                if(nums[mid]==target):
                    r=mid-1
                elif(nums[mid]>target):
                    r=mid-1
                else:
                    l=l+1
            if(l==n):return -1
            return l if(nums[l]==target) else -1
        def right_bound(l,r):
            while(l<r):
                mid=(l+r)//2
                if(nums[mid]==target):
                    l=mid+1
                elif(nums[mid]<target):
                    l=mid+1
                else:
                    r=mid
            return l-1
        if(not nums):
            return [-1,-1]
        n=len(nums)
        left=left_bound(0,n-1)
        if(left==-1):
            return [-1,-1]
        right=right_bound(0,n)
        return [left,right]
```