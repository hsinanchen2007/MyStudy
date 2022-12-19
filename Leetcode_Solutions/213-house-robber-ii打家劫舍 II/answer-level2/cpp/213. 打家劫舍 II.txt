```
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        int s0=0;
        int s1=0;
        int s2=0;

        
        for(int i=0;i<n-1;++i)
        {
            int tmp=s0;
            s0=max(s1,s2)+nums[i];
            s2=s1;
            s1=tmp;
        }

        int t0=0;
        int t1=0;
        int t2=0;
        
        for(int i=1;i<n;++i)
        {
            int tmp=t0;
            t0=max(t1,t2)+nums[i];
            t2=t1;
            t1=tmp;
        }
        
        return max(max(s0,s1),max(t0,t1));
    }
};
```
