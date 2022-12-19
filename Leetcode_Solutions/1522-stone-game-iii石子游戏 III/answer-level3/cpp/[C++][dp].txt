### 思路
目标是最大化自己的收益。定义自己的收益为 X，对方的收益为 Y。最大化 X 也就是最大化 X - Y。
定义`dp[i]`为有`[i, size)`这些石子时，所能获得的最大的X - Y。
别人的收益是你的损失，所以`dp[i] = a[i] - dp[i+1]`
则有如下代码。

### 实现
```C++
class Solution {
 public:
  string stoneGameIII(vector<int>& a) {
    int size = a.size();
    vector<int> dp(size + 10, 0);
    for (int i = size - 1; i >= 0; i--) {
      // 取一堆
      dp[i] = a[i] - dp[i+1];
      if (i + 1 < size) {
        // 取两堆
        dp[i] = max(dp[i], a[i] + a[i+1] - dp[i+2]);
      }
      if (i + 2 < size) {
        // 取三堆
        dp[i] = max(dp[i], a[i] + a[i+1] + a[i+2] - dp[i+3]);
      }
    }
    if (dp[0] > 0) {
      return "Alice";
    } else if (dp[0] == 0) {
      return "Tie";
    } else {
      return "Bob";
    }
  }
};
```
