### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s=sum(A)
        if s%3!=0:
            return False
        t,m,n=s//3,0,0
        for i in A:
            m+=i
            if m==t:
                n+=1
                m=0
        return m==0 and n>=3

```