### 解题思路

- 回溯深度d
- 约束剪枝isValid
- 每轮的选择[0...N-1]


### 代码

```java
class Solution {
    char[][] board;
    List<List<String>> result = new ArrayList<>();
    int N;
    public List<List<String>> solveNQueens(int n) {
        // 初始化
        board = new char[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i][j] = '.';
            }
        }
        N = n;
        backtrack(board, 0);
        return result;
    }
    void backtrack(char[][] board, int depth){
        // 终止条件
        if(depth == board.length){
            ArrayList<String> tmp = new ArrayList<>();
            for(int i=0; i<board.length; i++){
                String s = String.valueOf(board[i]);
                tmp.add(s);
            }
            result.add(tmp);
            return;
        }
        for(int j=0; j<board.length; j++){
            // 是否满足约束, 进行剪枝
            if(!isValid(depth, j)){
                continue;
            }
            // 下一轮的回溯搜索
            board[depth][j] = 'Q';
            backtrack(board, depth+1);
            board[depth][j] = '.';
        }
    }
    boolean isValid(int d, int j){
        // 当前(d, j)为Q
        for(int i=0; i<d; i++){
            // 前面的d-1行的同一列不为Q
            if(board[i][j] == 'Q'){
                return false;
            }
            // 前面的d-1行的
            // (3,2), 则(2,1), (1,0)不能为Q  d-j = i - k ==> k = i-(d-j)
            if(0 <= i-d+j && i-d+j < N){
                if(board[i][i-d+j] == 'Q'){
                    return false;
                }
            }
            // (3,1), 则(2,2),(1,3)不能为Q  d+j = i+k ==> k = d+j-i
            if(0 <= d+j-i && d+j-i < N){
                if(board[i][d+j-i] == 'Q'){
                    return false;
                }
            }
        }
        return true;
    }
}
```