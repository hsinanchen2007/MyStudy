### 解题思路
遍历列表，将数值转换成字符型，根据字符长度判断位数。

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        ans = 0
        for i in nums:
            if not len(str(i))%2: ans += 1
        return ans

```