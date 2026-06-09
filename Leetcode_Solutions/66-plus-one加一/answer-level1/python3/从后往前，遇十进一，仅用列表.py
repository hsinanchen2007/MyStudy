### 解题思路
如题

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        final = -1
        while True:
            digits[final] = digits[final]+1
            if digits[final]==10:
                digits[final] = 0
                final -= 1
                if -final > len(digits):
                    digits.insert(final,1)
                    break
            else:
                break
        return digits
```