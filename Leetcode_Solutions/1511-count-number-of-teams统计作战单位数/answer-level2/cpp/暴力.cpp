暴力，双百。周赛的时候一直在找最大子序列，想错了。
```
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size(),cnt=0,flag=0;
        for(int i=0;i<n;i++)
        {   
            for(int j=i+1;j<n;j++)
            {   if(rating[j]>rating[i])
                {for(int k=j+1;k<n;k++)
                {
                    if(rating[k]>rating[j])
                    {cnt++;};
                }}
            }
        }
        for(int i=0;i<n;i++)
        {   
            for(int j=i+1;j<n;j++)
            {   if(rating[j]<rating[i])
                {for(int k=j+1;k<n;k++)
                {
                    if(rating[k]<rating[j])
                    {cnt++;};
                }}
            }
        }
        
        return cnt;
    }
};
```
