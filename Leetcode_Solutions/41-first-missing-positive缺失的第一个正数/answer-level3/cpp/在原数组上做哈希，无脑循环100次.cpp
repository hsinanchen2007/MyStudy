先把nums的大小填到n + 1确保1~n都能放进去，然后就开始排了嗷。循环100次可以不这么做，而是在内部一直置换到当前数不能置换为止的哈。
```c++
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    nums.emplace_back(-10000000);
    if (n == 0) return 1;
    if (n == 1) {
      if (nums[0] == 1) return 2;
      return 1;
    }
    for (int j = 0; j < 100; j++) {
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0 && nums[i] <= n && i != nums[i]) {
          swap(nums[i], nums[nums[i]]);
        }
      }
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (nums[i] != i) return i;
    }
    return nums.size();
  }
};
```