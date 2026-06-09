### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        judge = {}
        trs = {}
        if trust ==  []:
            return N
        for p in trust:
            judge.setdefault(p[0], []).append(p[1])
            if p[1] not in trs.keys():
                trs.setdefault(p[1], 1)
            else:
                trs[p[1]] += 1
        print(trs)
        print(judge)

        sorted_trs = sorted(trs.items(), key=lambda item: item[1], reverse=True)
        print(sorted_trs)
        for k, v in sorted_trs:
            if k not in judge.keys() and v == N-1:
                return k
        return -1
```