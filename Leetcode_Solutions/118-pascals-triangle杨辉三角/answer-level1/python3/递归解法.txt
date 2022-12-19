
通过numRows-1，求numRows行，递归求解
```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1],[1,1]]
        else:
            result = self.generate(numRows - 1)
            tmp = [1]
            length = len(result[-1])
            for i in range(length-1):
                tmp.append(result[-1][i]+result[-1][i+1])
            tmp.append(1)
            result.append(tmp)
            return result
```
