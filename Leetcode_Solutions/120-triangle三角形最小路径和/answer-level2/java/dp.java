### 解题思路
子问题：从下往上看，第i层最小的值
状态方程；p[i,j]来表示第i层的值
状态转移方程：
从第i+1层到第i层的方程，p[i,j] = Math.min(p[i+1, j+1]+tri[i,j],p[i+1, j+1]+tri[i,j])

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
       
        if (triangle == null || triangle.size() == 0) {
            return 0;
        }
        int[][] p = new int[triangle.size()][triangle.size()];
        // 从最后一排开始
        
        for (int i=triangle.size()-1;i>=0;i--) {
            // 从当前行的第一个开始
            for (int j=0;j<i+1;j++) {
                // 最后一排特殊处理
                if (i == triangle.size()-1) {
                    p[i][j] = triangle.get(i).get(j);
                    continue;
                }
                // 一般情况处理
                p[i][j] = Math.min(triangle.get(i).get(j) + p[i+1][j], triangle.get(i).get(j)+p[i+1][j+1]);

            }
        }
        return p[0][0];
    }
}
```