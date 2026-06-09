> 关注公众号【算法码上来】，每日算法干货马上就来！

![宣传图片.jpg](https://pic.leetcode-cn.com/dbcdbe2b8584f874a2b1efa1498cb829952f38aca66dadd7389defca821c67ad-%E5%AE%A3%E4%BC%A0%E5%9B%BE%E7%89%87.jpg)

## LeetCode 5352. 生成每种字符都是奇数个的字符串
### 题目链接
[https://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/](https://leetcode-cn.com/problems/generate-a-string-with-characters-that-have-odd-counts/)

### 题解
这题就没什么好说的了，如果 $n$ 是奇数，那就生成 $n$ 个 $a$ 。如果 $n$ 是偶数，那就生成 $n-1$ 个 $a$ ，再加上 $1$ 个 $b$ 。

### 代码（python）
```python
class Solution:
    def generateTheString(self, n: int) -> str:
        if n % 2 == 0:
            return "a"+"b"*(n-1)
        return "a"*n
```

## LeetCode 5353. 灯泡开关 III
### 题目链接
[https://leetcode-cn.com/problems/bulb-switcher-iii/](https://leetcode-cn.com/problems/bulb-switcher-iii/)

### 题解
如果某一个时刻灯都是蓝色的，等价于所有的亮灯都连续排列在数组最左边，没有间断。所以只需要判断当前时刻亮灯的最大编号是否等于亮灯的数量就行了。

比赛的时候傻 x 了，第一个想到的竟然是树状数组，于是直接把模板套过来过了。

### 代码（c++）
```cpp
class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int res = 0, maxx = 0;
        for (int i = 0, sz = light.size(); i < sz; ++i) {
            maxx = max(maxx, light[i]);
            if (maxx == i + 1) res++;
        }
        return res;
    }
};
```

**树状数组：**
```cpp
class Solution {
public:
    static const int MAXN = 50010;
    int bit[MAXN];
    
    int numTimesAllBlue(vector<int>& light) {
        memset(bit, 0, sizeof bit);
        int maxx = 0, res = 0;
        for (int i = 0, sz = light.size(); i < sz; ++i) {
            add(light[i], 1);
            maxx = max(maxx, light[i]);
            if (sum(maxx) == maxx) res++;
        }
        return res;
    }
    
    int lowbit(int x) {
        return x&(-x);
    }

    void add(int i, int x) {
        while (i < MAXN) {
            bit[i] += x;
            i += lowbit(i);
        }
    }

    void sub(int i, int x) {
        while (i < MAXN) {
            bit[i] -= x;
            i += lowbit(i);
        }
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= lowbit(i);
        }
        return s;
    }
};
```

## LeetCode 5354. 通知所有员工所需的时间
### 题目链接
[https://leetcode-cn.com/problems/time-needed-to-inform-all-employees/](https://leetcode-cn.com/problems/time-needed-to-inform-all-employees/)

### 题解
首先根据 $manager$ 数组来建图，边权就是父结点到子结点的通知时间。然后从根结点开始做 dfs ，求出根结点到每个叶子结点的路径长度的最大值。

### 代码（c++）
```cpp
class Solution {
public:
    static const int N = 100010;
    vector<int> G[N];
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                G[manager[i]].push_back(i);
            }
        }
        return f(headID, informTime);
    }
    
    int f(int headID, vector<int>& informTime) {
        if (!informTime[headID]) return 0;
        int maxx = 0;
        for (int i = 0, sz = G[headID].size(); i < sz; ++i) {
            maxx = max(maxx, f(G[headID][i], informTime));
        }
        return maxx+informTime[headID];
    }
};
```

## LeetCode 5355. T 秒后青蛙的位置
### 题目链接
[https://leetcode-cn.com/problems/frog-position-after-t-seconds/](https://leetcode-cn.com/problems/frog-position-after-t-seconds/)

### 题解
首先建图，然后从 $1$ 号结点开始，还是用 dfs 。每往下走一次，时间 $t$ 减 $1$ 。如果 $t = 0$ 或者到了叶子结点了，就判断结点是否为 $target$ ，是就返回 $1$ ，不是就返回 $0$ 。每次概率除以当前结点的子结点个数，然后再乘上所有子结点 dfs 结果的最大值（因为结果不是 $0$ 就是正确概率）。

### 代码（c++）
```cpp
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1) return 1.0;
        vector<vector<int>> G(110);
        for (int i = 0; i < n-1; ++i) {
            int u = edges[i][0], v = edges[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        return dfs(1, 0, t, target, G);
    }
    
    double dfs(int u, int fa, int t, int target, vector<vector<int>>& G) {
        int sz = G[u].size();
        if (!t || (fa && sz == 1)) {
            if (u == target) return 1;
            else return 0;
        }   
        double p = 1.0 / (fa ? sz-1 : sz), maxx = 0;
        for (int i = 0, sz = G[u].size(); i < sz; ++i) {
            int v = G[u][i];
            if (v == fa) continue;
            maxx = max(maxx, dfs(v, u, t-1, target, G));
        }
        return p*maxx;
    }
};
```

