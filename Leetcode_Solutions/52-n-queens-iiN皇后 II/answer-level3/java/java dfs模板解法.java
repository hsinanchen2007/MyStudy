```
class Solution {
    int [][]board;
    int []col; // 列
    int []diag; // 主对角线
    int []back_diag; // 副对角线
    int res;
    int bound;
    public int totalNQueens(int n) {
        bound=n;
        res=0;
        col=new int[n];
        diag=new int[2*n-1];
        back_diag=new int[2*n-1];

        dfs(0);
        return res;
    }
    void dfs(int row){
        if(row==bound){
            res++;
            return;
        }
        for(int i=0;i<bound;i++){
            if(check(row,i)){
                col[i]=1;
                diag[row-i+bound-1]=1; //0-(n-1) 会出界 所以后面加n-1
                back_diag[row+i]=1;
                dfs(row+1);

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
