```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool s1=false;
        int st=0;
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i])
            {
                if(!s1)
                {
                    s1=true;
                    st=i;
                }
            }
            else
            {
                if(s1)
                {
                    res=max(res,i-st);
                    s1=false;
                }
            }
        }
        if(s1)
        {
            res=max(res,n-st);
        }

        return res;
    }
};
```
