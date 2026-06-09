class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  
        vector<int> a;
        int n = nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                a.push_back(++i);
                a.push_back(++j);
                break;
            }
            else if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else{
                i++;
            }
        }
        return a;
    }
};