class Solution {

    int[] dx={0,0,1,-1};
    int[] dy={1,-1,0,0};
    int row;
    int col;
    public int numEnclaves(int[][] A) {
        if(A==null || A.length==0)
            return 0;
        row=A.length;
        col=A[0].length;
        int ret=0;
        for(int i=0;i<row;i++){
            if(A[i][0]==1){
                helper(A,i,0);
            }
            if(A[i][col-1]==1)
            {
                helper(A,i,col-1);
            }
        }
        for(int i=0;i<col;i++){
            if(A[0][i]==1){
                helper(A,0,i);
            }
            if(A[row-1][i]==1){
                helper(A,row-1,i);
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(A[i][j]==1)
                    ret++;
            }
        }
        return ret;
    }
    public void helper(int[][] A,int i,int j){
        if(i<0 || i>=row || j<0 || j>=col || A[i][j]==0)
            return;
        A[i][j]=0;
        for(int k=0;k<4;k++){
            int x=dx[k]+i;
            int y=dy[k]+j;
            helper(A,x,y);
        }
    }
}