class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i,re;
        for(i=0;i<nums.size();i++){
            if(nums[i]==target) return i;
            else continue;
        }
        for(i=0;i<nums.size();i++)
        {
            if((nums[i]<target&&i==nums.size()-1)||(nums[i]<target&&nums[i+1]>target))
              return (i+1);
            else if(nums[i]>target&&i==0)
              return i;
            else continue;
         }
         return re;
    }
};