
### 解题思路
这个题目就是一个多重背包的变形。区别是：多重背包的问“最多能装多少”，这个题问“刚好装这么多的时候，如何组合？”
套用多重背包模板，把所有组合用c_dict记录下来。

### 代码

```python3

import copy

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        n = target + 1
        c_dict = {}
        for i in range(n): 
            c_dict[i] = []

        for c in candidates: 
            if c>=n:
                continue
            c_dict[c].append([c])
            for i in range(n): 
                if c_dict[i]==[]:
                    continue 
                for k in c_dict[i]: 
                    if i+c>=n:
                        continue
                    nk = copy.deepcopy(k)
                    nk.append(c)
                    c_dict[i+c].append(nk)
                
        return c_dict[target]


```