### 解题思路
遍历整个list,对于每一个非0数字，通过整除10来判断它的位数，如果位数是偶数，计数器count + 1

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        count = 0
        for i in nums:
            count_ = 0
            while i != 0:
                i //= 10
                count_ += 1
            if count_ % 2 == 0:
                count += 1
        
        return count

```