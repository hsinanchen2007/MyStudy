执行用时 :
32 ms
, 在所有 C++ 提交中击败了
96.40%
的用户

内存消耗 :
9.8 MB
, 在所有 C++ 提交中击败了
89.26%
的用户
```
vector<vector<int>> permuteUnique(vector<int> &nums) {
  vector<vector<int>> res;
  sort(nums.begin(), nums.end());
  do {
    res.push_back(nums);
  } while (next_permutation(nums.begin(), nums.end()));
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
}
```