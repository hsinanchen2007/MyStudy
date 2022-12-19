```c++
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    vector<int> f(100000, 0);
    for (int i = 0; i < nums.size(); i++) {
      f[nums[i] + 50000]++;
    }
    nums.clear();
    for (int i = 0; i < 100000; i++) {
      while (f[i]) {
        nums.emplace_back(i - 50000);
        f[i]--;
      }
    }
    return nums;
  }
};
```