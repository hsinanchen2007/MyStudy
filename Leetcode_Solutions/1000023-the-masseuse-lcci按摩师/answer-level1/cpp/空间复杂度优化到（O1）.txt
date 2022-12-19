巧妙的在向量第一个位置插入0，代码非常简洁，一行多余的都没有。

class Solution {
public:
    int massage(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        int len = nums.size();
        for(int i = 2; i < len; ++i){
            nums[i] = max( nums[i] + nums[i-2] , nums[i-1] );
        }
        return nums[len-1];
    }
};