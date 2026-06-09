```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,res,0);         //从数组的第0个位置开始递归
        return res;                 //将每个位置上的数与它之后的数依次交换
    }
    
    void helper(vector<int>& nums,vector<vector<int>>& res,int level) {
        int len = nums.size();
        if(level == len) {
            res.push_back(nums);
            return;   
        } 
        for(int i = level;i < len;i++) {
                if(i != level)                    //在每个位置上将该位置上的数和之后的数交换
                    swap(nums[i],nums[level]);
                helper(nums,res,level+1);         //进入数组的下一个位置
                if(i != level)                    //交换之后要交换回来，即回溯
                    swap(nums[i],nums[level]);
            }
        
    }
};
```
