### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return n;
        vector<int> dp;
        int  len=1;
        dp.push_back(nums[0]);

        for(int i=0; i<n; ++i)
        {
            if(nums[i] > dp.back())
            {
                dp.push_back(nums[i]);
                len+=1;
            }
            else 
            {
                int p=findPos(dp, nums[i]);
                dp[p]=nums[i];
            }
        }

        return len;
    }

    int findPos(vector<int>& dp, int target)
    {
        int low=0, high=dp.size()-1;
        while(low+1 < high)
        {
            int mid=low+(high-low)/2;
            if(target>dp[mid] && target<=dp[mid+1]) return mid+1;
            else if(target == dp[mid]) return mid;
            else if(target > dp[mid]) low=mid;
            else high=mid;
        }
        if(target > dp[low]) return high;
        else return low;
    }
};
```