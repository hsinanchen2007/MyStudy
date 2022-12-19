### 解题思路
此处撰写解题思路
map, join的使用
### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        res = []
        for i in range(len(S)):
            if i == 0 or S[i] != S[i - 1]:
                res.append(S[i])
                res.append(1)
            else:
                res[-1] += 1
        if len(res) < len(S):
            last = "".join(map(str,res))
            return last
        else:
            return S

```