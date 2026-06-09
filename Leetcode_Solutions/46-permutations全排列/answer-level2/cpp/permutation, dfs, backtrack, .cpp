#001#
今日打卡之经典题型:46 排列  
DFS, backtrack算法
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        //异常处理
        if(nums.empty()) return res;
        int n = nums.size();
        vector<int> subsets;
        //判断节点是否访问
        vector<bool> visited(n,false);
        //recursion
        dfs(nums, res, subsets,visited);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& subsets, vector<bool>& visited){
        //当访问节点数量等于需要排列数列的数量时,结束递归
        if(subsets.size() == nums.size()){
            //将此时的子集为排列结果之一
            res.push_back(subsets);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            //如果访问过当前节点,continue
            if(visited[i]) continue;
            //将访问的节点放入子集
            subsets.push_back(nums[i]);
            //将放入子集的节点标记为true,表示以访问
            visited[i] = true;
            dfs(nums, res, subsets, visited);
            //回溯,即将放入的节点移除,并将此节点访问状态改为false(表示将状态回溯为未访问前)
            subsets.pop_back();
            visited[i] = false;
        }
    }
};
```
打卡发布.如有错误,恳请指正!
