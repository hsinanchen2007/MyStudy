### 解题思路
【**函数定义**】
定义目标函数：f(n) 表示以元素a[n]为结尾的子序列集合中的最大和
那么本题要求解的就是 max{f(1), f(2), f(3), ..., f(n)}

【**推导过程**】
记符号S[m,n] = sum(a[m], a[m+1], ..., a[n-1], a[n])
那么有：
f(n)   = max(S[1,n], S[2,n], ...,     S[n-2,n], S[n-1,n])
f(n-1) = max(S[1,n-1], S[2,n-1], ..., S[n-2,n-1])

由f(n) = max(S[1,n], S[2,n], ...,     S[n-2,n], S[n-1,n])
        = max(S[1,n-1]+a[n], S[2,n-1]+a[n], ..., S[n-2,n-1]+a[n], a[n-1]+a[n])
        = max{max(S[1,n-1]+a[n], S[2,n-1]+a[n], ..., S[n-2,n-1]+a[n]), a[n-1]+a[n]}
        = max{max(S[1,n-1], S[2,n-1], ..., S[n-2,n-1])+a[n], a[n-1]+a[n]}
        = max(f(n-1)+a[n], a[n-1]+a[n])
        = max(f(n-1), a[n-1]) + a[n]

得出：
**f(n) = max(f(n-1), a[n-1]) + a[n]**

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        maxSum_i = nums[0]
        rst = maxSum_i
        for i in range(1, len(nums)):
            maxSum_i = max(maxSum_i+nums[i], nums[i])
            rst = maxSum_i if maxSum_i > rst else rst
            
        return rst
```