优先队列存历史记录，用一个vis判断当前在队列里的数字都是啥，每次更新答案的时候先pop一波优先队列。
```c++
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> vis(20020, 0);
    vector<int> ret;
    priority_queue<int> pq;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      nums[i] += 10000;
    }
    for (int i = 0; i < min(n, k); i++) {
      vis[nums[i]]++;
      pq.emplace(nums[i]);
    }
    if (k >= n) {
      ret.emplace_back(pq.top() - 10000);
      return ret;
    }
    ret.emplace_back(pq.top() - 10000);
    for (int i = k; i < n; i++) {
      vis[nums[i - k]]--;
      while (!pq.empty() && !vis[pq.top()]) pq.pop();
      pq.emplace(nums[i]);
      vis[nums[i]]++;
      ret.emplace_back(pq.top() - 10000);
    }
    return ret;
  }
};
```