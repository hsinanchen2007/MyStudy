最重要的思想就是回溯思想，因为每一行都会相互攻击，那么我们可以选择在每一行的0-N列中的某一列尝试放置皇后，若放置成功，继续放置尝试在下一行中的某一列中防止皇后，若放置失败，返回上一步。
还有一个比较巧妙的编程思想：同一条对角线(\\)上的row + col相等，同样的另一条对角线(/)上的row - col相等，因为我们是用数组来记录，row - col会出现负数的情况，所以我们加上N来保证不为负数。
```
class Solution {
    
    
    private int[] hills;// 对角线(\)
    private int[] dales;// 对角线(/)
    private int[] rows;// 第col列若放置了皇后则置为1，否则为0。比如rows[1]代表第一列已经放置过皇后了
    private int[] queens;// queens[row] = col:表示第row行的皇后放置在第col列
    private int N;// N皇后
    
    private List<List<String>> res;//记录结果
    
    public List<List<String>> solveNQueens(int n) {
        //对角线 row + col，最大可能为 (N - 1) + (N - 1) 所以需要开辟2 * N的空间
        hills = new int[n * 2];
        //对角线 row - col + N(因为可能是负数，所以加上N)，最大可能为 (N - 1) - 0 + N，所以同样开辟2 * N的空间
        dales = new int[n * 2];
        //记录列
        rows = new int[n];
        //记录皇后放置的位置
        queens = new int[n];
        res = new ArrayList<>();
        N = n;
        
        backtrack(0);
        
        return res;
    }
    
    //回溯算法
    private void backtrack(int row) {
        if (row == N) {
            addSolution();
            return;
        }
        //尝试在第row行的第0-N列放置皇后
        for (int col = 0; col < N; ++col) {
            if (isNotUnderAttack(row, col)) {
                placeQueen(row, col);
                backtrack(row + 1);
                removeQueen(row, col);
            }
        }
    }
    
    //尝试在第row行第col列放置皇后，放置成功返回true，放置失败返回false
    private boolean isNotUnderAttack(int row, int col) {
        //若要放置成功，需要列不冲突，两条对角线不冲突
        int res = rows[col] + hills[row + col] + dales[row - col + N];
        return res == 0;
    }
    
    //在第row行第col列放置皇后
    private void placeQueen(int row, int col) {
        //记录皇后在第row行第col列
        queens[row] = col;
        //记录col列已经放置了皇后，同样记录两条对角线
        rows[col] = hills[row + col] = dales[row - col + N] = 1;
    }
    
    //将第row行第col列的皇后移除
    private void removeQueen(int row, int col) {
        rows[col] = hills[row + col] = dales[row - col + N] = 0;        
    }
    
    //将结果记录起来
    private void addSolution() {
        List<String> list = new ArrayList<>();
        for (int row = 0; row < N; ++row) {
            StringBuffer sb = new StringBuffer();
            for (int col = 0; col < N; ++col) {
                if (queens[row] == col)
                    sb.append("Q");
                else
                    sb.append(".");
            }
            list.add(sb.toString());
        }
        res.add(list);
    }
}
```
