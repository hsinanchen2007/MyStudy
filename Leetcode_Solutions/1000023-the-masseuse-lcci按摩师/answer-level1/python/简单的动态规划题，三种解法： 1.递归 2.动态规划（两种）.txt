### 解题思路
简单的动态规划题
三种解法：
1.递归
2.动态规划（两种）

### 代码

```python3

# 递归
class Solution:
    def massage(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums[0], nums[1])
        len1 = nums[length - 1] + self.massage(nums[:length - 2])
        len2 = nums[length - 2] + self.massage(nums[:length - 3])
        return max(len1, len2)


# 动态规划一：空间复杂度为O(n)
class Solution:
    def massage(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums[0], nums[1])
        dp = [0 for _ in range(length)]
        dp[0] = nums[0]
        dp[1] = nums[1]
        dp[2] = nums[2] + nums[0]
        for i in range(3, length):
            dp[i] = nums[i] + max(dp[i - 2], dp[i - 3])
        return max(dp[length - 1], dp[length - 2])


# 动态规划二：省内存，空间复杂度为O(1)
class Solution:
    def massage(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums[0], nums[1])
        num0 = nums[0]
        num1 = nums[1]
        num2 = nums[2] + nums[0]
        for i in range(3, length):
            num = num2
            num2 = nums[i] + max(num0, num1)
            num0 = num1
            num1 = num
        return max(num1, num2)
```