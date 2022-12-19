### 解题思路
想半天 以为用动态规划
结果看题解还蛮简单的

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> left(nums.size(), 1);
      vector<int> right(nums.size(), 1);
      vector<int> res(nums.size(), 1);
  
      for(int i = 1; i < nums.size(); i++)
        left[i] = nums[i - 1] * left[i - 1];

      for(int i = nums.size() - 2; i >= 0; i--)
        right[i] = nums[i + 1] * right[i + 1];

      for(int i = 0; i < nums.size(); i++)
        res[i] = left[i] * right[i];

      return res;
    }
};
```