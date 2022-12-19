# 题解
## 两次遍历
**第一次简历：**
从前向后遍历，使用$max\_num$，保存到当前位置为止的最大值，若下个数大于等于$max\_num$，则更新$max\_num$。否则，更新需要排序数组的右界$right$。

 1. 初始化$right=0$，$max\_num=nums[0]$
 2. 遍历数组，遍历区间$[0,n)$：
 	+ 若$nums[i]>=max\_num$，更新$max\_num=nums[i]$
 	+ 否则，更新右界$right=i$

**第二次简历：**
从后向前遍历，使用$min\_num$，保存到当前位置为止的最小值，若下个数小于等于$min\_num$，则更新$min\_num$。否则，更新需要排序数组的左界$left$。

 1. 初始化$left=n$，$min\_num=nums[-1]$
 2. 遍历数组，遍历区间$(n,0]$：
 	+ 若$nums[i]<=min\_num$，更新$min\_num=nums[i]$
 	+ 否则，更新左界$right=i$

若$right-left+1>0$，返回$right-left+1$，否则，返回$0$
### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n=len(nums)
        max_num=nums[0]
        right=0
        for i in range(n):
            if(nums[i]>=max_num):
                max_num=nums[i]
            else:
                right=i
        left=n
        min_num=nums[-1]
        for i in range(n-1,-1,-1):
            if(nums[i]<=min_num):
                min_num=nums[i]
            else:
                left=i
        return right-left+1 if(right-left+1 >0) else 0
```

## 排序比对
很自然的想法，将原数组copy并排序，和原数组比对。

### 复杂度分析
 - 时间复杂度：$O\left(nlog(n)\right)$
 - 空间复杂度：$O(n)$

### Python

```python
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        nums_copy=nums[:]
        nums_copy.sort()
        left=float("inf")
        right=0
        for i in range(len(nums)):
            if(nums_copy[i]!=nums[i]):
                left=min(left,i)
                right=max(right,i)
        return right-left+1 if(right-left+1 > 0) else 0
```
