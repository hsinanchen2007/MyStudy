回溯或者循环调用下一个组合

```python
class Solution:
    def permutation(self, S: str) -> List[str]:
        # 方法1: 回溯
        v = {}
        for c in S:
            v[c] = False
        res = []

        def dfs(path):
            if len(path) == len(S):
                res.append(path)
                return
            for c in v:
                if not v[c]:
                    v[c] = True
                    dfs(path + c)
                    v[c] = False

        dfs('')
        return res
        # 方法2: 找下一个组合
        # def getNext(s):
        #     for i in range(len(s) - 1)[::-1]:
        #         if s[i] < s[i + 1]:
        #             j = i + 1
        #             while j < len(s) and s[j] > s[i]:
        #                 j += 1
        #             j -= 1
        #             ls = list(s)
        #             ls[i], ls[j] = ls[j], ls[i]
        #             return ''.join(ls[0:i + 1] + ls[i + 1:][::-1])
        #     return s[::-1]

        # res = [S]
        # cur = getNext(S)
        # while cur != S:
        #     res.append(cur)
        #     cur = getNext(cur)
        # return res
```
