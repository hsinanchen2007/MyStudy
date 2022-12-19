### 解题思路
我们只要算出当前的和, 对比一下完整数字列表的和, 就知道缺了哪个数字

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        expected_sum = (len(nums) + 0) * (len(nums) + 1) // 2  # 等差数列高斯求和公式.
        return expected_sum - sum(nums)

```