```c++
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret(2, -1);
    int n = nums.size();
    if (n == 0) return ret;
    int lo = 0, hi = n - 1;
    int pos = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (nums[mid] >= target) {
        if (nums[mid] == target) pos = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (pos == -1) return ret;
    ret[0] = pos;
    pos = -1;
    hi = n - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (nums[mid] <= target) {
        if (nums[mid] == target) pos = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    ret[1] = pos;
    return ret;
  }
};
```