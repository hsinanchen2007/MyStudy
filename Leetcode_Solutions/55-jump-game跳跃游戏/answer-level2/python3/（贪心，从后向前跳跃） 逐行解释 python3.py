# 题解
## 贪心算法
 1. 定义目前达到的最远位置$max\_bound=0$，和上一步到达的边界$end=0$。
 2. 遍历数组，遍历范围$[0,n)$：
 	* 所能达到的最远位置$max\_bound=max(max\_bound,nums[i]+i)$，表示上一最远位置和当前索引$i$和索引$i$上的步数之和中的较大者。
 	* 如果索引$i$到达了上一步的边界$end$，即$i==end$，则：
 		+ 更新边界$end$，令$end$等于新的最远边界$max\_bound$，即$end=max_bound$
 		+ 判断可到达边界是否大于等于$n-1$，若满足，则返回$True$
 4. 返回$False$
 **注意！**数组遍历范围为$[0,n)$，和[45.跳跃游戏II](https://blog.csdn.net/zhushaojiecumt/article/details/102897792)不同的是，这里只需判断能否到达，而不需精确的步数，因此不需要纠结于最后一步，且这样可以避免长度为1的特判。


### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_bound=0
        n=len(nums)
        end=0
        for i in range(n):
            max_bound=max(max_bound,nums[i]+i)
            if(i==end):
                end=max_bound
            if(end>=n-1):
                return True
        return False
```


## 从后向前跳跃
 1. 定义索引$last\_index=n-1$
 2. 遍历范围$[n-1,0]$，倒序遍历：
 	* 若当前位置可到达的边界大于等于$last\_index$，说明可将$last\_index$更新到当前位置，即$last\_index=i$
 
 3. 若$last\_index==0$，说明从$0$处可以到达$n-1$处，返回$True$，否则返回$False$。

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lastindex=len(nums)-1
        for i in range(len(nums)-1,-1,-1):
            if(i+nums[i]>=lastindex):
                lastindex=i
        return lastindex==0
```