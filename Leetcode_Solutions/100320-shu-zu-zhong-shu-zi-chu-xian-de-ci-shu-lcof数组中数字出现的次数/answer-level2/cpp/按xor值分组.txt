按xor值分组搞就好了嗷，奥利给
```c++
class Solution {
public:
  vector<int> singleNumbers(vector<int>& nums) {
    int v = 0;
    for (int i = 0; i < nums.size(); i++) {
      v ^= nums[i];
    }
    int pos = 0;
    for (int i = 0; i < 32; i++) {
      if ((1 << i) & v) {
        pos = i;
        break;
      }
    }
    vector<int> ret(2, 0);
    for (int i = 0; i < nums.size(); i++) {
      if ((1 << pos) & nums[i]) {
        ret[0] ^= nums[i];
      } else {
        ret[1] ^= nums[i];
      }
    }
    return ret;
  }
};
```