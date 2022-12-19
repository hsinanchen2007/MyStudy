# 题解
本题的难点在于：

 - 不能更改原数组
 - 只能使用$O(1)$的额外空间

## 二分法
按题目表达，设数组长度为$n$，则数组中元素$\in[1,n-1]$，且只有一个重复元素。一个直观的想法，设一个数字$k\in[1,n-1]$，统计数组中小于等于$k$的数字的个数$count$：
 1. 若$count<=k$，说明重复数字一定在$(k,n-1]$的范围内。
 2. 若$count>k$，说明重复数字一定在$[0,k]$的范围内。
 
利用这个性质，我们使用二分查找逐渐缩小重复数字所在的范围。
 1. 初试化左右 **数字** 边界$left=1,right=n-1$
 2. 循环条件$left<right$:
	+ $mid=(left+right)//2$
	+ 按照性质，统计数组中小于等于$mid$的元素个数$count$
	+ 若 $count<=mid$，说明重复数字一定在$(mid,right]$的范围内。令$left=mid+1$
	+ 若$count>mid$，说明重复数字一定在$[left,mid]$的范围内。令$right=mid$。
 3. 返回$left$

### 复杂度分析
 - 时间复杂度：$O\left(nlog(n)\right)$，二分法执行了$log(n)$次遍历$n$，因此复杂度为$O\left(nlog(n)\right)$。
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        left = 1
        right = len(nums) - 1
        while(left<right):
            mid=(left+right)//2
            count=0
            for num in nums:
                if(num<=mid):
                    count+=1
            if(count<=mid):
                left=mid+1
            else:
                right=mid
        return left

```

## 快慢指针
分为两步：

 1. 找到环
 2. 找到环的入口（即重复元素）


**找环：**

 1. 定义快慢指针$slow=0,fast=0$
 2. 进入循环：
 	+ $slow$每次走一步，即$slow=nums[slow]$
 	+ $fast$每次走两步，即$fast=nums[nums[fast]]$
 	+ 当$slow==fast$时，退出循环。
当快慢指针相遇时，一定在环内。此时假设$slow$走了$k$步，则$fast$走了$2k$步。设环的周长为$c$，则$k\%c==0$。

**找环的入口：**

 1. 定义新的指针$find=0$
 2. 进入循环：
 	+ $find$每次走一步，即$find=nums[find]$
 	+ $slow$每次走一步，即$slow=nums[slow]$
 	+ 当两指针相遇时，即$find==slow$，返回$find$

为何相遇时，找到的就是入口：
假设起点到环的入口(重复元素)，需要$m$步。此时$slow$走了$n+m$步，其中$n$是环的周长$c$的整数倍，所以相当于$slow$走了$m$步到达入口，再走了$n$步。所以相遇时一定是环的入口。
### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow=0
        fast=0
        while(1):
            slow=nums[slow]
            fast=nums[nums[fast]]
            if(slow==fast):
                break
        find=0
        while(1):
            find=nums[find]
            slow=nums[slow]
            if(find==slow):
                return find

```