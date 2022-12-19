使用dp记录steps，与move字符串，原来我好几次是最后一个没过，后来才知道如果说要更新一个move的字符串的话，需要重新入队列进行搜索的，然后同样之前扩展距离相等的点才能更新为字典序更小的字符串，方法和迷宫2类似。。可以改进一些判断语句，减少重复判断的次数。
```
class Solution {
public:
  struct Status {
    int steps;
    string move;
    Status(int s, string m) : steps(s), move(m) {}
  };
  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    int n = maze.size(), m = maze[0].size();
    vector<vector<Status>> dp(n, vector<Status>(m, Status(0, "")));
    // bfs的队列
    queue<pair<int, int>> tmp;
    tmp.push(make_pair(ball[0], ball[1]));
    int r, c, tmpr, tmpc, steps;
    while (!tmp.empty()) {
      auto t = tmp.front();
      tmp.pop();
      r = t.first;
      c = t.second;
      // cout << dp[r][c].move << endl;
      {
        // 四个大括号分别为上下左右方向的搜索，steps记录总步数，move记录如何移动到此处的
        // 如果步数优于dp中的步数，需要重新入队
        tmpr = r;
        tmpc = c;
        // 向上走，不能碰墙，下一格不能是1，并且不能碰到洞
        // 停下来的原因：到地图边界了/下一格是1/碰到洞了
        // 走的步数等于dp中起点的steps+走的步数
        // 如果没走，就不能算，所以tmpr不等于r，并且去的点没被访问（steps为0）或者现在到那个点的步数
        // 要少于先前到那个点的步数，就要将那个点重新进入队列，并且将move更新为现在更短的走法
        // 如果现在走到那个点的步数已经大于那边本身存储的步数了，没必要再去扩展了，那边肯定扩展过了
        // 如果steps相等，但是新走法的字典序更小，就要将新走法的move更新进去，重新入队扩展
        // 其他三个方向同理。
        while (tmpr > 0 && !maze[tmpr - 1][tmpc] && !(tmpr == hole[0] && tmpc == hole[1])) --tmpr;
        steps = r - tmpr + dp[r][c].steps;
        if (tmpr != r && (!dp[tmpr][tmpc].steps || steps < dp[tmpr][tmpc].steps)) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].steps = steps;
          dp[tmpr][tmpc].move = dp[r][c].move + 'u';
        }
        if (tmpr != r && steps == dp[tmpr][tmpc].steps && dp[r][c].move + 'u' < dp[tmpr][tmpc].move) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].move = dp[r][c].move + 'u';
        }
      }
      {
        tmpr = r;
        tmpc = c;
        while (tmpr < n - 1 && !maze[tmpr + 1][tmpc] && !(tmpr == hole[0] && tmpc == hole[1])) ++tmpr;
        steps = tmpr - r + dp[r][c].steps;
        if (tmpr != r && (!dp[tmpr][tmpc].steps || steps < dp[tmpr][tmpc].steps)) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].steps = steps;
          dp[tmpr][tmpc].move = dp[r][c].move + 'd';
        }
        if (tmpr != r && steps == dp[tmpr][tmpc].steps && dp[r][c].move + 'd' < dp[tmpr][tmpc].move) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].move = dp[r][c].move + 'd';
        }
      }
      {
        tmpr = r;
        tmpc = c;
        while (tmpc > 0 && !maze[tmpr][tmpc - 1] && !(tmpr == hole[0] && tmpc == hole[1])) --tmpc;
        steps = c - tmpc + dp[r][c].steps;
        if (tmpc != c && (!dp[tmpr][tmpc].steps || steps < dp[tmpr][tmpc].steps)) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].steps = steps;
          dp[tmpr][tmpc].move = dp[r][c].move + 'l';
        }
        if (tmpc != c && steps == dp[tmpr][tmpc].steps && dp[r][c].move + 'l' < dp[tmpr][tmpc].move) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].move = dp[r][c].move + 'l';
        }
      }
      {
        tmpr = r;
        tmpc = c;
        while (tmpc < m - 1 && !maze[tmpr][tmpc + 1] && !(tmpr == hole[0] && tmpc == hole[1])) ++tmpc;
        steps = tmpc - c + dp[r][c].steps;
        if (tmpc != c && (!dp[tmpr][tmpc].steps || steps < dp[tmpr][tmpc].steps)) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].steps = steps;
          dp[tmpr][tmpc].move = dp[r][c].move + 'r';
        }
        if (tmpc != c && steps == dp[tmpr][tmpc].steps && dp[r][c].move + 'r' < dp[tmpr][tmpc].move) {
          tmp.push(make_pair(tmpr, tmpc));
          dp[tmpr][tmpc].move = dp[r][c].move + 'r';
        }
      }
    }
    return dp[hole[0]][hole[1]].move == "" ? "impossible" : dp[hole[0]][hole[1]].move;
  }
};
```