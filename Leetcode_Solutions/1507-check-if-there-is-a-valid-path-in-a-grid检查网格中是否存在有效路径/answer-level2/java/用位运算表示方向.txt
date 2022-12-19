### 解题思路
用位运算表示方向，参考C++的那位用1，2，3，4表示方向的做法。详见注释

### 代码

```java
class Solution {
    public boolean hasValidPath(int[][] grid) {
        byte[] valid = new byte[7];
        valid[0] = 0;
        // 初始化数组，四位数分别表示，左、下、右、上是否可通，1可行，0不可通
        valid[1] = Integer.valueOf("1010",2).byteValue();
        valid[2] = Integer.valueOf("0101",2).byteValue();
        valid[3] = Integer.valueOf("1100",2).byteValue();
        valid[4] = Integer.valueOf("0110",2).byteValue();
        valid[5] = Integer.valueOf("1001",2).byteValue();
        valid[6] = Integer.valueOf("0011",2).byteValue();

        return dfs(grid,0,0,valid,-1);
    }

    private boolean dfs(int[][] grid, int i, int j, byte[] valid,int input) {
        //是否越界
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length) return false;
        int now = grid[i][j];
        // 标识当前已经走过，“锁上”，不能再经过，防止转圈
        grid[i][j]  = 0;
        byte numValid = valid[now];
        // 如果无路可走 ｜｜ 或者不是起点（-1），看与上个点有没有相接的入口
        if (numValid == 0 || (input != -1 && (numValid >> input & 1) != 1)){
                return false;
        }
        //找到终点
        if (i == grid.length -1 && j == grid[i].length - 1){
            return true;
        }
        // 四个方向，
        // 左边，右移0位 input肉眼观察，对应的就是右移2:右边
        if ((numValid & 1) == 1 && dfs(grid,i-1,j,valid,2)){
            return true;
        }
        // 下边，1位，input对应的就是3:上边 下面同理
        if ((numValid >> 1 & 1) == 1 && dfs(grid,i,j+1,valid,3)){
            return true;
        }
        if ((numValid >> 2& 1) == 1 && dfs(grid,i+1,j,valid,0)){
            return true;
        }
        if ((numValid >> 3& 1) == 1 && dfs(grid,i,j-1,valid,1)){
            return true;
        }
        // 这个点走完了，可以“释放掉”
        grid[i][j] = now;
        return false;
    }

};
```