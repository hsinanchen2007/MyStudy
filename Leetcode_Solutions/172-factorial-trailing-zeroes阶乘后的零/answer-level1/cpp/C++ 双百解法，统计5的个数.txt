```
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int i=1;
        while(pow(5,i)<=n){
            res = res + n/(pow(5,i));
            i++;
        }
        return res;
    }
};
```
