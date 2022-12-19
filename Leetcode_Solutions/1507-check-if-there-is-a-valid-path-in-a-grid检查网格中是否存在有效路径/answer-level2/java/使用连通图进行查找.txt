

```
class Solution {
    public boolean hasValidPath(int[][] grid) {
        if(grid.length == 1 && grid[0].length == 1) return true;
        int[][] result = getNextPostion(grid[0][0]);
        grid[0][0] = 0;
        // 当前(0,0)的前后连同位置，开始进行查找
        return hasValidPath(grid, 0, 0, result[0][0], result[0][1]) || hasValidPath(grid, 0, 0, result[1][0], result[1][1]);
    }
    
    public boolean hasValidPath(int[][] grid, int preX, int preY, int curX, int curY){
        //边界点判断
        if(curX < 0 || curX >= grid.length || curY < 0 || curY >= grid[curX].length) return false;
        //得到当前位置的前后连同的位置信息
        int[][] result = getNextPostion(grid[curX][curY]);
        //避免重复查找
        grid[curX][curY] = 0;
        //判断当前的前面连同的位置是否符合要求
        if(curX + result[0][0] == preX && curY + result[0][1] == preY){
            //判断当前位置是否是最后位置
            if(curX == grid.length - 1 && curY == grid[curX].length - 1) return true;
            return hasValidPath(grid, curX, curY, curX + result[1][0], curY + result[1][1]);
        }
        //判断当前的后面连同的位置是否符合要求
        else if(curX + result[1][0] == preX && curY + result[1][1] == preY){
            //判断当前位置是否是最后位置
            if(curX == grid.length - 1 && curY == grid[curX].length - 1) return true;
            return hasValidPath(grid, curX, curY, curX + result[0][0], curY + result[0][1]);
        }
        return false;
    }
    
    //获得当前value的前一个位置的差值与下一个位置的差值
    public int[][] getNextPostion(int value){
        int[][] result = new int[2][2];
        switch(value){
            case 1:
                result[0][0] = 0;
                result[0][1] = -1;
                result[1][0] = 0;
                result[1][1] = 1;
                return result;
            case 2:
                result[0][0] = -1;
                result[0][1] = 0;
                result[1][0] = 1;
                result[1][1] = 0;
                return result;
            case 3:
                result[0][0] = 0;
                result[0][1] = -1;
                result[1][0] = 1;
                result[1][1] = 0;
                return result;
            case 4:
                result[0][0] = 1;
                result[0][1] = 0;
                result[1][0] = 0;
                result[1][1] = 1;
                return result;
            case 5:
                result[0][0] = 0;
                result[0][1] = -1;
                result[1][0] = -1;
                result[1][1] = 0;
                return result;
            case 6:
                result[0][0] = -1;
                result[0][1] = 0;
                result[1][0] = 0;
                result[1][1] = 1;
                return result;
        }
        return result;
    }
}
```
