```
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n=A.size();
        vector<int> sum(n+1,0);
        for(int i=0;i<n;++i)
        {
            sum[i+1]=sum[i]+A[i];
        }

        deque<int> d;
        int res=n+1;
        for(int i=0;i<=n;++i)
        {
            while(!d.empty()&&sum[i]<=sum[d.back()])
            {
                d.pop_back();
            }
            while(!d.empty()&&sum[i]-sum[d.front()]>=K)
            {
                res=min(res,i-d.front());
                d.pop_front();
            }
            d.push_back(i);
        }
        return res<=n?res:-1;
    }
};
```
