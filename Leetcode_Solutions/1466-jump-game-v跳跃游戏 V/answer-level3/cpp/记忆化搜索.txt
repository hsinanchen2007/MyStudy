### 解题思路
dp转移还是很好想的 dp[now]=max(dp[now],dp[next]+1);
这道题如果只能往左跳，很好解决，但这个是左右都可以跳，for去循环遍历能跳过的位置就显得麻烦了。
这个时候我们dfs去跳跃就很方便了
dfs搜索的时候，我们可以记录一下，每个点可以跳跃的最远位置，当遇到已经计算过的点时，就不用重复去计算了。


### 代码

```cpp
#define SZ(x) (int)x.size()
class Solution {
    int dp[(int)(1e4+5)];
public:
    int dfs(const vector<int>& arr, int d,int k){
        if(dp[k])return dp[k];
        for(register int i=k-1;i>=k-d;--i)
            if(i<0)break;
            else if(arr[i]<arr[k])dp[k]=max(dfs(arr,d,i)+1,dp[k]);
            else break;
        for(register int i=k+1;i<=min(SZ(arr)-1,k+d);++i)
            if(arr[i]<arr[k])dp[k]=max(dfs(arr,d,i)+1,dp[k]);
            else break;
        return dp[k];
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,0,sizeof dp);
        for(register int i=0;i<SZ(arr);dfs(arr,d,i++));
        return *max_element(dp,dp+SZ(arr))+1;
    }
};
```