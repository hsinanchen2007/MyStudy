### 解题思路
重点在于如何更新剩余nums.

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>list;
        dfs(list, 0, nums);
        return ret;
    }
    void dfs(vector<int>list, int num, vector<int> &nums){
        if(num==nums.size()) {
            ret.push_back(list);
            return;
        }
        for(int i=num; i < nums.size(); i++){
            list.push_back(nums[i]);
            swap(nums[i], nums[num]);
            dfs(list, num+1, nums);
            list.pop_back();
            swap(nums[i], nums[num]);
        }
        return;
    }
};
```