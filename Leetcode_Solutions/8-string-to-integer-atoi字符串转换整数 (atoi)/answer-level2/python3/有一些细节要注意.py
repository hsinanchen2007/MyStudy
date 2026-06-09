### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        ans = str.strip()
        if ans == '':return 0
        if ans[0] == '-':
            flag = -1
            ans = ans[1:]
        elif ans[0] == '+':
            flag = 1
            ans = ans[1:]
        elif ans[0].isdigit():
            flag = 1
        else:
            return 0
        value = 0

        for i in ans:
            if i.isdigit():
                value = 10*value + int(i)
            else:
                break
            if flag*value > 2147483647:return 2147483647
            if flag*value < -2147483648: return -2147483648
        return flag*value
```