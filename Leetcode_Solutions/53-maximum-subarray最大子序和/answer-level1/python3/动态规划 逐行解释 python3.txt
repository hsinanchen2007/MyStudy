# 题解
## 动态规划
 1. 定义当前最大连续子序列和$cur\_sum=0$，最大子序和$res=nums[0]$，数组长度$n$
 2. 对数组进行遍历，对于$nums[i]$，存在两种情况：
 	* 若当前最大连续子序列和$cur\_sum>0$，说明$cur\_sum$对后续结果有着正向增益，即能使后续结果继续增大，则继续加和$cur\_sum=cur\_sum+num[i]$。
 	* 若当前最大连续子序列和$cur\_sum<=0$，说明$cur\_sum$对后续结果没有增益或负向增益，即若存在更大的加和，一定是从下一元素开始，加上$cur\_sum$，只会使结果更小。因此，令$cur\_sum$更新为$nums[i]$。
 	* 更新最大子序和$res$,$res=max(res,cur\_sum)$,始终保留最大结果。


### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_sum=0
        res=nums[0]
        n=len(nums)
        for i in range(n):
            if(cur_sum>0):
                cur_sum+=nums[i]
            else:
                cur_sum=nums[i]
            res=max(res,cur_sum)    
        return res
```
