### 解题思路
在超时的边缘反复横跳

### 代码

```python3
import itertools 
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        s=""
        for i in list(itertools.permutations(range(1,n+1),n))[k-1]:
            s+=str(i)
        return s
```