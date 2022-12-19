### 解题思路
主要就是处理进位.
如果有进位, 数值加1. 如果当前位数值>=10, 那进位设置为1, 否则设置为0
注意最后while循环结束的时候, 要检查下是否还有进位, 有进位的话要digits.insert(0, 1)

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] += 1
        i = len(digits) - 1
        jinwei = 0
        while i >= 0:
            if jinwei:
                digits[i] += 1
            if digits[i] >= 10:
                digits[i] -= 10
                jinwei = 1
            else:
                jinwei = 0
            i -= 1
        if jinwei:
            digits.insert(0, 1)
        return digits
            
```