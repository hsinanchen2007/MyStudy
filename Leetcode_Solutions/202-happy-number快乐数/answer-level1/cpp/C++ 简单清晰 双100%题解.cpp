```
class Solution {
public:
    bool isHappy(int n) {
        while(n>=10){
            n = next(n);
        }
        return n==1 || n==7;
    }
    
    int next(int n){
        int res = 0;
        while(n){
            int k = n%10;
            res += k*k;
            n /= 10;
        }
        return res;
    }
};
```
