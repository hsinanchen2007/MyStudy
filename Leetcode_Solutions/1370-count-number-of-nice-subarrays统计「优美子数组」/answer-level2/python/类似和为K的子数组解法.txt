### 解题思路
此题与《和为K的子数组》https://leetcode-cn.com/problems/subarray-sum-equals-k/
解法一致
### 代码

```python3
class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        m = len(nums)
        if m <= 0: return 0
        sum_dict = dict(); sum_dict[0] = 1
        ans  = 0; temp = 0
        for num in nums:
            temp += 1 if num % 2 else 0
            if temp - k in sum_dict:
                ans += sum_dict[temp-k]
            if temp not in sum_dict:
                sum_dict[temp] = 1
            else:
                sum_dict[temp] += 1
        return ans

```