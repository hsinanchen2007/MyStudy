1. 偷懒直接计算。
$$
f(n,x) = \sum_{i=1}^{6}\frac{f(n-1,x-i)}{6}
$$
```c++
class Solution {
public:
    vector<double> twoSum(int n) {
        map<int,double> dp;
        vector<double> res;
        
        for(int i = 1; i <= 6; ++i){
            dp[i] = 1.0/6;
        }
        for(int i = 2; i <= n; ++i){
            map<int,double> curr;
            for(auto x : dp){
                for(int j = 1; j <= 6; ++j){
                    curr[x.first+j] += dp[x.first]*(1.0/6);
                }
            }
            dp = curr;
        }
        for(auto & x : dp){
            res.push_back(x.second);
        }

        return res;
    }
};
```