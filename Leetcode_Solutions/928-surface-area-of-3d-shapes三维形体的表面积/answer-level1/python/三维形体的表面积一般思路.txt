### 解题思路
算出每个单元格里的表面积，再减去与相邻单元格（行、列）重复的面积。
此代码没考虑[[1],[1,1]]这样的格式，不太严谨。


*为啥[[1,1]]的预期结果不是10啊？吓死菜菜了

![image.png](https://pic.leetcode-cn.com/c566a3977f4bdcfaf56b347f310d5b780695dd96a89719f7743f8f346caf3473-image.png)


### 代码

```python3
class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        '''
        对单个单元格来说表面积是            6n-2*(n-1)=4n+2  n!=0
        对相邻的单元格来说重复的表面积是    2*min(a,b)
        '''
        i=0
        results=0
        while i <len(grid):
            j=0
            while j <len(grid[i]):
                if grid[i][j]>0:                               #排除n=0
                    results+=4*grid[i][j]+2
                    if j>0:                                         #行重合
                        results-=2*min(grid[i][j-1],grid[i][j])
                    if i>0:                                         #列重合
                        results-=2*min(grid[i-1][j],grid[i][j])
                j+=1
            i+=1
                
        return results
```