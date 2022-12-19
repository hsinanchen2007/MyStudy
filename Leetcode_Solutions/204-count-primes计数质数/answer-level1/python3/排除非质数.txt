### 解题思路
我们都知道一个质数除了它本身，它的倍数都是非质数，所以我们只要排除掉这些非质数即可
### 代码

```python3
class Solution:
    def countPrimes(self, n: int) -> int:
        if n<3: return 0
        v=[1]*n
        v[0],v[1]=0,0
        for i in range(2,n):
            if v[i]==1:
                for j in range(2*i,n)[::i]:
                    v[j]=0
        return v.count(1)
```