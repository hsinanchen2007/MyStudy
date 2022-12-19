```
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res=0;
        int max_=0;
        int n=customers.size();
        vector<int> pre(n+1,0);
        for(int i=0,i1=1;i<n;++i,++i1)
        {
            if(grumpy[i])
            {
                pre[i1]=pre[i]+customers[i];
            }
            else
            {
                res+=customers[i];
                pre[i1]=pre[i];
            }
            
            if(i1>=X)
            {
                max_=max(max_,pre[i1]-pre[i1-X]);
            }
        }

        return res+max_;
    }
};
```
