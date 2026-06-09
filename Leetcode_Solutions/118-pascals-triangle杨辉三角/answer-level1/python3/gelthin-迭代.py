### 解题思路
没有官方题解写得好

官方题解写的简洁精炼。

而我增加了很多特殊情况的处理。相当于是补丁。

忘了判断 numRows, 导致第一次提交错误。

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        result = [[1]]
        if numRows == 1:
            return result
    
        for i in range(1, numRows):
            result.append([1])
            j, k = 0, 1
            while k < len(result[i-1]):
                result[i].append(result[i-1][j]+result[i-1][k])
                j += 1
                k += 1
            result[i].append(1)
        return result
        


```