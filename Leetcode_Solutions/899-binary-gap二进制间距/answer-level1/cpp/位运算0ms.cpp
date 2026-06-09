```
class Solution {
    public:
        int binaryGap(int N) {
            int n = 0;
            int res = 0;
            int ans = 0;
            while(N){
                if(!n){
                    n = N & (0 - N);
                }else{
                    res = max(res, (N & (0 - N)) / n / 2);
                    n = N & (0 - N);
                }
                N -= n;
            }
            while(res){
                res /= 2;
                ans ++;
            }
            return ans;
        }
};
```
