### 解题思路
因为异或满足交换律和分配率，再加上两个相同的数异或为0，一个数与0异或为自身。因此将0到n中的n+1个数以及数组中的n个数依次去异或，2n+1个数中，出现在数组中的数异或了两次，缺失的数出现了一次，所以结果为缺失的数

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        missing = len(nums)
        for i, num in enumerate(nums):
            missing ^= i ^ num
        return missing

```