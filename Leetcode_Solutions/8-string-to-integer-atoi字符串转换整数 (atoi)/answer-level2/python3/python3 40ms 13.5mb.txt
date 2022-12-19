### 解题思路
1. 先判断首位的，如果是符号，就记录正负，并接下来删掉首位
2. 然后寻找数字，逐个遍历，遇到非数字返回它之前的数字串，此时要考虑长度
3. 最后判断大小
### 代码

```python3
class Solution:
    INT_MAX = 2**31-1
    INT_MIN = -2**31
    def myAtoi(self, str: str) -> int:
        if not str:
            return 0
        tmp_part = str.split()
        if len(tmp_part) == 0:
            return 0
        else:
            part = tmp_part[0]
        if part[0].isnumeric():
            part = part
            sign = 1
        elif part[0] == "-":
            part = part[1:]
            sign = -1
        elif part[0] == "+":
            part = part[1:]
            sign = 1
        else:
            return 0
        num = part
        if len(part) == 0:
            return 0
        for i in range(0, len(part)):
            if not part[i].isnumeric():
                num=part[:i]
                print(num)
                break
        if len(num) == 0:
            return 0
        num = int(num) *sign
        if num>self.INT_MAX:
            return self.INT_MAX
        elif num<self.INT_MIN:
            return self.INT_MIN
        else:
            return num
```