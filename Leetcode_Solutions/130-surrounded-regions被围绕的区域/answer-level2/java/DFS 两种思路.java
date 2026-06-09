### 解题思路
思路一：
首先求出联通的‘O’区域，用List来记录坐标，每当求出一个联通的‘O’区域，就判断list中是否有点在边界上，如果没有，就将这些点改为'X'。

思路二：
在探寻'O'联通区域时，对‘O’所在位置进行判断，如果在边界上，则返回false，并将visited[i][j]设置为-1，代表失败的点，其余点进行DFS探索联通区域时，遇到-1的点直接返回false。

代码为思路二

### 代码

```java
class Solution {
    public void solve(char[][] board) {
        if (board.length == 0)
            return;
        int[][] visited = new int[board.length][board[0].length];
        List<int[]> points = new ArrayList<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O'){
                    boolean dfs = dfs(board, i, j, visited, points);
                    if (dfs){
                        for (int[] point : points) {
                            board[point[0]][point[1]] = 'X';
                        }
                    }
                    else{
                        for (int[] point : points) {
                            visited[point[0]][point[1]] = -1;
                        }
                    }
                    points = new ArrayList<>();
                }
            }
        }
    }

    private boolean dfs(char[][] board,int i,int j,int[][] visited,List<int[]> list){
        //没有越界
        if (!(i < 0 || i >= board.length || j < 0 || j >= board[i].length)){
            if (visited[i][j] == -1)
                return false;
            //该点在边界上
            //边界上的O
            else if (i == 0 || i == board.length-1 || j == 0 || j == board[i].length-1){
                if (visited[i][j] == 0 && board[i][j] == 'O'){
                    visited[i][j] = 1;
                    list.add(new int[]{i,j});
                    return false;
                }
            }
            else if (visited[i][j] == 0 && board[i][j] == 'O'){
                visited[i][j] = 1;
                list.add(new int[]{i,j});
                if (dfs(board,i+1,j,visited,list) && dfs(board,i-1,j,visited,list)
                        && dfs(board,i,j+1,visited,list) && dfs(board,i,j-1,visited,list))
                    return true;
                return false;
            }
        }
        return true;
    }
}
```