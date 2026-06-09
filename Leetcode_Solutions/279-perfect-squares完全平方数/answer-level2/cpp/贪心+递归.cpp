
dp的方法很多，但是贪心的简单递归没怎么看到，在优秀解法还看到一个数学定理（= =每次看到这个总有种奇怪的感觉，不是自己不好好学数学，关键这个也不是平常上课学的数学QAQ）。
这个题可以联想到cionchange（leetcode322）。用贪心的思路也是一样的，直觉想要最大的面额（平方数）来计算最少的纸张数（平方数的数目），在递归就可以了。
前面需要处理一下cion的数组。
```cpp
class Solution {
public:
    int mincount=numeric_limits<int>::max();
    int numSquares(int n) {
        vector<int> cion;
        for(int i=1;i*i<=n;i++){
            cion.push_back(i*i);
        }
        int size=cion.size();
        dfs(cion,n,0,size-1);
        return mincount;
    }
    void dfs(vector<int>& dp,int n,int count,int index){
        if(index<0||count+n/dp[index]>=mincount){return;}
        if(!(n%dp[index])){
            mincount=min(mincount,count+n/dp[index]);
            return;
        }
        for(int i=n/dp[index];i>=0;i--){
            dfs(dp,n-i*dp[index],count+i,index-1);
        }
    }
};
```