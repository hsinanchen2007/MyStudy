class Solution {

    private boolean[] mainDia;// 主对角线
    private boolean[] minorDia;// 次对角线
    private boolean[] column;// 纵
    private int[] res;

    public int totalNQueens(int n) {
        mainDia = new boolean[2 * n];// 主对角线
        minorDia = new boolean[2 * n];// 次对角线
        column = new boolean[n];// 纵
        res = new int[1];
        for (int i = 0; i < n; i++)
            dfs(0, i, n);
        return res[0];
    }

    public void updateQueen(int i, int j, int n, boolean change) {
        mainDia[i + j] = change;
        minorDia[n + i - j] = change;
        column[j] = change;
    }

    public void dfs(int i, int j, int n) {
        if (mainDia[i + j] || minorDia[n + i - j] || column[j])
            return;
        if (i == n - 1) {
            res[0]++;
            return;
        }
        updateQueen(i, j, n, true);
        for (int x = 0; x < n; x++)
            dfs(i + 1, x, n);
        updateQueen(i, j, n, false);
    }
}