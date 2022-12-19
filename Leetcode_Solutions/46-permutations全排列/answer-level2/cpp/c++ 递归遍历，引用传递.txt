### 解题思路
还可以优化，因为push_back()是有可能造成内存空间重分配的，可以考虑一开始就把temp的空间申请好

### 代码

```cpp
class Solution {
private:
    vector<bool> visited;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return vector<vector<int>>();
        visited.resize(nums.size(), false);
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(nums, temp, ans);
        return ans;
    }

    void dfs(const vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                dfs(nums, temp, ans);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }
};
```