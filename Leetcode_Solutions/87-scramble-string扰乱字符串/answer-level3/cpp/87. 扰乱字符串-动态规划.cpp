### 解题思路

if((rt[i][j][k] && rt[i+k][j+k][len-k]) || (rt[i][j+len-k][k] && rt[i+k][j][len-k]))
rt[i][j][len] = true;

执行用时 :56 ms, 在所有 C++ 提交中击败了26.38%的用户

### 代码

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m != n) return false;
        vector<vector<vector<bool>>> rt(m, vector<vector<bool>>(n, vector<bool>(m+1, false)));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(s1[i] == s2[j]){
                    rt[i][j][1] = true;
                }
            }
        }
        for(int len = 2; len < n+1; len++){
            for(int i = 0; i <= n-len; i++){
                for(int j = 0; j <= n-len; j++){
                    for(int k = 1; k < len; k++){
                        if((rt[i][j][k] && rt[i+k][j+k][len-k]) || (rt[i][j+len-k][k] && rt[i+k][j][len-k])){
                            rt[i][j][len] = true;
                            break;
                        }
                    }
                }
            }
        }
        return rt[0][0][m];
    }
};
```