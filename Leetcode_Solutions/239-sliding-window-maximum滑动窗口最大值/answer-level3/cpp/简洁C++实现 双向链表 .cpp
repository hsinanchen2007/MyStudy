```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> res;
  deque<int> dq;
  for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && nums[i] > nums[dq.back()]) dq.pop_back();
    dq.push_back(i);
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
    if (i >= k - 1) res.push_back(nums[dq.front()]);
  }
  return res;
}
```
