看了大神们的分享，dfs bfs都试了一下，dfs快多了

### 代码

```java
class Solution {
    public char[][] updateBoard(char[][] table, int[] click) {
        if (table==null || table.length<=0 ||
                click[0]<0 || click[0]>=table.length ||
                click[1]<0 || click[1]>=table[0].length){
            return null;
        }
        // 记录是否被访问过
        boolean[][] visit = new boolean[table.length][table[0].length];

        dfs(table,click[0],click[1],visit);
        return table;
    }
    // 深度优先搜索
    private static void dfs(char[][] table, int x, int y, boolean[][] visit) {
        if (x<0 || x>=table.length || y<0 || y>=table[0].length || visit[x][y]){
            return;
        }
        // 标记当前位置走过
        visit[x][y] = true;
        // 点到地雷
        if (table[x][y]=='M'){
            table[x][y] = 'X';
            return;
        }
        int[][] directions = {
                {-1, 0},
                {-1, 1},
                { 0, 1},
                { 1, 1},
                { 1, 0},
                { 1,-1},
                { 0,-1},
                {-1,-1}
        };
        // 当前位置不是地雷， 8个方向搜索当前位置范围内地雷个数；
        int count = getDL(x,y,table,directions);
        // 有地雷 显示地雷个数 没有显示 'B'
        if (count!=0){
            table[x][y] = (char)('0'+count);
            return;
        }else {
            table[x][y] = 'B';
        }

        // 下个位置递归
        for (int i = 0; i < directions.length; i++) {
            int newx = x + directions[i][0];
            int newy = y + directions[i][1];
            if (check(table,newx,newy,visit)){
                dfs(table,newx,newy,visit);
            }
        }

    }

    // 判断当前位置是否合法，是否走过
    private static boolean check(char[][] table, int x, int y, boolean[][] visit) {
        if (x<0 || x>= table.length || y<0 || y>=table[0].length || visit[x][y]){
            return false;
        }
        return true;
    }

    // 查询当前位置范围内的地雷个数
    private static int getDL(int x, int y, char[][] table, int[][] directions) {
        int count = 0;
        for (int i = 0; i < directions.length; i++) {
            int newx = x + directions[i][0];
            int newy = y + directions[i][1];
            if (pd(newx,newy,table)){
                count++;
            }
        }
        return count;
    }
    // 判断当前位置是否合法，是不是地雷，是地雷返回true
    private static boolean pd(int x, int y, char[][] table) {
        if (x<0 ||x>=table.length || y<0 || y>=table[0].length || (table[x][y]!='M' && table[x][y]!='X')){
            return false;
        }
        return true;
    }
}
```