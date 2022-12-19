执行用时 : 16 ms, 在Jump Game的C++提交中击败了89.89% 的用户  
内存消耗 : 9.8 MB, 在Jump Game的C++提交中击败了87.30% 的用户 

核心思路：找到0，并向前检查能否跳过0


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        bool jump_out;
        for(int i = 0; i < l - 1; i++){
            if(nums[i]==0){
                jump_out = false;
                for(int j = 1; i - j >= 0; j++){
                    if(nums[i-j] > j)
                        jump_out = true;
                }
                if(jump_out == false)
                    return false;
            }
        }
        return true;
    }
};

