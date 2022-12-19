写出来发现和官方题解思路一样，但是用一个数组来避免官方题解里的重复计算，速度打败100%
```
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        if(n==0)return -1;
        vector<int> sum(n+1);
        sum[0]=0;;
        for(int i=0;i<n;++i)
        {
            sum[i+1]=sum[i]+machines[i];
        }
        
        if(sum[n]%n)
        {
            return -1;
        }
        int avg=sum[n]/n;

        for(int i=0;i<=n;++i)
        {
            sum[i]-=avg*i;
        }
        
        int res=0;
        for(int i=0;i<n;++i)
        {
            if(sum[i]<0&& sum[i+1]>0)
            {
                res=max(res, abs(sum[i])+abs(sum[i+1]));
            }
            else
            {
                res=max(res,max(abs(sum[i]),abs(sum[i+1])));
            }
        }
        return res;
    }
};
```
