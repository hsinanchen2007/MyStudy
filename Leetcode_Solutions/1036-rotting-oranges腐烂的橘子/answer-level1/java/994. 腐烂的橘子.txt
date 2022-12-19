### 解题思路
采用递归的思想。
1. 将每个腐烂的橘子看作一个起点，传染源的初始值num为2。
2. 开始模拟感染的过程，每次尝试感染上下左右方的橘子，若跳出单元格或遇到本就腐烂的橘子/空单元格，则该方向停止感染；若遇到新鲜橘子/此次传染时间更短，则将该格赋值为num+1，然后继续重复2.
3. 对每个腐烂橘子都模拟感染结束之后，遍历单元格找到最大值max。若仍存在新鲜橙子，返回-1；否则，返回经过的最小分钟数max-2。

### 代码

```java
class Solution {
    public int orangesRotting(int[][] grid) {
        // Map<Integer, Integer> rotMap = new HashMap<Integer, Integer>();      // 不能用map，因为行（Key）相同时，上一个值会被覆盖
        int MAXLEN = grid.length*grid[0].length;
        int[] rotRow = new int[MAXLEN];
        int[] rotCol = new int[MAXLEN];
        int time = 0;

        for(int i=0; i<grid.length; i++){       // 行
            for(int j=0; j<grid[0].length; j++){    //列
                if(grid[i][j] == 2){
                    // 存储腐烂橘子的行列
                    rotRow[time] = i;
                    rotCol[time] = j;
                    time++;
                    // System.out.println("rot put:"+i+" ; "+j);
                }
            }
        }

        for(int k=0; k<time; k++){
            // System.out.println("rot entry: "+rotRow[k]+" ; "+rotCol[k]);
            transRotting(grid, rotRow[k], rotCol[k], 2);
        }

        int max = 2;       // 最大分钟数
        boolean flag = false;       // 是否有新鲜橘子的标识
        
        for(int i=0; i<grid.length; i++){       // 行
            for(int j=0; j<grid[0].length; j++){    //列
                // System.out.println(grid[i][j]);
                if(grid[i][j] == 1){
                    flag = true;
                    break;
                }
                if(grid[i][j] > max){
                    max = grid[i][j];
                }
            }
        }

        if(flag == true)    return -1;
        else    return (max-2);

    }

    public void transRotting(int[][] grid, int row, int col, int num){
        // 传染正上方
        if(row-1>=0 && grid[row-1][col] != 0 && grid[row-1][col] != 2){     // 存在 && 不为0 && 不为2
            if(grid[row-1][col] == 1 || grid[row-1][col] > num+1){       // 新鲜 || 此次传染时间更短：更新时间
                grid[row-1][col] = num+1;
                transRotting(grid, row-1, col, num+1);
            }
        }
        // 传染正下方
        if(row+1<grid.length && grid[row+1][col] != 0 && grid[row+1][col] != 2){     // 存在 && 不为0 && 不为2
            if(grid[row+1][col] == 1 || grid[row+1][col] > num+1){       // 新鲜 || 此次传染时间更短：更新时间
                grid[row+1][col] = num+1;
                transRotting(grid, row+1, col, num+1);
            }
        }
        // 传染正左方
        if(col-1>=0 && grid[row][col-1] != 0 && grid[row][col-1] != 2){     // 存在 && 不为0 && 不为2
            if(grid[row][col-1] == 1 || grid[row][col-1] > num+1){       // 新鲜 || 此次传染时间更短：更新时间
                grid[row][col-1] = num+1;
                transRotting(grid, row, col-1, num+1);
            }
        }
        // 传染正右方
        if(col+1<grid[0].length && grid[row][col+1] != 0 && grid[row][col+1] != 2){     // 存在 && 不为0 && 不为2
            if(grid[row][col+1] == 1 || grid[row][col+1] > num+1){       // 新鲜 || 此次传染时间更短：更新时间
                grid[row][col+1] = num+1;
                transRotting(grid, row, col+1, num+1);
            }
        }
    }
}
```