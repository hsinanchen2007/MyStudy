从[@tuffy](/u/tuffy)和[@coder](/u/coder)的解得到启发
也是树里面比较有意思的一题

```
class Solution:
    def verifyPreorder(self, preorder: List[int]) -> bool:
        if preorder:
            st,lower=[],-1<<30
            for e in preorder:
                if e<lower:
                    return False
                if st and e>st[-1]:
                    last=0
                    while st and e>st[-1]:
                        last=st.pop()
                        lower=max(lower,last)
                    if not st:
                        lower=last
                st.append(e)
            return True
        return True
```
