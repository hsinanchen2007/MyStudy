### 解题思路

sum[j] - sum[i] 表示前j个数的和减去前i个数的和， sum(nums[i+1:j]), j > i+1。
遍历nums数据， 即能求出所有的sum, 而如果去遍历sum获取所有满足的i的time是O(n^2)，
而用dict存储cursum[k] （k<j)的值，将会让时间降低到O(n)

初始化 prefix[0] = 1主要是为了满足cursum[j]的和就为k, 不用去掉任何前缀和

类似的题: [713. 乘积小于K的子数组](https://leetcode-cn.com/problems/subarray-product-less-than-k/)

### 代码

```python
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if not nums:return 0

        ans = cursum = 0
        prefix = collections.defaultdict(int)
        prefix[0] = 1
        for num in nums:
            cursum = cursum + num
            ans += prefix[cursum-k]
            prefix[cursum] += 1

        return ans
```