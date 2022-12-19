class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string s;
        int low,high,i,j=0,flag=1;
        for(i=0;i<nums.size()&&j<nums.size();)
        {
            low=i;
            flag=1;
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[j-1]==nums[j]-1)
                {
                    flag=0;
                    high=j;
                }
                else
                {
                    break;
                }
            }
            if(flag==1)
            {
                s=to_string(nums[low]);
                res.push_back(s);
            }
            else{
                s=to_string(nums[low])+"->"+to_string(nums[high]);
                res.push_back(s);
            }
            i=j;
        }
        return res;
    }
};