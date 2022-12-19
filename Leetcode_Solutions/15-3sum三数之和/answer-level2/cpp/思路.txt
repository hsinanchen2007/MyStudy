### 解题思路
看起来简单，太容易NG了，一开始用哈希写更是一直过不了，主要重复元素没有找到好的方法剔除掉
后来老实用双指针

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      if(nums.size() < 3) return res;
      sort(nums.begin(), nums.end());

      for(int i = 0; i < nums.size() - 2; i++){
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        if(nums[i] > 0) break;
        int sum = 0 - nums[i];
        
        int j = i + 1, k = nums.size() - 1;

        while(j < k){
          if(nums[j] + nums[k] == sum){
            res.push_back({nums[i], nums[j], nums[k]});
            while(nums[j] == nums[j + 1] && j + 1 < k)
              j++;
            while(nums[k] == nums[k - 1] && k - 1 > j)
              k--;
            j++;
            k--;
          }else if(nums[j] + nums[k] < sum)
            j++;
          else
            k--;
        }
      }

      return res;
    }
};
```