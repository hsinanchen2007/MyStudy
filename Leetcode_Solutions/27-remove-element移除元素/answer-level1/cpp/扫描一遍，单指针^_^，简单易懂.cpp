class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int location=0;//用于移动元素
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val)nums[location++]=nums[i];
        }
        return location;
    }
};