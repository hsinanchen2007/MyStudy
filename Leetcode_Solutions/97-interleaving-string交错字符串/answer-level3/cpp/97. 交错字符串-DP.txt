### 解题思路

rt[i][j] = (s1[i-1] == s3[i+j-1] && rt[i-1][j]) || (s2[j-1] == s3[i+j-1] && rt[i][j-1]);


动态规划

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != (s2.size() + s1.size())) return false;
        int len_s1 = s1.size();
        int len_s2 = s2.size();
        int len_s3 = s3.size();
        vector<vector<bool>> rt(len_s1 + 1, vector<bool>(len_s2 + 1, false));
        rt[0][0] = true;
        for(int i = 0; i < len_s2; i++){
            if(s2[i] == s3[i]) rt[0][i+1] = rt[0][i];
        }
        for(int i = 0; i < len_s1; i++){
            if(s1[i] == s3[i]) rt[i+1][0] = rt[i][0];
        }
        for(int i = 1; i < len_s1+1; i++){
            for(int j = 1; j < len_s2+1; j++){
                // if(s1[i] == s3[i+j]) rt[i][j] = rt[i-1][j];
                // if(s2[j] == s3[i+j]) rt[i][j] = rt[i][j-1];
                rt[i][j] = (s1[i-1] == s3[i+j-1] && rt[i-1][j]) || (s2[j-1] == s3[i+j-1] && rt[i][j-1]);

            }
        }
        return rt[len_s1][len_s2];
    }
};
```