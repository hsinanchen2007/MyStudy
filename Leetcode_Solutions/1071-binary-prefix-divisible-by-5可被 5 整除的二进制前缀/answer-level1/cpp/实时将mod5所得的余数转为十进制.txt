实时将mod5所得的余数转为十进制
```
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int s = 0;
        for(auto n:A){
            s = s * 2 + n;
            s %= 5;
            res.push_back(s % 5 == 0);
        }
        return res;
    }
};
```
