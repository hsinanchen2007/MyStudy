```
class Solution {
    vector<int> dp;//缓存结果，减小重复计算
public:
    int numTrees(int n) {
        dp.resize(n,0);
        return numTrees(1,n);
    }
    int numTrees(int start,int end) {
        if(start>=end)return 1;
        if(dp[end-start]>0)return dp[end-start];
        int res=0;
        for(int i=start;i<=end;++i){
            res+=numTrees(start,i-1)*numTrees(i+1,end);
        }
        dp[end-start]=res;
        return res;
    }
};
```
