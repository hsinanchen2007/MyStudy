### 解题思路


### 代码

```python
class Solution(object):
    def permutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        if S == '':
            return []
        ans = [S[0]]
        n = len(S)
        for i in range(1, n):
            add = S[i]
            while len(ans[0]) == i:
                a = ans.pop(0)
                for k in range(i+1):
                    ans.append(a[:k]+add+a[k:])
        return ans
                    



```