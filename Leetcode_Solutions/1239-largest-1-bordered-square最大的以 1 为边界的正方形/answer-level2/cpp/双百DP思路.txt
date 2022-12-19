```
class Solution {//dp
public://执行用时 :20 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :10 MB, 在所有 C++ 提交中击败了100.00%的用户
    int i,j,k,t,m,n,res,len;
    int left[100][100];//表示此点（包括）向左有多少连续的1
    int up[100][100];//表示此点（包括）向上有多少连续的1
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        m = grid.size();n = grid[0].size();
        for(i=0;i<m;i++) {
             for(j=0;j<n;j++) {
                if(j&&grid[i][j-1]) left[i][j] = left[i][j-1] + grid[i][j]; 
                else left[i][j] = grid[i][j];
             }
        }
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                if(j&&grid[j-1][i]) up[j][i] = up[j-1][i] + grid[j][i];
                else up[j][i] = grid[j][i];
            }
        }
        for(i=0;i<m;i++) {
            for(j=0;j<n;j++) {
                if(grid[i][j]) {
                    len = min(left[i][j],up[i][j]);//找最小交接长度
                    k = i - len + 1;
                    t = j - len + 1;
                    while(k<=i-res) {//在大于最优长度的范围内寻找解
                        if(up[i][t]>=len&&left[k][j]>=len) {res = i-k+1;break;}
                        k++;t++;len--;
                    }
                }
            }
        }
        return res*res;
    }
};
```
