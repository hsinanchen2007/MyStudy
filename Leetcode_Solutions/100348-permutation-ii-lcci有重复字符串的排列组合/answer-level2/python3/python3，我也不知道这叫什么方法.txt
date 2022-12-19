### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def permutation(self, S: str) -> List[str]:
        if not S:
            return []
        if len(S) == 1:
            return [S]

        S = ''.join(sorted(list(S)))

        res = []
        def helper(cur_S='', rest_S=S):
            if len(rest_S) == 0:
                res.append(cur_S)
            for i in range(len(rest_S)):
                if i == 0:
                    helper(cur_S+rest_S[i], rest_S[:i]+rest_S[i+1:])
                elif i > 0 and rest_S[i] != rest_S[i-1]:
                    helper(cur_S+rest_S[i], rest_S[:i]+rest_S[i+1:])
        helper()
        return res
        
            



```