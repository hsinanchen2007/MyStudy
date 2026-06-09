### 解题思路

```
result = []
def backtrack(选择列表，路径):
    if 满足结束条件:
        result.add(路径)
        return
    
    for 选择 in 选择列表:
        剪枝判断
        做选择
        backtrack(路径, 选择列表)
        撤销选择
```


先排序后剪枝

```
void backtrack(vector<int>& nums, vector<int> track, vector<int> rt){
        if(track.size() == nums.size()){
            res.push_back(rt);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            // 加入剪枝条件
            if(i > 0 && nums[i] == nums[i-1] && find(track.begin(), track.end(), i-1) == track.end()) continue;
            if(find(track.begin(), track.end(), i) == track.end()){
                track.push_back(i);
                rt.push_back(nums[i]);
                backtrack(nums, track, rt);
                track.pop_back();
                rt.pop_back();
            }
        }
    }
```

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> track, vector<int> rt){
        if(track.size() == nums.size()){
            res.push_back(rt);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && find(track.begin(), track.end(), i-1) == track.end()) continue;
            if(find(track.begin(), track.end(), i) == track.end()){
                track.push_back(i);
                rt.push_back(nums[i]);
                backtrack(nums, track, rt);
                track.pop_back();
                rt.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty()) return res;
        vector<int> track;
        vector<int> rt;
        sort(nums.begin(), nums.end());
        backtrack(nums, track, rt);
        return res;
    }
};
```