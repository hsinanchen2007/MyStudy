```
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(auto i:s){
            res *= 26;
            res += (i-'@');
        }
        return res;
    }
};
```
