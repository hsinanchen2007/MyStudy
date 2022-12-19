### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int n = S.length();
        char c = S[0];
        int cnt = 1;
        string ret="";
        for (int i = 1;i<n;i++){
            if(S[i]!=c){
                ret+=c;
                ret+=to_string(cnt);
                c = S[i];
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        ret+=c;
        ret+=to_string(cnt);
        if(ret.length()>=n){
            return S;
        }
        return ret;
    }
};
```