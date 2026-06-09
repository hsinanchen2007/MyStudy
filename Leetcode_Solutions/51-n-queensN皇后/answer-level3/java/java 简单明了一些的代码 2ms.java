```
class Solution {
    
    int []col; // 列
    int []diag; // 主对角线
    int []back_diag; // 副对角线
    char [][]board;
    List res;
    int bound; // 行数、列数
    public List<List<String>> solveNQueens(int n) {
        res=new ArrayList<List<String>>();
        bound=n;
        board=new char[n][n];
        col=new int[n];
        diag=new int[2*n-1];
        back_diag=new int[2*n-1];

        dfs(0);
        return res;
    }

    void dfs(int row){
        if(row==bound){
            List<String> list=new ArrayList<>();
            for(int i=0;i<bound;i++){
                /*字符数组转字符串后加到list */       
                list.add(new String(board[i])); 
            }
            res.add(list);
            return;
        }

        Arrays.fill(board[row],'.');
        for(int i=0;i<bound;i++){
            if(check(row,i)){
                board[row][i]='Q'; // 放置皇后
                col[i]=1;
                diag[row-i+bound-1]=1; //0-(n-1) 会出界 所以后面加n-1
                back_diag[row+i]=1;
                
                dfs(row+1); // 递归搜索下一行

                board[row][i]='.'; // 回溯
                col[i]=0;
                diag[row-i+bound-1]=0;
                back_diag[row+i]=0;
            }
        }
    }

    boolean check(int x,int y){
        if(col[y]==0&&diag[x-y+bound-1]==0&&back_diag[x+y]==0)
            return true;
        return false;
    }

}
```
