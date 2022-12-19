```
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
    int z_sum=0;
    int l=0;
    int r=X-1;
    int x,y;
    vector<int> sum;
    int c=0;
    for(int i=0;i<customers.size();++i)
    {
        if(grumpy[i]==1)
        {
            c+=customers[i];
        }
        sum.push_back(c);
    }
    while(r<customers.size())
    {
        if(l>0)
        {
             int temp=sum[r]-sum[l-1];
             if(temp>z_sum)
             {
                 z_sum=temp;
                 x=l;
                 y=r;
             }
            l++;
            r++;
        }
        else
        {
            int temp=sum[r];
             if(temp>z_sum)
             {
                 z_sum=temp;
                 x=l;
                 y=r;
             }
            l++;
            r++;
        }
    }
    int res=0;
    for(int i=0;i<customers.size();++i)
    {
        if(i<x || i>y)
        {
            if(grumpy[i]==0)
            {
               res+=customers[i];    
            }
        }
    }
    for(int i=x;i<=y;++i)
    {
        res+=customers[i];
    }
    return res;
    }
};
```
