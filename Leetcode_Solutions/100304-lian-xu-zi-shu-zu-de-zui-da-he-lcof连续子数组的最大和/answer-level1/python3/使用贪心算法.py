### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 本题用分治法nlgn.用贪心算法o(n)
        # 接下来使用贪心算法
        maxsum = nums[0]
        tmp = 0
        for i in range(len(nums)):
            # 排除数组全为负数情况
            if maxsum < nums[i]:
                maxsum = nums[i]
            
            tmp += nums[i]
            if tmp<0:
                tmp = 0
            elif tmp>maxsum:
                maxsum = tmp
        return maxsum

```