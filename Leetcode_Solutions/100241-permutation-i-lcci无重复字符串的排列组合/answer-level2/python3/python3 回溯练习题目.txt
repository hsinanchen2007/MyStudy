### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        # return ["".join(i) for i in itertools.permutations(S)]

        ans = []

        def helper(S,res=''):
            if not S:
                ans.append(res)
                return
            for i in range(len(S)):
                helper(S[:i]+S[i+1:],res+S[i])
        
        helper(S)
        return ans
```