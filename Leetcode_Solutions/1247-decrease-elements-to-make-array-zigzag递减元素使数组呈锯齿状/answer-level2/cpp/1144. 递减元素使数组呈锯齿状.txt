
```
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size();
        int res1=0;
        int res2=0;

        for(int i=0;i<n;i+=2)
        {
            int left=(i==0)?INT_MAX:nums[i-1];
            int right=(i==n-1)?INT_MAX:nums[i+1];
            res1+= max(0,nums[i]-min(left,right)+1);
        }

        for(int i=1;i<n;i+=2)
        {
            int left=nums[i-1];
            int right=(i==n-1)?INT_MAX:nums[i+1];
            res2+= max(0,nums[i]-min(left,right)+1);
        }

        return min(res1,res2);
    }
};
```
