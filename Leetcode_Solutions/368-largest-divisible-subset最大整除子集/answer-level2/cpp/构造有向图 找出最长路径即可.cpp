### 解题思路
1.元素从小到大排序
2.构造有向图； 如果当前元素i可以被元素j整除 则构造一条有向边：i->j； 利用next数组记录当前路径的下一个顶点
3.遍历有向图：从中找出最长路径 

### 代码

```cpp
class Solution {
public:
    //DAG最长路径问题 构造一个有向图 然后找到图中的最长路径 21：34
    vector<vector<int> > G;
    vector<int> dp;
    vector<int> next,ans;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return vector<int>();
        G = vector<vector<int> >(len,vector<int>(len,0));
        dp = vector<int>(len,1);
        next = vector<int> (len,-1);
        sort(nums.begin(),nums.end());
        //构造有向图
        for(int i=0;i<len;++i){
            for(int j=i+1;j<len;++j){
                if(nums[j]%nums[i]==0){
                    G[i][j] = 1;
                }
            }
        }
        int res = 0,st = 0;
        for(int k=0;k<len;++k){
            int tmp = DP(k,len);
            if(tmp>res){
                res = tmp;
                st = k;
            }
        }
        for(int t=st;t!=-1;){
            ans.push_back(nums[t]);
            t = next[t];
        }
        return ans;
    }
    int DP(int i,int n){ //dp[i] 记录从i号顶点出发所能到达的最大路径
        if(dp[i]!=1) return dp[i];
        int maxn = 1;
        for(int j=i+1;j<n;++j){//遍历所有边
            if(G[i][j]==1){
                int tmp = DP(j,n)+1;
                if(tmp>maxn){
                    maxn = tmp;
                    next[i] = j;
                }
            }
        }
        dp[i] = maxn;
        return dp[i];
    }
};
```
