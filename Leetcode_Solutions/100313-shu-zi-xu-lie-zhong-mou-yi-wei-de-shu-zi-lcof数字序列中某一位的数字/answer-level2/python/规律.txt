### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findNthDigit(self, n: int) -> int:
        n += 1
        p = [0]*11
        p[0] = 1
        for i in range(1,11):
            p[i] = 9*i*10**(i-1)
        ind = 0
        while ind<11 and n>p[ind]:
            n -= p[ind]
            ind += 1
        if ind==0:return 0
        if n%ind==0:return int(str(n//ind-1+10**(ind-1))[-1])
        else:return int(str(n//ind+10**(ind-1))[n%ind-1])
        
            
```