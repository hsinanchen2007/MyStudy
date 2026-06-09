class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> Map;
        for(int i=0;i<nums.size();i++){
            Map[nums[i]]++;
            if(Map[nums[i]]>nums.size()/2) return nums[i];
        }
        return 0;
    }
};