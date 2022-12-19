击败98%……这题不难啊。
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int n1=n-1;
        int nmax=0;
        for(int i=0;i<n;++i)
        {
            if(i<=nmax)
            {
                nmax=max(nmax,i+nums[i]);
                if(nmax>=n1)return true;
            }
            else
            {
                return false;
            }
        }
        if(nmax>=n1)return true;
        else return false;
    }
};
```
