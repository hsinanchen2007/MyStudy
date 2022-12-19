### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def oneEditAway(self, first: str, second: str) -> bool:
        size1 = len(first)
        size2 = len(second)
        if first == second : return True
        ls = [[0 for _ in range(size2+1)] for _ in range(size1+1)]
        for i in range(size1+1):
            ls[i][0] = i
        for i in range(size2+1):
            ls[0][i] = i
        for i in range(1,size1+1):
            for j in range(1,size2+1):
                n = 0 if first[i-1] == second[j-1] else 1
                ls[i][j] = min(ls[i-1][j-1]+n,ls[i][j-1]+1,ls[i-1][j]+1)
        return ls[-1][-1] <= 1
```