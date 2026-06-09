```
class Solution {
public:
    int rob(vector<int>& nums) {
        int s0=0;
        int s1=0;
        int s2=0;

        int n=nums.size();
        
        for(int i=0;i<n;++i)
        {
            int tmp=s0;
            s0=max(s1,s2)+nums[i];
            s2=s1;
            s1=tmp;
        }

        return max(s0,s1);
    }
};
```
