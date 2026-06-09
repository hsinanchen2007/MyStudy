### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        c = 1
        for i in range(len(digits)-1, -1, -1):
            tmp = digits[i] + c
            digits[i] = tmp % 10
            c = tmp // 10
        if c > 0:
            digits.insert(0, c)
        return digits

```