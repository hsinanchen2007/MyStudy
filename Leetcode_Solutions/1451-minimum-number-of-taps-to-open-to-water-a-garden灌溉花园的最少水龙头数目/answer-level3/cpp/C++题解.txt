### [1326. 灌溉花园的最少水龙头数目](https://leetcode-cn.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)

#### 题解
  + 统计区间并按右边界大小进行排序
  + 区间动态规划， $dp[i]$ 为覆盖从0到第i个区间的右边界所需的最小区间个数
  + 动态转移方程：$dp[i] = min(dp[j] + 1) ,\  j < i \&\& l[i] <=  r[j]$
  + $ans = min(ans, dp[i]) ,\  r[i] >= n$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)
#### 代码

```cpp
class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
      int* a = new int[n+1];
      int* l = new int[n+1];
      int* r = new int[n+1];
      for(int i = 0; i <= n; i++)
          {
              a[i] = i;
              l[i] = i-ranges[i];
              r[i] = i+ranges[i];
          }
      // [&]表示使用了外部变量a/b
      sort(a, a+n+1, [&](int x, int y){return r[x] < r[y];});
      int* dp = new int[n+1];
      int res = 0x3f3f3f3f;
      for(int i = 0; i <= n; i++)
      {
          dp[i] = l[a[i]] <= 0 ? 1 : 0x3f3f3f3f;
          for(int j = i-1; j >= 0 && r[a[j]] >= l[a[i]]; j--)
          {
              dp[i] = min(dp[i], dp[j] + 1);
          }
          if(r[a[i]] >= n) res = min(res, dp[i]);
      }
      if (res >= 0x3f3f3f3f) return -1;
      return res;
  }
};
```