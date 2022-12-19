### 解题思路
将所有0的索引保存到zero_index中；
根据zero_index计算所有1的长度，保存到difference中
返回difference的最大值

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        if(0 not in nums):
            return len(nums)
        zero_index = []
        for i in range(len(nums)):
            if(nums[i] == 0):
                zero_index.append(i)
        difference = []
        difference.append(zero_index[0])
        for j in range(1,len(zero_index)):
            difference.append(zero_index[j]-zero_index[j-1]-1)
        difference.append(len(nums) - zero_index[-1] - 1)
        difference.sort()
        return difference[-1]
```