### 解题思路
动态规划（编辑距离的变种）

                if(t[i] == s[j]){
                    rt[i][j] = rt[i-1][j-1] + rt[i][j-1];
                }
                else{
                    rt[i][j] = rt[i][j-1];
                }

执行用时 :8 ms, 在所有 C++ 提交中击败了87.04%的用户
### 代码

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() == 0 && t.size() == 0) return 1;
        if(s.size() < t.size() || s.size() == 0 || t.size() == 0) return 0;
        int len_s = s.size();
        int len_t = t.size();
        vector<vector<long>> rt(len_t, vector<long>(len_s, 0));
        for(int i = 0; i < len_s; i++){
            if(i > 0){
                rt[0][i] = rt[0][i-1];
            }
            if(t[0] == s[i]){
                rt[0][i] += 1;
            }
        }
        for(int i = 1; i < len_t; i++){
            for(int j = 1; j < len_s; j++){
                if(t[i] == s[j]){
                    rt[i][j] = rt[i-1][j-1] + rt[i][j-1];
                }
                else{
                    rt[i][j] = rt[i][j-1];
                }
            }
        }
        return rt[len_t-1][len_s-1];
    }
};
```