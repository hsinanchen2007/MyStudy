# 题解
## 桶排序
 
本题希望找到没有出现的最小整数，即我们只需从索引$0$开始观测，找到第一个$nums[i]!=i+1$即可。
也就意味着**一个萝卜一个坑**，自然想到桶排序。

 1. 特判，若$nums$为空，则返回$1$
 2. 遍历数组，进入循环，循环条件：对于索引$i$处的$nums[i]$，$nums[i]-1$是否满足在索引范围$[0,n-1]$,且$nums[i]!=nums[nums[i]-1]$，表示若索引处已经存放一个正确元素，则退出循环。
 	+ 交换$nums[nums[i]-1]$和$nums[i]$
 
 3. 遍历数组，找到第一个$nums[i]!=i+1$，返回$i+1$，若遍历结束不返回，则返回$n+1$。

 	


### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if(not nums):
            return 1
        n=len(nums)
        for i in range(n):
            while(0<nums[i]<=n and nums[i]!=nums[nums[i]-1]):
                nums[nums[i]-1],nums[i]=nums[i],nums[nums[i]-1]
        for i in range(n):
            if(nums[i]!=i+1):
                return i+1
        return n+1
```