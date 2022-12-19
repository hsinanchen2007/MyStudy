```
class Solution {
public:
    vector<bool>col,d,ud;
    int ans = 0,n ;
    int totalNQueens(int _n) {
        //依次枚举每一行皇后的位置
        //1.每一列只有一个皇后 col[N] 2. 每条斜线上只有一个皇后 d[2N] ud[2N] bool 
        //(x,y) x + y, x - y + n
        n = _n;
        col = vector<bool>(n);
        d = ud = vector<bool>(2 * n);
        dfs(0);
        return ans;
    }
    void dfs(int u){
        if(u == n){
            ans ++;
            return;
        }
        for(int i = 0; i < n; i++){
            if(!col[i] && !d[u + i] && !ud[u - i + n]){
                col[i] = d[ u + i] = ud[u - i + n] = true;
                dfs(u + 1);
                col[i] = d[u + i] = ud[u - i + n] = false;
            }
        }
    }
};
```
