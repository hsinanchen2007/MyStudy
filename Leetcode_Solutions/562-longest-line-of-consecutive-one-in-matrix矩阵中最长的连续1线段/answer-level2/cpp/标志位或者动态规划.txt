```
class Solution {
public:
    static int idx(int x,int y,int colum){
        return x*colum + y;
    }
    
    int longestLine(vector<vector<int>>& M) {
        int r = M.size();
        if(r == 0){
            return 0;
        }
        
        int c = M[0].size();
        int res = 0;
        int visit[100001][4];
        
        
        
        /*flag:
          visit[i][0] : row
          visit[i][1] : colum
          visit[i][2] : diagonal
          visit[i][3] : back-diagona
         */
        memset(visit,0,sizeof(visit));
        for(int i = 0; i < r; ++i){
            for(int j = 0;j < c; ++j){                
                /*row*/
                if(M[i][j] == 1 && !visit[idx(i,j,c)][0]){
                    int k = j;
                    int cnt = 0;
                    while(k < c && M[i][k] == 1){
                        visit[idx(i,k,c)][0] = 1;
                        k++;
                        cnt++;
                    }
                    res = max(res,cnt);
                }
                /*colum*/
                if(M[i][j] == 1 && !visit[idx(i,j,c)][1]){
                    int k = i;
                    int cnt = 0;
                    while(k < r && M[k][j] == 1){
                        visit[idx(k,j,c)][1] = 1;
                        k++;
                        cnt++;
                    }
                    res = max(res,cnt);
                }
                /*diagonal*/
                if(M[i][j] == 1 && !visit[idx(i,j,c)][2]){
                    int m = i;
                    int n = j;
                    int cnt = 0;
                    while(m < r && n < c && M[m][n] == 1){
                        visit[idx(m,n,c)][2] = 1;
                        m++;
                        n++;
                        cnt++;
                    }
                    res = max(res,cnt);
                }
                /*back-diagona*/
                if(M[i][j] == 1 && !visit[idx(i,j,c)][3]){
                    int m = i;
                    int n = j;
                    int cnt = 0;
                    while(m < r && n >= 0 && M[m][n] == 1){
                        visit[idx(m,n,c)][3] = 1;
                        m++;
                        n--;
                        cnt++;
                    }
                    res = max(res,cnt);
                }
            }
        }
        
        return res;
    }
};
```