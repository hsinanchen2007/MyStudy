### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        def w(x):
            count=0
            while x!=1:
                if x%2==0:
                    x/=2
                else:
                    x=3*x+1
                count+=1
            return count
        return [one[0] for one in sorted({ one:w(one) for one in range(lo,hi+1)}.items(),key=lambda x:x[1])][k-1]
```