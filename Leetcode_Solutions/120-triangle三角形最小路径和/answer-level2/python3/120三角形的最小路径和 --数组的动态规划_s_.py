### 解题思路
动态规划解题，直接在原数组上操作
#### special case:
```python3
if not triangle:return 0
m=len(triangle)
if m==1:return triangle[0][0]
```
#### 起始条件:
第一行的最小路径和为第一行元素
#### 转移方程：（从第二行开始遍历）
**1.位于行首**:最小路径和为当前元素+上层行首元素
**2.未与行未**：最小路径和为当前元素+上层行末元素
**3.其他位置**：最小路径和为当前元素+上层中最小的元素



### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        #动态规划
        if not triangle:return 0
        m=len(triangle)
        if m==1:return triangle[0][0]
        #res=[[0]*i for i in range(m)]
        #res[0]=triangle[0][0]
        for i in range(1,m):
            for j in range(len(triangle[i])):#遍历数组
                if j==0:#行首
                    triangle[i][j]+=triangle[i-1][j]
                elif j==len(triangle[i])-1:#行末
                    triangle[i][j]+=triangle[i-1][j-1]
                else:triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j])
        return min(triangle[-1]) 
        




```