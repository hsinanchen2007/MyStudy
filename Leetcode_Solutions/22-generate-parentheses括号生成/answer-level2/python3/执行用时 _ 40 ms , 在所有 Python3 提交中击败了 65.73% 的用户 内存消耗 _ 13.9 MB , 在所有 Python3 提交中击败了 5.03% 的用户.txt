### 解题思路
简单深搜

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def dsf(cur, l_left, r_left):
            if l_left == 0 and r_left == 0:
                res.append(cur)
                return 
            if r_left >0 and r_left > l_left:
                dsf(cur + ')', l_left, r_left -1)
            if l_left > 0 :
                dsf(cur + '(', l_left-1, r_left)
        
        res = []
        dsf('',n,n)
        return res

```