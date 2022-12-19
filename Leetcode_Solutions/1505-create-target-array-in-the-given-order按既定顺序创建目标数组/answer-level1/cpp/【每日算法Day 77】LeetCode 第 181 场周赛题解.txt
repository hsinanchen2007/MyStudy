> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/bcabb02ecf5d6ae8c5d8c855df18bd6f3ff17e0fefbdb1bdff8426e53ecfe826-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)


## 周赛链接
[https://leetcode-cn.com/contest/weekly-contest-181](https://leetcode-cn.com/contest/weekly-contest-181)

## LeetCode 5364. 按既定顺序创建目标数组
### 题目链接
[https://leetcode-cn.com/problems/create-target-array-in-the-given-order/](https://leetcode-cn.com/problems/create-target-array-in-the-given-order/)

### 题解
c++ `vector` 自带 `insert` 函数，直接用就行了。

### 代码（c++）
```cpp
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target;
        for (int i = 0; i < n; ++i) {
            target.insert(target.begin()+index[i], nums[i]);
        }
        return target;
    }
};
```

## LeetCode 5178. 四因数
### 题目链接
[https://leetcode-cn.com/problems/four-divisors/](https://leetcode-cn.com/problems/four-divisors/)

### 题解
直接求出每个数因数个数就行了，对于每个数 $x$，只需要枚举到 $\sqrt{x}$ 就行了，另外如果因子个数已经大于 $4$ 了，就直接退出。

### 代码（c++）
```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (auto x : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i*i <= x; ++i) {
                if (i*i == x) {
                    cnt++;
                    break;
                }
                if (x%i == 0) {
                    cnt += 2;
                    sum += i + x/i;
                }
                if (cnt > 4) break;
            }
            if (cnt == 4) res += sum;
        }
        return res;
    }
};
```

## LeetCode 5366. 检查网格中是否存在有效路径
### 题目链接
[https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/](https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/)

### 题解
可以用 bfs 或者 dfs ，我这里采用的是 bfs 。

整体框架和普通的 bfs 完全一模一样，那么问题就在于如何判断两个格子能否相连。在代码中体现为 `link` 函数，我们给它传了三个参数：$a$，$b$ 表示两个格子的街道标号（题面里解释了），$d$ 表示两个格子的位置关系（$0$：左右，$1$：右左，$2$：上下，$3$：下上）。

其中 $d=1$ 和 $d=3$ 都可以通过交换 $a$ 和 $b$ 的顺序，来分别转换成 $d=0$ 和 $d=2$ 。

对于 $d=0$ 来说，左右能连接的情况，只有**右边有出口**的格子（$a=1,4,6$）接上**左边有入口**的格子（$b=1,3,5$）。

对于 $d=2$ 来说，上下能连接的情况，只有**下边有出口**的格子（$a=2,3,4$）接上**上边有入口**的格子（$b=2,5,6$）。

其他情况全部无法连接。

这样最后 bfs 遍历到了 $(n-1,m-1)$ 就能到达终点，否则就无法到达。

### 代码（c++）
```cpp
class Solution {
public:
    int link(int a, int b, int d) {
        if (d == 1 || d == 3) {
            d--;
            swap(a, b);
        }
        if (d == 0) return (a==1||a==4||a==6)&&(b==1||b==3||b==5);
        if (d == 2) return (a==2||a==3||a==4)&&(b==2||b==5||b==6);
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        vis[0][0] = 1;
        while (!Q.empty()) {
            pair<int, int> p = Q.front();
            Q.pop();
            int x = p.first, y = p.second;
            if (x == n-1 && y == m-1) return true;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] && link(grid[x][y], grid[nx][ny], i)) {
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
        return false;
    }
};
```

## LeetCode 5367. 最长快乐前缀
### 题目链接
[https://leetcode-cn.com/problems/longest-happy-prefix/](https://leetcode-cn.com/problems/longest-happy-prefix/)

### 题解
kmp 模板题，细节就不说了，网上教程漫天铺地都是的。就一个函数，是个模板直接用就行了。最后求出来的 $next[i]$ 就表示了 $s[0]$ 到 $s[i]$ 子串的最长相同前缀后缀的长度，所以答案就是 $next[n-1]$ 。

### 代码（c++）
```cpp
class Solution {
public:
    void getNext(string s, vector<int>& next) {
        int n = s.size();
        next[0] = 0;
        for (int q = 1, k = 0; q < n; ++q) {
            while (k > 0 && s[q] != s[k])
                k = next[k-1];
            if (s[q] == s[k]) k++;
            next[q] = k;
        }
    }
    
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> next(n);
        getNext(s, next);
        return s.substr(0, next[n-1]);
    }
};
```

