### 解题思路
使用两个dp表格，dpr[i][j]代表i,j处为尾的最长连续1的行长度，dpc[i][j]代表i,j为尾的最长列长度，知道了这两个值后，可以推出复杂度为O(N^3)的解法。

假设有一个连续1的片段形状较为奇特，如下:
``` 
        1
        1
        1
      1 1
    1 1 1
    1 1 1
1 1 1 1 1
1 1 1 1 1 <-位置i,j
```

那么可使用(O(N)的复杂度求解这个1块可能组成的矩形面积最大值，具体方式为从最右下角向上遍历，当列长度小于之前的列长度时，就表示一个新的矩形组成了，由此基于之前的矩形面积计算新的矩形面积,具体思路见代码注释处。

### 代码

```cpp
using namespace std;

class Solution{
    public:
        int maximalRectangle(vector<vector<char>>& mc){
            if(!mc.size() || !mc[0].size()) return 0;
            vector<vector<int>> matrix(mc.size(), vector<int>(mc[0].size()));
            vector<vector<int>> dpr(matrix.size(), vector<int>(matrix[0].size(),0));
            vector<vector<int>> dpc(matrix.size(), vector<int>(matrix[0].size(),0));
            for(int i=0;i<mc.size();i++){
                for(int j=0;j<mc[0].size();j++) matrix[i][j] = mc[i][j] == '1';
            }
            int res = matrix[0][0];
            dpr[0][0] = matrix[0][0];
            dpc[0][0] = matrix[0][0];
            for(int i=1;i<matrix[0].size();i++){
                dpc[0][i] = matrix[0][i];
                dpr[0][i] = matrix[0][i]*(dpr[0][i-1] + 1);
                res = max(res, max(dpc[0][i], dpr[0][i]));
            }
            for(int i=1;i<matrix.size();i++){
                dpr[i][0] = matrix[i][0];
                dpc[i][0] = matrix[i][0]*(dpc[i-1][0] + 1);
                res = max(res, max(dpr[i][0], dpc[i][0]));
            }
            for(int i=1;i<matrix.size();i++){
                for(int j=1;j<matrix[0].size();j++){
                        dpr[i][j] = matrix[i][j]*(dpr[i][j-1] + 1);
                        dpc[i][j] = matrix[i][j]*(dpc[i-1][j] + 1);
                        int c = dpc[i][j];
                        int t = dpr[i][j];
                        int ll = t;
                        int a = 0;
                        // 计算以i,j为右下角的1块所有可能的矩形面积
                        for(int k=1;k<=c;k++){
                            a += ll;
                            if(dpr[i-k+1][j] < ll){
                                a -= (ll - dpr[i-k+1][j])*k;
                                ll = dpr[i-k+1][j];
                            }
                            res = max(res, a);
                        }
                        /* cout << "i: " << i << "j:" << j << "area: " << tmp << "k: " << k << "t: " << t << endl; */
                }
            }
            return res;
        }
};

```