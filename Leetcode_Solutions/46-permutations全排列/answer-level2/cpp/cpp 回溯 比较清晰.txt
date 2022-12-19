//回溯
//路径：记录在track中
//选择列表：nums中不存在于track中的元素
//结束条件：nums中的元素全部出现在track中
```
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return result;
    }
    void backtrack(vector<int> nums, vector<int> track) {
        if(track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        int nums_size = nums.size();
        for(int i = 0; i < nums_size; ++ i) {
            //如果nums[i]没有出现在track中，即可供选择
            if(find(track.begin(), track.end(), nums[i]) == track.end()) {
                track.push_back(nums[i]);
                backtrack(nums, track);
                track.pop_back();
            }
        }
    }
};
```
