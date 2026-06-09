### 解题思路
DFS

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> item;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size(); ++i) {
            if(i > 0 && i < nums.size() && nums[i] == nums[i-1]) {
                continue;
            }
            DFS(i, nums);
        }
        return res;
    }

    void DFS(int index, vector<int>& nums) {
        if (index == nums.size()) {
            res.push_back(item);
            return;
        }
        item.push_back(nums[index]);
        for(int i = index+1; i <= nums.size(); ++i) {
            if (i > index+1 && i < nums.size() && nums[i] == nums[i-1]) {
                continue;
            }
            DFS(i, nums);
        }
        item.pop_back();
    }
};
```