### 解题思路
此题可用动态规划求解，a[i]表示以nums[i]为结尾的最长子序列长度，遍历num[i]之前的数并更新a[i]的值

### 代码

```python
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a=[1]*len(nums)
        if len(nums)==0:
            return 0
        for i in range(1,len(nums)):
            for j in range(0,i):
                if(nums[i]>nums[j]):
                    a[i]=max(a[i],a[j]+1)
        return max(a)

```