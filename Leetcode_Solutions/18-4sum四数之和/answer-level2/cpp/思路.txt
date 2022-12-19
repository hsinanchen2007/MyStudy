### 解题思路
和三数和一样的 套框架就好了

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      vector<vector<int>> res;
      if(nums.size() < 3) return res;
      sort(nums.begin(), nums.end());

      for(int i = 0; i < nums.size() - 3; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for(int j = i + 1; j < nums.size() - 2; j++){
          if(j > i + 1 && nums[j] == nums[j - 1]) continue;

          int x = j + 1, y = nums.size() - 1;
          while(x < y){
            if(nums[i] + nums[j] + nums[x] + nums[y] == target){
              res.push_back({nums[i], nums[j], nums[x], nums[y]});
              while(nums[x] == nums[x + 1] && x + 1 < y)
                x++;
              while(nums[y] == nums[y - 1] && y - 1 > x)
                y--;
              x++;
              y--;
            }else if(nums[i] + nums[j] + nums[x] + nums[y] < target)
              x++;
            else
              y--;
          }

        }
      }

      return res;
    }
};
```