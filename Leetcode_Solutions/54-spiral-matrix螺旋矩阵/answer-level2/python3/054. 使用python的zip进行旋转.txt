### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            res += matrix.pop(0)
            #t('matrix1:', matrix)
            matrix = list(map(list, zip(*matrix)))[::-1]
            #print('matrix2:', matrix)
        
        return res
```