```
class Solution {
public:
    int smallestFactorization(int a) {
        long long ans = 0;
        long long n = 1;
        
        if( a < 10){
            return a;
        }
        
        for(int i = 9;i >= 2; --i){
            while(a%i == 0){
                ans = i*n + ans;
                if(ans > INT_MAX){
                    return 0;
                }
                n = n*10;
                a = a/i;
            }
        }       
        
        if( a == 1){
            return ans;
        }
        
        return 0;
    }
};
```