### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.length());
        int len = S.length();
        for(int i = 0; i < S.length(); i++){
            if(S[i] == C){
                len = 0;
                res[i] = len;
            }
            else{
                len++;
                res[i] = len;
            }
        }
        len = S.length();
        for(int i = S.length() - 1; i >= 0; i--){
            if(S[i] == C){
                len = 0;
                res[i] = len;
            }
            else{
                len++;
                res[i] = min(len, res[i]);
            }
        }
        return res;
    }
};
```