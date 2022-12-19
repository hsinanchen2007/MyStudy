唉，竞赛时候没写完，一直在犹豫到底要不要暴力穷举。

暴力穷举是O(2^(mn))，线性方程是O(m^3n^3)。
```
class Solution {
public:
    void solve(vector<vector<int>>& board,vector<int>&pivot){
        int l=board.size();
        for(int j=0;j<l;j++){
            for(int i=0;i<l;i++){
                if(board[i][j]){
                    if(pivot[j]==-1){
                        if(find(pivot.begin(),pivot.end(),i)==pivot.end()){
                            pivot[j]=i;
                            i=-1;}
                        continue;
                    }else{
                        if(i!=pivot[j]){
                            for(int k=0;k<l+1;k++){
                                board[i][k]=(board[i][k]+board[pivot[j]][k])%2;
                            }
                        }
                    }
                }
            }
        }
    }
    int minFlips(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>board(m*n,vector<int>(m*n+1,0));
        for(int k=0;k<m*n;k++){
            board[k][m*n]=mat[k/n][k%n];
            board[k][k]=1;
            if(k%n!=0)board[k][k-1]=1;
            if(k-n>=0)board[k][k-n]=1;
            if(k%n!=n-1)board[k][k+1]=1;
            if(k+n<m*n)board[k][k+n]=1;
        }
        vector<int>pivot(board.size(),-1);
        solve(board,pivot);
        if(find(pivot.begin(),pivot.end(),-1)!=pivot.end())return -1;
        int ans=0;
        for(int k=0;k<m*n;k++){
            ans+=board[k][m*n];
        }
        return ans;
    }
};
```
