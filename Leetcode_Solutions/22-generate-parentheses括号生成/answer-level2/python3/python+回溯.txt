提供一种慢到爆炸的回溯解法😂
```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:    
        if not n:
            return []
        ans = []
        def panduan(s):
            mapping = {')': '(', ']': '[', '}': '{'}
            stack = []
            for c in s:
                if c in mapping:
                    if not stack or mapping[c] != stack.pop():
                        return False
                else:
                    stack.append(c)
            return not stack
        def helper(i,s):
            if i == n * 2:
                return
            if s.count('(') > n or s.count(')') > n:
                return
            if len(s) == n*2 and panduan(s) == True:
                ans.append(s)
            else:
                helper(i+1,s+'(')
                helper(i+1,s+')')
        helper(0,'(')
        return ans
```
