@[TOC](303. 区域和检索 - 数组不可变（Range Sum Query - Immutable）)
# 题解


## 缓存+动态规划
同样借助于缓存的思想：
如图所示：
**若求蓝色区域内的元素和，等于蓝色区域右下角到$(0,0)$处的累加和去掉红色绿色和绿色部分的累加和。
红色部分+绿色部分=矩阵左上角$(0,0)$到红色部分右下角的累加和
黄色部分+绿色部分=矩阵左上角$(0,0)$到黄色部分右下角的累加和**
![在这里插入图片描述](https://pic.leetcode-cn.com/3bc77d43943fe3202aababb0f54d768244e6d66943862155fb8e84c38a7b2d36.png)
创建$dp$数组如下：
其中$dp[i][j]$表示矩阵左上角到$matrix[i-1][j-1]$的累加和。
因此可得蓝色区域的递推公式，设蓝色区域左上角索引$(row1,col1)$（21）和右下角索引$(row2,col2)$：
$dp[row2+1][col2+1]-dp[row2+1][col1]-dp[row1][col2+1]+dp[row1][col1]$


![在这里插入图片描述](https://pic.leetcode-cn.com/483a02fc1ee679eadcc294e2bc8e7ca09cafd1b42d4fdb8013673e1c617d1ec3.png)

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n^{2})$，每次查询只需要$O(1)$
 - 空间复杂度：$O(n^{2})$

### Python
```python
class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if(not matrix):
            return
        m=len(matrix)
        n=len(matrix[0])
        self.dp=[[0]*(n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                self.dp[i][j]=self.dp[i-1][j]+self.dp[i][j-1]+matrix[i-1][j-1]-self.dp[i-1][j-1]
        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.dp[row2+1][col2+1]-self.dp[row2+1][col1]-self.dp[row1][col2+1]+self.dp[row1][col1]
```


