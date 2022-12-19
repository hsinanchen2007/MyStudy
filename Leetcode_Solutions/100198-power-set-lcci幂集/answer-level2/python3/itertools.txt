### 解题思路
用到itertools中的combinations函数进行组合，注意combinations要给出组合个数
itertools中还有全排列函数permutations

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        from itertools import combinations
        L=len(nums)
        List=[]
        Listemp=[]
        for i in range(L+1):
            Listemp += list(combinations(nums,i))
        for j in Listemp:
            List.append(list(j))
        return List
```