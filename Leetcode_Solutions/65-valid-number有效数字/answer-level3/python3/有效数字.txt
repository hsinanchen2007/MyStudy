## 思路:

思路一:作弊法

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        try:
            num = float(s)
            return True
        except:
            return False
```

思路二:考虑所有情况

思路三:有限自动机



![1.png](https://pic.leetcode-cn.com/0ae239f74ce6ecaaf7c9044291b3fcdc8c5e60ac28dc447b7712a1500f9b3e01-1.png)


以上思路二,三皆来自网络,我不是大佬,只是大自然搬运工!



## 代码:

思路二:

```python
class Solution:
    def isNumber(self, s: str):
        s = s.strip()
        #print(s)
        dot_seen = False
        e_seen = False
        num_seen = False
        for i, a in enumerate(s):
            if a.isdigit():
                num_seen = True
            elif a == ".":
                if e_seen or dot_seen:
                    return False
                dot_seen = True
            elif a == "e":
                if e_seen or not num_seen:
                    return False
                num_seen = False
                e_seen = True
            elif a in "+-":
                if i > 0 and s[i - 1] != "e":
                    return False
            else:
                return False
        return num_seen
```

思路三:

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        state = [
            {},
            # 状态1,初始状态(扫描通过的空格)
            {"blank": 1, "sign": 2, "digit": 3, ".": 4},
            # 状态2,发现符号位(后面跟数字或者小数点)
            {"digit": 3, ".": 4},
            # 状态3,数字(一直循环到非数字)
            {"digit": 3, ".": 5, "e": 6, "blank": 9},
            # 状态4,小数点(后面只有紧接数字)
            {"digit": 5},
            # 状态5,小数点之后(后面只能为数字,e,或者以空格结束)
            {"digit": 5, "e": 6, "blank": 9},
            # 状态6,发现e(后面只能符号位, 和数字)
            {"sign": 7, "digit": 8},
            # 状态7,e之后(只能为数字)
            {"digit": 8},
            # 状态8,e之后的数字后面(只能为数字或者以空格结束)
            {"digit": 8, "blank": 9},
            # 状态9, 终止状态 (如果发现非空,就失败)
            {"blank": 9}
        ]
        cur_state = 1
        for c in s:
            if c.isdigit():
                c = "digit"
            elif c in " ":
                c = "blank"
            elif c in "+-":
                c = "sign"
            if c not in state[cur_state]:
                return False
            cur_state = state[cur_state][c]
        if cur_state not in [3, 5, 8, 9]:
            return False
        return True
```

