从左到右扫一个数，剩下两个数在这个数右侧的数里划窗就行了嗷
```c++
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ret = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; i++) {
      int lo = i + 1, hi = n - 1;
      while (lo < hi) {
        int sum = nums[lo] + nums[hi] + nums[i];
        if (abs(sum - target) < abs(ret - target)) ret = sum;
        if (sum > target) hi--;
        else if (sum < target) lo++;
        else return ret;
      }
    }
    return ret;
  }
};
```