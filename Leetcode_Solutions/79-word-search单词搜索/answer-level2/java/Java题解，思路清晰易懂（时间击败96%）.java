**回溯算法，时间击败96%**

```
class Solution {
    public boolean exist(char[][] board, String word) {
        char[] arr = word.toCharArray();
        if (board.length == 0) return false;

        // 如果矩阵的元素个数比字符串中的字符数目要少，那么结果一定是找不到
        if (board.length*board[0].length < arr.length) return false;
        
        // visited数组记录深度优先遍历路径中已访问过的节点
        boolean[][] visited = new boolean[board.length][board[0].length];
        
        // 依次将矩阵中的每个点作为出发点，找到符合要求的路径则提前返回true
        for (int i=0; i<board.length; i++) {
            for (int j=0; j<board[0].length; j++) {
                if (dfs(board, visited, arr, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // 回溯遍历，从某个点出发，依次遍历左边，上面，右边，下面的点，如果某个递归返回了true，则可以剪枝，直接返回
    public boolean dfs(char[][] board, boolean[][] visited, char[] arr, int i, int j, int depth) {
        // 如果当前节点值不等于目标值，或者已访问过，则返回false
        if (board[i][j] != arr[depth] || visited[i][j]) {
            return false;
        }
        // 如果达到目标深度，且节点值等于目标值，则是符合要求的路径
        if (depth == arr.length-1) return true;
        
        // 访问当前节点
        visited[i][j] = true;
        
        // 依次递归访问当节点的左，上，右，下节点，如果有符合要求的，则提前返回
        if (i-1 >= 0) {
            if (dfs(board, visited, arr, i-1, j, depth+1)) return true;
        }
        if (j-1 >= 0) {
            if (dfs(board, visited, arr, i, j-1, depth+1)) return true;
        }
        if (i+1 < board.length) {
            if (dfs(board, visited, arr, i+1, j, depth+1)) return true;
        }
        if (j+1 < board[0].length) {
            if (dfs(board, visited, arr, i, j+1, depth+1)) return true;
        }
        // 返回上一层递归栈，需要将当前节点置为未访问过
        visited[i][j] = false;
        return false;
    }
}
```
