### 解题思路
最多2 ^ (m + n)个状态，我们利用位运算枚举状态即可

### 代码

```cpp
class Solution {
public:
    int minFlips(vector<vector<int>>& m) {
        int lenx = m.size();
        if(lenx == 0){
            return 0;
        }
        int leny = m[0].size();
        int allstatus = (1 << (lenx * leny)) - 1;
        int ans = 12345;
        vector<vector<int>> now;
        for(int s = 0; s <= allstatus; ++s){
            now = m;
            for(int i = 0; i < lenx; ++i){
                for(int j = 0; j < leny; ++j){
                    if((1 << (i * leny + j)) & s){
                        now[i][j] = now[i][j] ^ 1;
                        if(i > 0){
                            now[i - 1][j] = now[i - 1][j] ^ 1;
                        }
                        if(i < lenx - 1){
                            now[i + 1][j] = now[i + 1][j] ^ 1;
                        }
                        if(j > 0){
                            now[i][j - 1] = now[i][j - 1] ^ 1;
                        }
                        if(j < leny - 1){
                            now[i][j + 1] = now[i][j + 1] ^ 1;
                        }
                    }
                }
            }
            bool ok = true;
            for(int i = 0; i < lenx; ++i){
                for(int j = 0; j < leny; ++j){
                    if(now[i][j] == 1){
                        ok = false;
                    }
                }
            }
            if(ok){
                ans = min(ans, __builtin_popcount(s));
            }
        }
        return (ans == 12345 ? -1 : ans);
    }
};
```