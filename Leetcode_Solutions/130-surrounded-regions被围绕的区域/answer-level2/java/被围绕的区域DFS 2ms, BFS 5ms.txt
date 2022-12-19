### 解题思路
1. 根据题目的提示，可以想到将边界相关的O点找到，然后其余的O点置为X。
2. 具体找O点的做法是利用flag数组保存边界相关的O点，探索方法有DFS和BFS，具体实现如下。
3. DFS比BFS要快，可能因为BFS代码没有优化到位。

### 代码

```java
class Solution {
    private int[][] direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public void solve(char[][] board) {
        if(board == null || board.length == 0 || board[0].length == 0) return;
        int row = board.length, col = board[0].length;
        boolean[][] flag = new boolean[row][col];

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++){
                if(i != 0 && j != 0 && i != row-1 && j != col-1) continue;
                if(board[i][j] == 'O' && !flag[i][j]) DFS(i, j, board, flag);
            }
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(!flag[i][j]) board[i][j] = 'X';
    }

    private void DFS(int newx, int newy, char[][] board, boolean[][] flag){
        int row = board.length, col = board[0].length;
        if(newx >= 0 && newx < row && newy >= 0 && newy < col && !flag[newx][newy] && board[newx][newy] == 'O'){
            flag[newx][newy] = true;
            for(int k = 0; k < 4; k++)
                DFS(newx+direct[k][0], newy+direct[k][1], board, flag);
        }
    }

    private void BFS(int i, int j, char[][] board, boolean[][] flag){
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        flag[i][j] = true;
        int row = board.length, col = board[0].length;
        queue.offer(new Pair(i, j));
        while(!queue.isEmpty()){
            Pair<Integer, Integer> pair = queue.poll();
            int x = pair.getKey(), y = pair.getValue(), newx, newy;
            for(int k = 0; k < 4; k++){
                newx = x + direct[k][0];
                newy = y + direct[k][1];
                if(newx >= 0 && newx < row && newy >= 0 && newy < col && !flag[newx][newy] && board[newx][newy] == 'O'){
                    flag[newx][newy] = true;
                    queue.offer(new Pair(newx, newy));
                }
            }
        }
    }
}
```