我原来以为这道题是迷宫1的变种，没想到其实迷宫1只需要深搜即可，只要有解就可以，这题原来我用深搜超时了，因为太多重复的事情了，就使用大家都喜欢的广搜来解决，使用了队列存储坐标，以及dp记录步数以及是否访问过即可，迷宫3按理说只要稍微改一下也是可以的

```cpp
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    int n = maze.size(), m = maze[0].size();
    vector<vector<int>> dp(n, (vector<int>(m, 0)));  // 记录步数
    queue<pair<int, int>> tmp;
    tmp.push(make_pair(start[0], start[1]));
    int r, c, tmpr, tmpc, steps;
    while (!tmp.empty()) {
      auto t = tmp.front();
      tmp.pop();
      r = t.first;
      c = t.second;
      {
        // 四个大括号分别为上下左右方向的搜索，steps记录总步数
        // 如果步数优于dp中的步数，需要重新入队
        tmpr = r;
        tmpc = c;
        while (tmpr > 0 && !maze[tmpr - 1][tmpc]) --tmpr;
        steps = r - tmpr + dp[r][c];
        if (tmpr != r && (!dp[tmpr][tmpc] || steps < dp[tmpr][tmpc])) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc] = steps;
        }
      }
      {
        tmpr = r;
        tmpc = c;
        while (tmpr < n - 1 && !maze[tmpr + 1][tmpc]) ++tmpr;
        steps = tmpr - r + dp[r][c];
        if (tmpr != r && (!dp[tmpr][tmpc] || steps < dp[tmpr][tmpc])) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc] = steps;
        }
      }
      {
        tmpr = r;
        tmpc = c;
        while (tmpc > 0 && !maze[tmpr][tmpc - 1]) --tmpc;
        steps = c - tmpc + dp[r][c];
        if (tmpc != c && (!dp[tmpr][tmpc] || steps < dp[tmpr][tmpc])) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc] = steps;
        }
      }
      {
        tmpr = r;
        tmpc = c;
        while (tmpc < m - 1 && !maze[tmpr][tmpc + 1]) ++tmpc;
        steps = tmpc - c + dp[r][c];
        if (tmpc != c && (!dp[tmpr][tmpc] || steps < dp[tmpr][tmpc])) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc] = steps;
        }
      }
    }
    // 如果最后dp数组中目标位置为0，说明还没走过，肯定是走不到了
    return dp[destination[0]][destination[1]]
               ? dp[destination[0]][destination[1]]
               : -1;
  }
};
```