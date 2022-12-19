### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        flag1 = 0
        flag2 = 0
        index = -1
        flag_l = -1
        flag_ch = ''
        for ch in str:
            index += 1
            if ch == ' ':
                if flag1==1 or flag2==1:
                    break
                continue
            elif flag1 == 0 and (ch == '+' or ch == '-'):
                flag1 = 1
                flag_ch = ch
            elif ch >= '0' and ch <= '9':
                flag1 = 1
                flag2 = 1
                if flag_l == -1:
                     flag_l = index
            else:
                if flag1 == 0:
                    return 0
                index -= 1
                break
        if str == "" or flag1 == 0 or flag2 == 0:
            return 0
        res = int(flag_ch + str[flag_l : index+1])
        if res > 2147483647:
            return 2147483647
        elif res < -2147483648:
            return -2147483648
        else:
            return res
```