```c++
class Solution {
public:
  int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();
    vector<int> f(n + 1, -1);
    function<int(int)> dfs = [&](int i) {
      if (f[i] != -1) return f[i];
      int ret = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (arr[i] <= arr[j] || i - j > d) break;
        ret = max(ret, dfs(j) + 1);
      }
      for (int j = i + 1; j < n; j++) {
        if (arr[i] <= arr[j] || j - i > d) break;
        ret = max(ret, dfs(j) + 1);
      }
      return f[i] = ret;
    };
    int ret = 1;
    for (int i = 0; i < n; i++) {
      ret = max(ret, dfs(i));
    }
    return ret;
  }
};
```