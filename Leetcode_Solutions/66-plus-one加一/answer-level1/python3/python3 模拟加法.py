### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if not digits: return digits
        digits[-1] += 1
        carry, remainder = divmod(digits[-1], 10)
        if carry > 0:
            # 先处理最后一个
            digits[-1] = remainder
            for i in range(len(digits) - 2, -1, -1):
                digits[i] += carry
                carry, remainder = divmod(digits[i], 10)
                if carry == 0:
                    break
                digits[i] = remainder
        if carry > 0:   # 如果是[9, 9, 9]，需要再向前进位
            digits.insert(0, 1)
        return digits
```