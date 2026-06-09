### 解题思路
跟前面有几道题的方法一样

### 代码

```python3
class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        d = {}
        for i in range(len(S)):
            if S[i] not in d:
                d[S[i]] = [-1,-1]
        for i in range(len(S)):
            if d[S[i]][0] == -1:
                d[S[i]][0] = i
                d[S[i]][1] = i
            else:
                d[S[i]][1] = i
        res = sorted(d.values())
        ans = []
        cur = res.pop(0)
        start = cur[0]
        end = cur[1]
        while res:
            next = res.pop(0)
            if start < next[0] < end:
                end = max(end,next[1])
            elif end < next[0]:
                ans.append(end - start + 1)
                start = next[0]
                end = next[1]
        ans.append(end - start + 1)
        return ans

```