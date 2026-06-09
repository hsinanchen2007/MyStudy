### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def simplifyPath(self, path: str) -> str:
        res = path.split("/")
        b = 0
        # 去除空字符串和"."
        for i in range(len(res)):
            if res[i-b] == "." or res[i-b] == "":
                res.remove(res[i-b])
                b += 1
        b = 0
        for i in range(len(res)):
            if res[i-b] == "..":
                if i-b == 0:
                    res.pop(i-b)
                    b += 1
                else:
                    res.pop(i-b-1)
                    res.pop(i-b-1)
                    b += 2
        return "/"+"/".join(res)
```