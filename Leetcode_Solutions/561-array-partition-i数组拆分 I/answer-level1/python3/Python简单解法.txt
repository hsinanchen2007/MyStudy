### 解题思路
1、要理解题意，其实可以理解为：2个组合中，取第二大的，所以要让大的都尽量组合在一起，也就是排序。
2、排序，求和即可

### 代码

```

class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum(nums[0::2])

```