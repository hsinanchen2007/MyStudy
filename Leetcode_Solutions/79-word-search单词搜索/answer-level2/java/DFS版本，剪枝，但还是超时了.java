```
class Solution {
    public boolean isGood = false;

    public boolean exist(char[][] board, String word) {
        int M = board.length;
        int N = board[0].length;
        int[][] visit = new int[M][N];
        for(int i = 0;i<M;i++){
            for(int j = 0;j<N;j++){
                String pre = "";
                DFS(board,M,N,visit,i,j,pre,word);
            }
        }
        return isGood;
    }
    public void DFS(char[][] board,int M,int N,int[][] visit,int i,int j,String pre,String words){
        if(i<0||j<0||i>=M||j>=N){
            return;
        }
        if(visit[i][j]==1){
            return ;
        }
        String pre1 = pre + String.valueOf(board[i][j]);
        if(pre1.equals(words)){
            isGood = true;
            return ;
        }
        if(pre1.length()>words.length()||!words.startsWith(pre1)){//剪枝，但还是超时了
            return;
        }
        visit[i][j] = 1;
        DFS(board,M,N,visit,i+1,j,pre1,words);
        DFS(board,M,N,visit,i-1,j,pre1,words);
        DFS(board,M,N,visit,i,j+1,pre1,words);
        DFS(board,M,N,visit,i,j-1,pre1,words);
        visit[i][j] = 0;
    }
}
```
