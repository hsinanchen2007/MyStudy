### [1340. 跳跃游戏 V](https://leetcode-cn.com/problems/jump-game-v/submissions/)

#### 题解

  + 按高度从低到高排序,即得按高度排列的$a[i]$
  + 第一维从低到高进行DP，第二维DP时在未排序排列左右方向DP，选取未超过d且视线内高度小的进行DP
  + DP方程: $dp[a[i]] = max(dp[a[i]], dp[j]+1), d <= a[i]-j <= d \&\& arr[a[i]] > arr[j]$
  + 统计答案:$res = max(res, dp[a[i]])$
  + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码

```cpp
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int* a  = new int[arr.size()];
        int* dp = new int[arr.size()];
        for(int i = 0; i < arr.size(); i++)
            a[i] = i;
        sort(a, a + arr.size(), [&](int x, int y){
            return arr[x] < arr[y];
        });
        int res = 1;
        for(int i = 0; i < arr.size(); i++)
            {
                dp[a[i]] = 1;
                for(int j = a[i]-1; j >= 0 && a[i]-j <= d && arr[a[i]] > arr[j]; j--)
                    dp[a[i]] = max(dp[a[i]], dp[j]+1);
                for(int j = a[i]+1; j < arr.size() && j-a[i] <= d && arr[a[i]] > arr[j]; j++)
                    dp[a[i]] = max(dp[a[i]], dp[j]+1);
                res = max(res, dp[a[i]]);
            }
        return res;
    }
};
```