### 解题思路
计算矩阵每一行战力，以元组形式存储（战力，行号）
根据战力对元组进行排序
返回排序后列表前K项的行号

### 代码

```python3
class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        result = [(sum(mat[i]),i) for i in range(len(mat))]
        result.sort()
        return [i[1] for i in result[:k]]



```