### 解题思路
- 将下一行向上一行累积，最后返回结果；
- 下一行比上一行多1个元素，因此索引不会超出范围；

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
        return triangle[0][0]
```