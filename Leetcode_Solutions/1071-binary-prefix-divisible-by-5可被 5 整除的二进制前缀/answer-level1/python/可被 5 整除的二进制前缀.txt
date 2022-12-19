### 解题思路
此题的重点是解决二进制数到十进制数转化的问题，若是常规按位计算时间复杂度较高 超时。
若初始为 110...1 代表的十进制数为 num 往下走一位,若此时二进制数为 110...10,则num1 = num * 2,若此时二进制数为 110...11, 则num1 = num * 2 + 1

### 代码

```python
class Solution(object):
    def prefixesDivBy5(self, A):
        num = 0
        answers = []
        for i in range(len(A)):
            if A[i] == 0:
                num *= 2
            else:
                num = num*2 + 1 
            if num % 5 == 0:
                answers.append(True)
            else:
                answers.append(False)
        return answers
```