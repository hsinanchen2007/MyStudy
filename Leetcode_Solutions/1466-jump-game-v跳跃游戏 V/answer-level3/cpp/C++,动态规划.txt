```
const int maxn=1e5;
int idx[maxn];
vector<int>res;
inline bool cmp(int a,int b){
    return res[a]<res[b];
}
class Solution {
public:
//是一种简单的dp,但是难度大的是想到思路
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        res=arr;//将数组arr复制给res
        for(int i=0;i<n;i++)idx[i]=i;
        sort(idx,idx+n,cmp);//为了方便后面的处理
        int ans=1;
        int dp[maxn]={0};
        for(int k=0;k<n;k++){
            int num=idx[k];
            dp[num]=1;
            for(int j=num-1;j>=0&&num-j<=d;j--){
                if(arr[j]>=arr[num])break;
                dp[num]=max(dp[j]+1,dp[num]);
            }
            for(int j=num+1;j<n&&j-num<=d;j++){
                if(arr[j]>=arr[num])break;//因为之前已经排序过了
                dp[num]=max(dp[j]+1,dp[num]);
            }
            ans=max(ans,dp[num]);

        }
        return ans;
    }
};
```
