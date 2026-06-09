```c++
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int ret = 0;
    unordered_set<int> f;
    for (int i = 0; i < n; i++) {
      f.insert(nums[i]);
    }
    for (int i = 0; i < n; i++) {
      if (f.find(nums[i]) == f.end()) continue;
      int pre = nums[i] - 1, suf = nums[i] + 1, len = 1;
      f.erase(f.find(nums[i]));
      while (f.find(pre) != f.end()) {
        f.erase(f.find(pre));
        pre--;
        len++;
      }
      while (f.find(suf) != f.end()) {
        f.erase(f.find(suf));
        suf++;
        len++;
      }
      ret = max(ret, len);
    }
    return ret;
  }
};
```