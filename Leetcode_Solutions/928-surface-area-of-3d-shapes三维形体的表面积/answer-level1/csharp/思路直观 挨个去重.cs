![O7X(M}B`BM~G~GV137D1ENM.png](https://pic.leetcode-cn.com/f7ef917c419eed3990c1f35e6beee9eff1b80f052f659f242074263e2c4e2b53-O7X\(M%7DB%60BM~G~GV137D1ENM.png)

效率一般，主要是思路比较直观
思路：算出总的表面积 - 重复面积 = 真正的表面积
1. 总面积就是    高度（数组元素）* 1 * 4 + 2 * 1 这里需要用if判断一下如果高度为0的话直接跳过
2. 去重 我这里的话 每次判断右边和下边是否有方块 如果有的话选择较小的那个的高   高 * 1 * 2 （因为两个物体贴在一起有两个面）算出重合面积

```
public class Solution {
    public int SurfaceArea(int[][] grid) {
        int lenY = grid[0].Length;
        int lenX = grid.Length;
        int sum = 0;
        for(int i = 0; i < lenX; i++){
            for(int j = 0; j < lenY; j++){
                if(grid[i][j] != 0){
                    sum += grid[i][j] * 4 + 2;
                }
                if( j + 1 < lenY){ sum -= 2 * Math.Min(grid[i][j], grid[i][j+1]);}
                if( i + 1 < lenX){ sum -= 2 * Math.Min(grid[i][j], grid[i+1][j]);}
            }
        }

        return sum;
    }
}
```
