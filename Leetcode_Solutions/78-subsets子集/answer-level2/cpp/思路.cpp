### 解题思路
比较常规的，但是很难做到一次pass，有些细节还是需要debug一下
模板比较固定

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(vector<int> nums, vector<bool> &visited, int start, int level){
      if(tmp.size() == level){
        res.push_back(tmp);
        return;
      }

      for(int i = start; i < nums.size(); i++){
        if(!visited[i]){
          visited[i] = true;
          tmp.push_back(nums[i]);
          dfs(nums, visited, i + 1, level);
          tmp.pop_back();
          visited[i] = false;
        }
      }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
      res.push_back(tmp);

      if(nums.size() == 0)  return res;
      vector<bool> visited(nums.size(), false);

      for(int i = 1; i <= nums.size(); i++){
        dfs(nums, visited, 0, i);
      }

      return res;
    }
};
```