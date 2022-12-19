### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(m,n):
            if m>n:
                m,n=n,m
            if n%m==0:
                return m
            return gcd(m,n%m)
        c=collections.Counter(deck)
        l=list(c.values())
        x=l[0]
        for i in l[1:]:
            x=gcd(x,i)
            if x==1:
                return False
        return x>1

```