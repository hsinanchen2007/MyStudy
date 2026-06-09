


```
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        S = S.lower()
        chars = [char for char in S]
        ls = len(S)
        self.res = []
        self.dfs([], 0, chars, ls)
        return self.res
        
    def dfs(self, cur_S, index, chars, ls):
        if index == ls:
            self.res.append(''.join(cur_S))
            return
        if chars[index].isdigit():
            cur_S.append(chars[index])
            index += 1
            self.dfs(cur_S, index, chars, ls)
            cur_S.pop()
            index -= 1
        else:
            cur_S.append(chars[index])
            index += 1
            self.dfs(cur_S, index, chars, ls)
            cur_S.pop()
            index -= 1
            
            cur_S.append(chars[index].upper())
            index += 1
            self.dfs(cur_S, index, chars, ls)
            cur_S.pop()
            index -= 1
```

