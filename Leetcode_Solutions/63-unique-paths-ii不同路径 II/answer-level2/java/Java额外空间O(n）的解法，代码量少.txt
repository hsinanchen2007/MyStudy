### 解题思路
依旧可以使用上一题额外空间只使用O(n)的解法
首先可以为矩阵加一行虚拟行和一列虚拟列（助于理解），但额外空间只需要O(N)

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int n=obstacleGrid.length;
        int m=obstacleGrid[0].length;
        int[] counts=new int[m+1]; //加一列虚拟列
        counts[m-1]=1-obstacleGrid[n-1][m-1];
        for (int i=n-1;i>=0;i--){// 加一行虚拟行，从倒数第二行开始
            for (int j=m-1;j>=0;j--){ // 列也从倒数第二列开始(最右边是虚拟列）
                counts[j]=obstacleGrid[i][j]==1?0:counts[j]+counts[j+1];
            }
        }
        return counts[0];
    }
}
```