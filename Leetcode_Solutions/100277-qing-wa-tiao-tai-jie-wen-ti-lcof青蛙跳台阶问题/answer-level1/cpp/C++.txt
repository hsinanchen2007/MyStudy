```
class Solution {
public:
    // 斐波那契数列
    int numWays(int n) {
        int t0 = 0;
        int t1 = 1;
        int t;
        for(int i=1; i<=n; ++i){
            t = t1;
            t1 = t1+t0;
            t1 %= int(1e9+7);
            t0 = t;
        }
        return t1;
    }
};
```
