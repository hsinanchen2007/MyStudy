### 解题思路
暴力搜索 时长有点长

### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        res = ""
        ss = s
        flag = 0
        while True:
            if flag == 0:
                x = min(ss)
                res = res + x
                ss = ss.replace(x,"")
                s = s.replace(x,"",1)
                if ss == "":
                    flag = 1
                    ss = s
            else:
                x = max(ss)
                res = res + x
                ss = ss.replace(x,"")
                s = s.replace(x,"",1)
                if ss == "":
                    flag = 0
                    ss = s
            if s == "":
                break
        return res
```