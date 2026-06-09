### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        num = []
        flag = True
        if len(str) == 0:
            return 0
        if str[0] == ' ':
            i = 0
            while i < len(str) and str[i] == ' ':
                i += 1
            str = str[i:]
        if len(str) == 0:
            return 0
        if str[0] == '-':
            flag = False
            if len(str) > 2 and str[1] == '+':
                return 0
            else:
                str = str[1:]
        if len(str) == 0:
            return 0
        if str[0] == '+':
            flag = True
            str = str[1:]
        if len(str) == 0:
            return 0
        if ord(str[0]) > 57 or ord(str[0]) < 48:
            return 0
        while str[0] == '0':
            str = str[1:]
            if len(str) == 0:
                return 0
        i = 0
        while i < len(str) and ord(str[i]) <= 57 and ord(str[i]) >= 48:
            num.append(ord(str[i]) - 48)
            i += 1
        if flag:
            maxint = [2,1,4,7,4,8,3,6,4,7]
        else:
            maxint = [2,1,4,7,4,8,3,6,4,8]
        if len(num) > 10:
            if flag:
                return 2147483647
            else:
                return -2147483648
        if len(num) == 10:
            for i in range(10):
                if num[i] == maxint[i]:
                    continue
                if num[i] < maxint[i]:
                    break
                if num[i] > maxint[i]:
                    if flag:
                        return 2147483647
                    else:
                        return -2147483648
        result = 0
        for i in range(len(num)):
            result += num[len(num)-i-1] * pow(10, i)
        if flag:
            return result
        else:
            return 0-result
```