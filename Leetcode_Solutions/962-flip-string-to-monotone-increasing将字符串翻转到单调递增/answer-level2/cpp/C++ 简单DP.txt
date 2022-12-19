```
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int res_0=0,res_1=0;
        for(char c:S) {
            if(c=='0') {
                res_1=min(res_0+1, res_1+1);
            }else {
                res_1=min(res_1, res_0);
                res_0=res_0+1;
            }
        }
        return min(res_1,res_0);
    }
};
```
