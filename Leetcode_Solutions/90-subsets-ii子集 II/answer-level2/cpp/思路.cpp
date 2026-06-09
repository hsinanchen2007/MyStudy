### 解题思路
        if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
          continue;
这一段是核心，好像之前哪个题目也做过类似的，主要是前面的如果没有访问，并且相等，就不要访问这个了

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
        if(i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
          continue;

        if(!visited[i]){
          visited[i] = true;
          tmp.push_back(nums[i]);
          dfs(nums, visited, i + 1, level);
          tmp.pop_back();
          visited[i] = false;
        }
      }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      res.push_back(tmp);

      if(nums.size() == 0)  return res;
      vector<bool> visited(nums.size(), false);
      sort(nums.begin(), nums.end());

      for(int i = 1; i <= nums.size(); i++){
        dfs(nums, visited, 0, i);
      }

      return res; 
    }
};
```