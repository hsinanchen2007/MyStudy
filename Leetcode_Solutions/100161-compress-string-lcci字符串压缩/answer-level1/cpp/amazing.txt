### 解题思路

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string res;
        int ans=1;
        for(int i=1;i<S.size();i++){
            if(S[i]==S[i-1]) ans++;
            else {
                stringstream ss;
                ss<<ans;
                res+=S[i-1]+ss.str();
                ans=1;
            }
        }
        stringstream ss;
        ss<<ans;
        res+=S[S.size()-1]+ss.str();
        if(res.size()>=S.size()) return S;
        else return res;
    }
};
```