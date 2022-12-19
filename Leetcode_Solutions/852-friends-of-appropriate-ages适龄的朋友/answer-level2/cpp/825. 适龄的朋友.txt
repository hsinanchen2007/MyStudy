```
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> counter(121,0);
        for(int age : ages )
        {
            ++counter[age];
        }

        int res=0;
        for(int i=1;i<121;++i)
        {
            if(counter[i])
            {
                int age_min=int(0.5*i)+8;
                int age_max=i;

                for(int j=age_min;j<=age_max;++j)
                {
                    if(counter[j])
                    {
                        if(i==j)
                        {
                            res+=counter[i]*(counter[i]-1);
                        }
                        else
                        {
                            res+=counter[i]*counter[j];
                        }
                    }
                }
            }
        }

        return res;
    }
};
```
