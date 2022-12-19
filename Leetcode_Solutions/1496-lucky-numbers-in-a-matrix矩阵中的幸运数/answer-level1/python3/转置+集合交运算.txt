### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def luckyNumbers (self, matrix):
        lis1 = []
        lis2 = []
        for row in matrix:
            lis1.append(min(row))
        for column in list(map(list,zip(*matrix))):
            lis2.append(max(column))
        return list(set(lis1) & set(lis2))
        
        
```