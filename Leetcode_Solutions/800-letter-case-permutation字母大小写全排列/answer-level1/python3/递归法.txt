字母与32异或即可转换大小写，直接递归。
```
def letterCasePermutation(self, S: str) -> List[str]:
        if not S:
            return []
        res = []
        
        def dfs(cur, start, S):
            if len(cur) == len(S):
                res.append(cur)
                return
            if '0' <= S[start] <= '9':
                dfs(cur + S[start], start + 1, S)
            else:
                dfs(cur + chr(ord(S[start]) ^ (1 << 5)), start + 1, S)
                dfs(cur + S[start], start + 1, S)
        
        dfs('', 0, S)
        return res
```
