首先思路就是枚举效率的最小值，可以先对效率从小到大排序。
对于每次选择一个效率值，必须找到后面的（k-1）大的速率值，可以用堆维护。
因为最多可以选择k个，只有后k个最大的效率值，才可以这样，其他情况必选k个。

```
class Solution {
public:
    const int mod=1e9+7;
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        pair<int,int>p[n+2];
        long long sum=0,ans=0;
        for(int i=1;i<=n;i++)p[i]={-e[i-1],-s[i-1]};
        sort(p+1,p+1+n);
        priority_queue<int>q;
        for(int i=1;i<=n;i++){
            if(i<=k){
                sum-=p[i].second;
                q.push(p[i].second);
                ans=max(ans,sum*(-p[i].first));
            }else{
                int t=q.top();
                q.pop();
                sum+=t-p[i].second;
                q.push(p[i].second);
                ans=max(ans,sum*(-p[i].first));
            }
        }
        return ans%mod;
    }
};
```
