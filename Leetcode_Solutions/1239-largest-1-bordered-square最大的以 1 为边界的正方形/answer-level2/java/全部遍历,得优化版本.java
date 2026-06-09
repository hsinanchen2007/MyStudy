### 解题思路
从(0,0)->(row,col)逐一遍历,在每个点试图找到最大的返回.将当前的最大值传入查找方法,及时停止查找快速返回. 8ms/44.8mb

### 代码

```java
class Solution {

    public int largest1BorderedSquare(int[][] grid) {
        int max = 0;
        for(int row = 0 ; row < grid.length ; row ++){
            for(int col = 0 ; col < grid[row].length ; col ++){
                int squareArea = square(grid , row , col , max);
                max = max < squareArea ? squareArea : max;
            }
        }
        return max;
    }


    private int square(int[][] grid , int row , int col , int max){
        int rowNum = 0;
        int colNum = 0;

        for (int i = row; i < grid.length && grid[i][col] == 1; i++) {
            rowNum++;
        }
        for (int j = col; j < grid[row].length && grid[row][j] == 1; j++) {
            colNum++;
        }
        long max1 = Math.round(Math.sqrt(max)) ;
        int min = Math.min(rowNum , colNum);
        boolean end = false;
        while (!end && min>max1) {
            end = true;
            for (int i = 0; i < min; i++) {
                if (grid[i + row][col + min - 1] != 1) {
                    end = false;
                    min--;
                    break;
                }
                if (grid[row + min - 1][col + i] != 1) {
                    end = false;
                    min--;
                    break;
                }
            }
        }
        return min * min;
    }


}
```