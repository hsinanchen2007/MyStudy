```
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size();
        if((!a && !b && !s3.empty()) || a+b != s3.size()){
            return false;
        }
        vector<vector<bool>> m(a+1,vector<bool>(b+1,false));
        m[0][0] = true;
        for(int i = 1; i <= b; ++i){
            if(s3[i-1] == s2[i-1]){
                m[0][i] = true;
                continue;
            }
            break;
        }
        for(int i = 1; i <= a; ++i){
            if(s3[i-1] == s1[i-1]){
                m[i][0] = true;
                continue;
            }
            break;
        }
        for(int i = 1; i <= a; ++i){
            for(int j = 1; j <= b; ++j){
                if((m[i][j-1] && s2[j-1] == s3[i+j-1]) || (m[i-1][j] && s1[i-1] == s3[i+j-1])){
                    m[i][j] = true;
                }
            }
        }
        return m[a][b];
    }
};
```
