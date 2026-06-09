class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0,farav=0;i<nums.size()&&i<=farav;i++){
            farav=max(farav,nums[i]+i);
            if(farav>=nums.size()-1) return true;
        }
        return false;
    }
};