alpha-beta剪枝 强行过。。

```
class Solution {
public:
    int arr[101],sum[110],n;
    int work(bool isme,int sidx,int m,int curm,int low,int high)
    {
        if(sidx >= n) return curm;
        int res = isme ? low : high;
        if(isme) 
            for(int i=min(2*m,n-sidx);i>0;i--)
            {
                res = max(res,work(!isme,sidx+i,max(i,m),sum[sidx+i] - sum[sidx] + curm,res,high));
                if(res >= high) break;
            }
        else 
            for(int i=min(2*m,n-sidx);i>0;i--)
            {
                res = min(res,work(!isme,sidx+i,max(i,m),curm,low,res));
                if(res <= low) break;
            }
        return res;
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        sum[0] = 0;
        for(int i=0;i<n;i++) arr[i] = piles[i],sum[i+1] = sum[i] + arr[i];
        return work(true,0,1,0,-99999999,99999999);
    }
};
```
