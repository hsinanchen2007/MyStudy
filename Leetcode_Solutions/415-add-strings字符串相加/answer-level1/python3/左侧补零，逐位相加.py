### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        length = max(len(num1), len(num2))
        num1 = num1.zfill(length)
        num2 = num2.zfill(length)
        flag = 0
        answer = []
        for i in range(length - 1, -1, -1):
            value = int(num1[i]) + int(num2[i]) + flag
            if value >= 10:
                flag = 1
                answer.append(str(value % 10))
            else:
                flag = 0
                answer.append(str(value))

        if flag == 1:
            answer.append('1')

        answer.reverse()

        return ''.join(answer)
```