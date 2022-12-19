#002#
今日打卡之经典题型:78 子集
DFS, backtrack算法, 子集问题
```
//dfs一般套路做法
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;        
        vector<int> sub;
        dfs(nums, 0, sub, res);
        return res;
    }
    void dfs(vector<int>& nums, int index, vector<int>& sub, vector<vector<int>>& res){
        //所有可能子集,所以任何一种情况都需丢到res,共有2^n种情况
        res.push_back(sub);
        for(int i = index; i < nums.size(); i++){
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, res);
            sub.pop_back();
        }
    }
};
```
打卡发布.如有错误,恳请指正!
