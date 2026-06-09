### 解题思路
基本的二维动态规划问题。
有一点需要注意的是`i+1=j`的情况的处理，因为这种情况下s[i+1]~s[j]构不成子串。

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        if(N == 0) return 0;
        vector<vector<bool>> is_palindromic(N, vector<bool>(N, false));
        for(int i = 0; i < N; i++) is_palindromic[i][i] = true;
        for(int i = N-1; i >= 0; i--){
            for(int j = i+1; j < N; j++){
                if(s[i] == s[j] && (i+1 == j || is_palindromic[i+1][j-1])) is_palindromic[i][j] = true;
            }
        }
        int counter = 0;
        for(int i = 0; i < N; i++){
            for(int j = i; j < N; j++){
                counter += is_palindromic[i][j];
            }
        }
        return counter;
    }
};
```