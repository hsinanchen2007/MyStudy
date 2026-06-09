### 解题思路
解题思路没什么好说的，
- 首先按树的高度从低到高排序
- 然后按顺序求各个点之间的最短路径

然后。。
![image.png](https://pic.leetcode-cn.com/59e598d1fa6025328b792d258b6b6975829014e62dfd07c454831bb86297ba38-image.png)

要说的是，这个题很难想出复杂度低于 $O(m^2n^2)$ 的思路。那么，肯定是算法的常数太大了。。。
什么是 “常数”？就是说，你和某大佬的思路是一样的，复杂度是一样的，但是你的算法 TLE 了，他的 AC 了，然后你就郁闷了，。。

话说，LeetCode 上卡常数的题并不多见，只要思路和标准差不多即可，
不过既然这个题卡了，那我接招就是了！

#### 优化1：快速 BFS
首先这个题需要很多次 BFS 来求最短路，我们希望能够对数据预处理，加快 BFS 的速度。
话说，在从一个中心点扩张时， BFS 的模板代码是这样子的：
```cpp
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
for(int i = 0; i < 4; ++i) {
    int x = prev.x + dir[i][0];
    int y = prev.y + dir[i][1];
    if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && forest[x][y] > 0) {
        ...
    }
}

```
这里 `if(x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && forest[x][y] > 0)` 有 6 个判断！
如果我们在地图的外围加上一圈 '0':
```
0 0 0 0 0
0|1 2 3|0
0|0 0 4|0
0|7 6 5|0
0 0 0 0 0
```
那么就可以简化判断：`if(forest[x][y] && !vis[x][y])`，两个判断就可以了！
因为越界的 $x$，$y$ 都会被识别成障碍物。

这样其实还不够好。访问二维数组，需要两个下标 $x$，$y$，需要一次乘法运算和一次加法运算。
例如，访问 $A[x][y]$，相当于访问 $A[x*n + y]$，其中 $n$ 是二维数组的列数。
如果可以在预处理时，将 **二维数组一维化**，那么，下次再访问元素时，只需要一个下标，进行一次乘法运算即可。
比如，将上面的
```
0 0 0 0 0
0 1 2 3 0
0 0 0 4 0
0 7 6 5 0
0 0 0 0 0
```
可以一维化为
```txt
0 0 0 0 0|0 1 2 3 0|0 0 0 4 0|0 7 6 5 0|0 0 0 0 0
```
该矩阵的列数为 5。假设现在处于某一位置 $x$ 上：
- 在其下方的元素为 $x + 5$。
- 在其上方的元素为 $x - 5$。
- 在其左侧的元素为 $x - 1$。
- 在其右侧的元素为 $x + 1$。

经过上述优化后，BFS 的代码可以简化成：
```cpp
int go[4] = {1, -1, n, -n}; // n 为矩阵的列数
for(int i = 0; i < 4; ++i) {
    int ne = pre + go[i];
    if(forest[ne] && !vis[ne]) { // forest 和 vis 都是一维化之后的数组
        ...
    }
}
```

#### 优化 2：手写队列
STL 的容器在一般不卡常数的题目中可以使用，一般效率也没问题。不过遇到这种 BT 题目，还是手写一个吧！
手写队列其实非常简单。队列有一个读指针和写指针。读用读指针，写用写指针，下面是示例代码：
```cpp
int q[1000], r = 0 /* 读指针 */, w = 0 /* 写指针 */;

// 读操作
int val = q[r++];

// 写操作
q[w++] = val;

// 是否为空
bool empty = (r == w);
```

#### 优化 3：间隔 BFS
假设我们要求 $A → B → C → D → E$ 的最短路径。
一般的思路是逐个求 $A→B$，$B→C$，$C→D$，$D→E$ 的最短路径。
但这样涉及一些重复计算。
假如我们先求出了 $A→B$ 的最短路径。然后求 $B→C$ 的最短路时，如果遇到了 $A$，显然是无用的，这相当于我们求了两次 $A→B$ 的最短路径。
于是，我们这样求：
- 从 $B$ 开始，同时求 $B→A$，$B→C$。
- 从 $D$ 开始，同时求 $D→C$，$D→E$。

这样，本来需要 4 次 BFS，现在只需要两次了。
虽然仍有一些重复计算，但是实践表明，间隔 BFS 所需时间更短。
### 代码
![image.png](https://pic.leetcode-cn.com/7e896aea0921dcad3ef449cb36e67f66f75a8154e98080c596405e3ba022cd04-image.png)
```cpp
int f[3050], vis[3050], sz, m,n,n2;
int q[3050], st[3050];
int tr[3000], cnt;
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        sz = 0, m = forest.size(), n = forest[0].size(),n2 = n+2, cnt = 0;

        // 数据预处理
        for(int i = 0; i < n2; ++i) f[sz++] = 0;
        tr[cnt++] = sz+1; // 我们需要从 [0,0] 开始
        for(int i = 0; i < forest.size(); ++i) {
            f[sz++] = 0;
            for(int j = 0; j < forest[0].size(); ++j, ++sz) {
                f[sz] = forest[i][j];
                if(f[sz] > 1) tr[cnt++] = sz;
            }
            f[sz++] = 0;
        }
        for(int i = 0; i < n2; ++i) f[sz++] = 0;
        memset(vis, 0, sz*sizeof(int));

        // 按树的高度从低向高排序
        sort(tr + 1, tr + cnt, [](int &a, int &b) {
            return f[a] < f[b];
        });

        // 间隔 bfs
        int res = 0, t[2];
        for(int i = (tr[0] == tr[1]? 2 : 1); i < cnt; i += 2) {
            t[0] = tr[i-1], t[1] = ((i + 1 == cnt)? -1 : tr[i+1]);
            if(!bfs(i, tr[i], t, 1 + (t[1] != -1), res))
                return -1;
        }
        return res;
    }

    bool bfs(int num, int s, int t[], int obj, int& res) {
        int got = 0, go[4] = {1,-1,n2,-n2};
        q[0] = s, st[0] = 0, vis[s] = num;
        for(int r = 0, w = 1; r != w; ++r)
        for(int d = 0; d < 4; ++d) {
            int ne = q[r] + go[d];
            if(f[ne] && vis[ne] != num) {
                if(ne == t[0]) res += st[r] + 1, ++got;
                if(ne == t[1]) res += st[r] + 1, ++got;
                if(got == obj) return true;
                vis[ne] = num, q[w] = ne, st[w] = st[r] + 1,++w;
            }
        }
        return false;
    }
};
```