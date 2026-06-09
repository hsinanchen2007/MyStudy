```python
class Solution:
    def permutation(self, s: str) -> List[str]:
        if not s: return []
        ans = []

        def back_tracking(s, strings):
            if not s:
                ans.append(''.join(strings))
                return 
            visited = set()
            for i in range(len(s)):
                if s[i] in visited: continue
                back_tracking(s[:i]+s[i+1:], strings+[s[i]])
                visited.add(s[i])
            
        back_tracking(s, [])

        return ans 
```