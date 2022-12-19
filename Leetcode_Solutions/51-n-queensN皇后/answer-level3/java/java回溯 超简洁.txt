
```
class Solution {

    char[][] g;

    boolean[] col;
    boolean[] pie;
    boolean[] la;
    int n ;

    List<List<String>> res ;

    public List<List<String>> solveNQueens(int n) {
       this.n = n;
       g = new char[n][n];
       col = new boolean[n];
       pie = new boolean[2*n];
       la = new boolean[2*n];
       res = new ArrayList();
       for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                g[i][j] = '.';
            }
        }
        dfs(0);
        return res;
    }
    /**
    跟全排列类似
    **/
    private void dfs(int u){
        if (u == n){
            List<String> item = new ArrayList<>();
            for (int i = 0; i < n; i++){
                item.add(new String(g[i]));
            }
            res.add(item);
            return;
        }
        
        for (int i = 0; i < n; i++){
            if (!col[i] && !pie[u + i] && !la[i -u + n]){//当前点可以选择皇后 （之前的列、正对角、斜对角都没有皇后）
                g[u][i] = 'Q';
                col[i] = pie[u + i] = la[i - u + n] = true;
                dfs(u + 1);
                g[u][i] = '.';
                col[i] = pie[u + i] = la[i - u + n] = false;
            }
        }
    }
  

}
```
