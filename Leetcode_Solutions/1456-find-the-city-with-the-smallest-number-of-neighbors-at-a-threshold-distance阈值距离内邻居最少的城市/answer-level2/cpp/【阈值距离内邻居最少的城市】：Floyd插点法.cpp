#### Floyd算法

Floyd算法又称插点法，其中算法的核心思想是动态规划。

#### 算法步骤

1. 通过已知条件初始化距离矩阵D[n][n]，其中`D[i][j]`表示，顶点`i`到顶点`j`的距离。

2. n个顶点依次作为插入点，例如，k为其中一个顶点，`D[i][k] + D[k][j] < D[i][j]`，那说明顶点`i`经过顶点`k`再到达`j`，比直接到达`j`要近。所以更新`D[i][j]`：`D[i][j] = D[i][k] + D[k][j]`。

3. 可以归纳得到状态转移方程：`D[i][j] = min(D[i,k]+D[k,j],D[i,j]);`

Floyd核心代码：

```cpp
// Floyd算法
for (int k = 0; k < n; k++) {
// n个顶点依次作为插入点
// 注意插点k是放在第一层循环，后面会解释原因
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 遍历各个顶点之间的距离，并用插入点进行更新
            D[i][j] = min(D[i][k]+D[k][j], D[i][j]);
        }
    }
}
```

#### 题目解析

1. 使用Floyd算法求出各个城市到其它城市的距离，保存在矩阵`D[n][n]`中。

2. 遍历`D[n][n]`，统计各个城市在距离不超过 `distanceThreshold` 的情况下，能到达的其它城市的数量。

3. 返回能到达其它城市最少的城市 `ret`。

#### 解题代码


```cpp
class Solution {
public:
    int findTheCity(int n, vector <vector<int>> &edges, int distanceThreshold) {
        // 定义二维D向量，并初始化各个城市间距离为INT_MAX（无穷）
        vector <vector<int>> D(n, vector<int>(n, INT_MAX));
        // 根据edges[][]初始化D[][]
        for (auto &e : edges) {
            // 无向图两个城市间的两个方向距离相同
            D[e[0]][e[1]] = e[2];
            D[e[1]][e[0]] = e[2];
        }
        // Floyd算法
        for (int k = 0; k < n; k++) {
            // n个顶点依次作为插入点
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j || D[i][k] == INT_MAX || D[k][j] == INT_MAX) {
                        // 这些情况都不符合下一行的if条件，
                        // 单独拿出来只是为了防止两个INT_MAX相加导致溢出
                        continue;
                    }
                    D[i][j] = min(D[i][k] + D[k][j], D[i][j]);
                }
            }
        }
        // 选择出能到达其它城市最少的城市ret
        int ret;
        int minNum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && D[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= minNum) {
                minNum = cnt;
                ret = i;
            }
        }
        return ret;
    }
};
```

#### 一、 为什么遍历插入点k是放在第一层循环？

这个源自Floyd的核心思想--动态规划，代码中的二维状态转移方程`D[i][j] = min(D[i,k]+D[k,j],D[i,j]);`，其实是从三维简化得到的。

我们不妨从最初的三维说起，思路和二维一样：

1. 首先定义状态数组（也就是距离矩阵）`D[n][n][n]`，其中`D[k][i][j]`表示顶点`i`, 顶点`j`通过前`k`个顶点（0~k）得到的最短距离。

2. `D[k][i][j]`是从`D[k-1][i][j]`和`D[k-1][i][k] + D[k-1][k][j]`两者中值较小的一个转移得到的，也就是说要在前`k-1`个顶点已经插入，更新距离矩阵状态之后，第`k`个顶点才能作为插入顶点。

3. 归纳得到状态转移方程：`D[k][i][j] = min(D[k-1][i][j], D[k-1][i][k] + D[k-1][k][j])`。

4. 其中`k`的作用是标志到达了第几个插入点，也就是状态数组到达了哪个状态，不用刻意记录，于是减去第一维就变成了二维。

明白了Floyd的三维dp思想，根据状态转移方程在编码时就很自然的会将 `k` 放在第一层循环，而将`k`放在最后一层则是错误的编码。

#### 最后

感谢您的观看！欢迎大家留言，一起讨论交流。

至此，您已经掌握了 Floyd 算法，如果这篇文章对您有帮助，您可以扫描下方二维码关注我的公众号“小小算法”，感谢支持！

![小小算法.png](https://pic.leetcode-cn.com/1776597b2773892787b2a16738cd78feb346c5a5290273bce69275b0b66a0a95-%E5%AE%A3%E4%BC%A0%E5%9B%BE2.png)