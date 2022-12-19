### 解题思路
将`digits`数组逆序处理，用一个变量`a`来存放当前位是否需要+1。+1后，如果未进位，`a`置零，跳出循环；进位的话，`a`仍然为1.如果处理完`digits`的每一位后，`a`仍然为1，说明最后要进一位，于是`digits.append(1)`。
### 代码

```python3
class Solution:
    def plusOne(self, digits):
        digits = digits[::-1]
        a = 1
        for i in range(len(digits)):
            digits[i] += a
            a = 0
            if digits[i] >= 10:
                digits[i] -= 10
                a = 1
            else:
                break
        if a == 1:
            digits.append(1)
        return digits[::-1]
```