### 解题思路
本人菜鸡，声音难听，画质垃圾，讲解混乱，勿喷我，觉得有用可以鼓励我一下点个赞。。
![...-53-22.mpeg4.aac.mp4](1b169e02-3169-4bfc-8a41-2b32ca2e9a2d)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur_an_res;
        int sum = 0;
        sort(candidates.begin(),candidates.end());

        dfs(cur_an_res,sum,0, candidates,target);
        return res;
    }
    void dfs(vector<int>& cur_an_res, int sum ,int i, vector<int> & candidates, int target){
        if(sum == target){
            res.push_back(cur_an_res);
            return ;
        }
        if(sum > target){
            return ;
        }
        // sum < target
        for(int j=i; j<candidates.size(); j++){
            cur_an_res.push_back(candidates[j]);
            sum += candidates[j];
            dfs(cur_an_res, sum, j, candidates, target);
            cur_an_res.erase(cur_an_res.end()-1);
            sum -= candidates[j];
        }
    }
};
```