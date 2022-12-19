```
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i,j,m,n,s,s2,s1;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        if(nums.size()<4)
        {
            return ret;
        }
        int mini = target - (nums[nums.size()-1]+nums[nums.size()-2]+nums[nums.size()-3]);
        int maxi = target - (nums[i+1]+nums[i+2]+nums[i+3]);
        int last2 = nums[nums.size()-1]+nums[nums.size()-2];
        for(i=0; i<nums.size()-3; i++)
        {
            if(nums[i]<mini)
                continue;
            if(nums[i]>maxi)
                break;
            for(j=i+1; j<nums.size()-2; j++)
            {
                m = j+1;
                n = nums.size()-1;
                s2 = target - nums[i] - nums[j];
                if(last2 < s2)
                    continue;
                if(nums[m]+nums[m+1] > s2)
                    break;
                while(m<n)
                {
                    s = nums[m] + nums[n];
                    if(s == s2)
                    {
                        ret.push_back({nums[i], nums[j], nums[m], nums[n]});
                        do
                        {
                            m++;
                        }
                        while(m<n && nums[m] == nums[m-1]);
                    }
                    else if(s<s2)
                    {
                        do
                        {
                            m++;
                        }
                        while(m<n && nums[m] == nums[m-1]);
                    }
                    else
                    {
                        do
                        {
                            n--;
                        }
                        while(m<n && nums[n] == nums[n+1]);
                    }
                }
                while(j<nums.size()-2 && nums[j] == nums[j+1])
                    j++;
            }
            while(i<nums.size()-3 && nums[i] == nums[i+1])
                i++;
        }
        return ret;
    }
};```
