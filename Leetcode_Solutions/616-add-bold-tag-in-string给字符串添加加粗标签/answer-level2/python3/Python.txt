### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addBoldTag(self, s: str, dict: List[str]) -> str:
        N = len(s)
        mask = [False] * N
        for i in range(N):
            prefix = s[i:]
            for word in dict:
                if prefix.startswith(word):
                    for j in range(i, min(i+len(word), N)):
                        mask[j] = True
        ans = []
        for incl, grp in itertools.groupby(zip(s, mask), lambda z: z[1]):
            if incl: ans.append("<b>")
            ans.append("".join(z[0] for z in grp))
            if incl: ans.append("</b>")
        return "".join(ans)
```