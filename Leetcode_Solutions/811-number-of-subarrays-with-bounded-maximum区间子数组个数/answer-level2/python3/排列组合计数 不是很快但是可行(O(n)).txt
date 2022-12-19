### 解题思路
先按照比R大的把A分成几段，每一段长度为$len_i$符合条件的数组数$n_i$为$\frac{len_{i}*(len_{i}+1)}{2}$
符合这个条件的总数是$large=\sum{n_i}$

先按照比L大的把A分成几段，每一段长度为$len_j$符合条件的数组数$n_j$为$\frac{len_{j}*(len_{j}+1)}{2}$
符合这个条件的总数是$small=\sum{n_j}$
于是总数就是$n_i - n_J$

### 代码

```python3

class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        if len(A) == 0:
            return 0
        i = 0; ret = 0
        while i < len(A):
            tot = 0
            j = i
            while j < len(A) and A[j] <= R:
                tot += 1; j+= 1
            i = j+1
            ret += (tot*(tot+1)/2)

        i = 0; ret2 = 0
        while i < len(A):
            tot = 0
            j = i
            while j < len(A) and A[j] <= L-1:
                tot += 1; j+= 1
            i = j+1
            ret2 += (tot*(tot+1)/2)
        return int(ret-ret2)
        
                 
```