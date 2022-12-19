# 题解
动态规划，从上到下，保存每一层每个位置的最小路径和。
## 动态规划
 1. 特判，若$triangle$为空，返回$0$，若只有一层$len(triangle)==1$，返回元素。
 2. 从第二行开始，遍历区间$[1,n)$：
 	* 对每一层的元素进行遍历，遍历区间$[0,len(triangle[i]))$，存在三种情况：
 		+ 每一行的首位，$triangle[i][j]+=triangle[i-1][j]$，等于上一行的相同索引处。
 		+ 每一行的末位，$triangle[i][j]+=triangle[i-1][j-1]$，等于上一行的前一位处。
 		+ 对于其他元素，$triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j])$，等于上一行中相邻的较小值加上自身。
 4. 返回最后一行中的最小路径和

### 复杂度分析
 - 时间复杂度：$O(n^{2})$，等差数列求和。
 - 空间复杂度：$O(1)$，借助自身保存结果。

### Python

```python
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if(not triangle):
            return 0
        n=len(triangle)
        if(n==1):
            return triangle[0][0]
        for i in range(1,n):
            for j in range(len(triangle[i])):
                if(j==0):
                    triangle[i][j]+=triangle[i-1][j]
                elif(j==len(triangle[i])-1):
                    triangle[i][j]+=triangle[i-1][j-1]
                else:
                    triangle[i][j]+=min(triangle[i-1][j-1],triangle[i-1][j])
        return min(triangle[-1])
```