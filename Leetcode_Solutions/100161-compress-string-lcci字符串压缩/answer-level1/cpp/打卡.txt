### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string ans = "";
        if(S == ""){
            return S;
        }
        int count = 1;
        char ch = S[0];
        for(int i = 1; i < S.length(); i++){
            if(ch == S[i]){
                count++;
            }else{
                ans += ch + to_string(count);
                count = 1;
                ch = S[i];
            }
        }
        ans += ch + to_string(count);
        int len = ans.length();
        if(len < S.length()){
            return ans;
        }else{
            return S;
        }
    }
};
```