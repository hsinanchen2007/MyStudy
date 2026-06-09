### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        res = ""
        if not str:return 0
        for s in str:
            # 判断第一个字符是不是合理开始字符
            if not res and not s.isdigit() and s not in '+- ':
                return 0
            elif s in '-+' and not res:
                res += s 
            elif not s.isdigit() and res:
                break
            elif s.isdigit():
                res += s
        if not res or res == '+' or res == '-':return 0
        elif res[0] == '-':
            return - int(res[1:]) if 0 <= int(res[1:]) <= 2 ** 31 else - 2 ** 31
        elif res[0] == '+':
            return int(res[1:]) if 0 <= int(res[1:]) <= 2 ** 31 else 2 ** 31 - 1
        else:
            return int(res) if 0 <= int(res) <= 2 ** 31 - 1 else 2 ** 31 - 1


```