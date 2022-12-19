### 解题思路
和查找缺少一个数的思路相同，将所有数相加以求出缺失数的和，利用数据的有序性找到第一个缺少值就好了

### 代码

```cpp
class Solution {
public:
   vector<int> missingTwo(vector<int>& nums) {
      vector<int> ans(2);
      int n = nums.size();
      nums.push_back(n + 2);
      int sum = 2 * n + 3;
       for(int i = 0; i < n;i++)
              sum += i + 1 - nums[i];
      if (nums[0] != 1)
          ans[0] = 1;
      else
      {
          for (int i = 0; i < n; i++)
          {
              if (nums[i] + 1 != nums[i+1])
              {
                  ans[0] = nums[i] + 1;
                  break;
              }
          }
      }
      ans[1] = sum - ans[0];
      return ans;
  }
};
```