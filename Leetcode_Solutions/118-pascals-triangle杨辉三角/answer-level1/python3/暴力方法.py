### 解题思路
首先生成一个指定大小的数组用1填充，然后根据杨辉三角的递推关系f[i,j] = f[i-1][j-1] + f[i-1][j]对内部的元素进行填充，注意边缘的元素全部为1；结果通过，但是效率很慢，分析了一下，存在很多重复的计算，因为杨辉三角对称，所以计算左边的右边的结果也自动算出来了。可以优化一下

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        arrays = [[1]*(i+1) for i in range(numRows)]
        for i in range(numRows):
            for j in range(i+1):
                if i == 0 or (j==0 or j==i):
                    continue
                arrays[i][j] = arrays[i-1][j-1] + arrays[i-1][j]
        return arrays
```