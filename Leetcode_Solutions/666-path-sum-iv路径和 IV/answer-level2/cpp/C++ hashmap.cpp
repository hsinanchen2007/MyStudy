```cpp
int pathSum(vector<int>& nums) {
  int res = 0;
  unordered_map<int, int> M;
  for (int i = int(nums.size()) - 1; i >= 0; i--) {
    int d = nums[i] / 100, p = (nums[i] % 100) / 10, v = nums[i] % 10;
    M[d * 10 + p] = max(M[d * 10 + p], 1);
    res += M[d * 10 + p] * v;
    M[(d - 1) * 10 + (p - 1) / 2 + 1] += M[d * 10 + p];
  }
  return res;
}
```
