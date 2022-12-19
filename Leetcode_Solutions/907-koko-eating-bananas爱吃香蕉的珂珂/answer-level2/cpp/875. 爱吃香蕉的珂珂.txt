```
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n=piles.size();
        long low=1;
        long high=0;
        long sum=0;
        for(int i=0;i<n;++i)
        {
            sum+=piles[i];
            high=max(high,(long)piles[i]);
        }
        if(H<=n)return high;
        if(H>=sum)return 1;

        while(low<high)
        {
            long mid=(high+low)>>1;
            sum=0;
            float fmid=mid;
            for(int i=0;i<n;++i)
            {
                sum+=ceil(piles[i]/fmid);
            }
            if(sum>H)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return high;
    }
};
```
