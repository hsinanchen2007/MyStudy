### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minIncrementForUnique(self, A: List[int]) -> int:
        sort_L = sorted(A)
        count = 0
        for i in range(1, len(sort_L)):
            if sort_L[i]<=sort_L[i-1]:
                count += sort_L[i-1]+1-sort_L[i]
                sort_L[i] = sort_L[i-1]+1
        return count



```