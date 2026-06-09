在上一个题的基础上增添了hash去重的判断
hash查表中增加了10个偏移量 来解决负数的情况

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        if(size == 0) return res;
        back(size,nums,res,0);
        return res;
    }
    void back(int size,vector<int>& nums,vector<vector<int>>& res,int i){
        int hash[20]={0};
        int j;
        if(i == size-1) {
            1. res.push_back(nums);
            return;
        }
        for(j=i;j<size;j++){
            if(hash[nums[j]+10]!=1){
                swap(nums[i],nums[j]);
                back(size,nums,res,i+1);
                swap(nums[i],nums[j]);
                hash[nums[j]+10]=1;
            }
        }
    }
};
