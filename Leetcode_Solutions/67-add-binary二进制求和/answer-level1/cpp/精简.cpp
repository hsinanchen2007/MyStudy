### 解题思路


### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans;
        int t = 0;
        for(int i = 0;i < a.size() || i < b.size();++i){
            if(i < a.size()) t += a[i] - '0';
            if(i < b.size()) t += b[i] - '0';
            ans += t % 2 + '0';
            t /= 2;
        }
        if(t) ans += t + '0';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```