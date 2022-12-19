**简单二分根据返回值检查搜索区间即可**
```
#define long long int
class Solution {
public:
    const int N=1000000;
    bool ok(int a, int t,vector<int>& n){
        int sum=0;
        for(int i=0;i<n.size();i++){
            if(n[i]%a!=0)sum+=n[i]/a+1;
            else
            sum+=n[i]/a;
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& n, int t) {
        int ans=INT_MAX;
        int l=1,r=N;
        while(l<=r){
            int mid=(l+r)>>1;
            if(ok(mid,t,n)){
                ans=min(ans,mid);
                r=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};
```
