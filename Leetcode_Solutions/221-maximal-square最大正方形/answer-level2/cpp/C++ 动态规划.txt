### 解题思路
执行用时 :20 ms, 在所有 C++ 提交中击败了64.08%的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int vlen = matrix.size();
        int hlen = matrix[0].size();
        int *dp = new int[vlen*hlen];
        int maxlen = 0;
        //初始化
        for (int i = 0; i<hlen; i++){
            dp[i] = matrix[0][i]-'0';
            if(dp[i]!=0){
                maxlen =1;
            }
        }
        for(int j = 0; j<vlen; j++){
            dp[j*hlen] = matrix[j][0]-'0';
            if(dp[j*hlen]!=0){
                maxlen = 1;
            }
        }

        
        for (int i = 1; i<vlen; i++){
            for (int j = 1; j< hlen; j++){
                if(matrix[i][j]-'0'==1){
                    dp[i * hlen + j] = mymin(dp[(i-1) * hlen + j],dp[i*hlen + j-1],dp[(i-1) * hlen + j - 1]) + 1;
                }
                else{
                    dp[i*hlen + j] = 0;
                }
                if (maxlen<dp[i * hlen + j]){
                    maxlen = dp[i * hlen + j];    
                }
            }
        }
        return maxlen*maxlen;
    }
    int mymin(int a,int b,int c){
        int temp = a<b?a:b;
        return c<temp?c:temp;
    }
};
```