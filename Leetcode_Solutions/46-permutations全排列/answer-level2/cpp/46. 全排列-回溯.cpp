### 解题思路
1、框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

2、track值传递、find函数、pop_back()

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> track){
        if(track.size() == nums.size()){
            res.push_back(track);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(find(track.begin(), track.end(), nums[i]) == track.end()){
                track.push_back(nums[i]);
                backtrack(nums, track);
                track.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return res;
        int n = nums.size();
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
};
```