### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        extra = 1
        len_digits = len(digits)
        for i in range(len_digits):
            num = digits[len_digits-i-1]+extra
            digits[len_digits-i-1]= num % 10
            extra = num // 10
        if extra ==1:
            digits.insert(0,extra)
        return digits


```