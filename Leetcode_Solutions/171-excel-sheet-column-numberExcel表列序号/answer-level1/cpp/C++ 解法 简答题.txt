```
class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        long long tag = 1;
        for(int i=s.size()-1;i>=0;i--){
            int tp = s[i] - 'A' + 1;
            ret += tp * tag;
            tag *= 26;
        }
        
        return ret;
    }
};
```
