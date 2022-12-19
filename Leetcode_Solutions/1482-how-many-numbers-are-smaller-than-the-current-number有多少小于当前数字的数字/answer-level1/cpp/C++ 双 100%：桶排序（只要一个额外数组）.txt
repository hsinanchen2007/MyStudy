```C++
vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
  int aux[101] = {0};
  // 计算每个数出现的次数
  for (int e : nums) {
    aux[e]++;
  }

  // 注意 aux 的含义发生了变化：从指示数 i 出现了多少次变成指示有多少元素比 i 小
  // 比 i 小的元素的个数 = i - 1 出现的次数 + 比 i - 1 小的元素的个数
  // 类似 Fibonacci 数的计算
  int a = aux[0], t;
  // 比 0 小的元素有 0 个
  aux[0] = 0;
  for (int i = 1; i < 101; i++) {
    t = aux[i];
    aux[i] = a + aux[i - 1];
    a = t;
  }

  // 统计
  vector<int> ans(nums.size());
  for (int i = 0; i < nums.size(); i++) {
    ans[i] = aux[nums[i]];
  }

  return ans;
}
```