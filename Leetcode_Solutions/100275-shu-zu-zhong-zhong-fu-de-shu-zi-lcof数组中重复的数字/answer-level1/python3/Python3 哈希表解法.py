### 解题思路
利用Counter方法，计数过程中发现重复数字便返回。
执行用时 :68 ms, 在所有 Python3 提交中击败了48.04%的用户
内存消耗 :23.1 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        from collections import Counter
        c = Counter()

        for num in nums:
            c[num] = c[num] + 1
            if c[num] > 1:
                return num
        
```