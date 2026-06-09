### 解题思路
原地操作省拷贝
大小切换位运算

### 代码

```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        if not S:return []
        res = []
        def dfs(S,ix):
            if ix == len(S): # 0,1,2 3==3
                res.append(''.join(S)) #  copy inplace value 
                return 
            dfs(S,ix+1) # keep raw
            if S[ix].isalpha(): # not S[ix].isdigit()
                S[ix] = chr(ord(S[ix]) ^ (1<<5)) # bit +-32 for char toggle; inplace op
                dfs(S,ix+1)
                S[ix] = chr(ord(S[ix]) ^ (1<<5)) # reset
        dfs(list(S),0)
        return res
```