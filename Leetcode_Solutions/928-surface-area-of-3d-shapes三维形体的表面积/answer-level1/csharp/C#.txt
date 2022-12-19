### 解题思路
此处撰写解题思路

### 代码

```csharp
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