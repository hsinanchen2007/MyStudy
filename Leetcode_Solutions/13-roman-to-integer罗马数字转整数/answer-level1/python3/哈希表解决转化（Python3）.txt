### 解题思路
使用哈希表来运算，当a>b且a在b之后，运算时b要取它的相反数来运算。除了这个情况之外，都按照加法运算

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        d={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        num=0
        for i in range(len(s)-1):
            if d[s[i]]<d[s[i+1]]:
                num-=d[s[i]]
            else:
                num+=d[s[i]]
        return num+d[s[-1]]        

                

```