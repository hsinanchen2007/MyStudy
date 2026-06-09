#### 思路分析



首先可以把题目中给出表示情侣的数组对 `(0, 1), (2, 3), (4, 5), ...` 用 `(0, 0), (1, 1), (2, 2), ...` 来表示，这种转换是不会影响答案的。同时再想象一下有 `N` 个两人沙发，编号为 `0, 1, 2, ..., N-1`。这就可以把问题转换成让每对情侣坐在一张沙发上至少需要多少次交换。
在此基础上，我们做出一个猜想，这个猜想叫做 ”快乐交换猜想“。
猜想的内容是，如果一次交换之后，没有更多的人变开心，那这次交换一定不在最优解里面。我们会在后面对其进行证明。

#### 方法一： 回溯法 【超时】

**思路**

我们可以再有一个猜想（之后会证明），按顺序将每张沙发上的人变开心可以得到最优解。这个猜想要比 “快乐交换猜想” 更具体，而且这个猜想看起来是比较合理的，因为每次交换我们至少可以让一对情侣变开心。（具体证明见方法二）
在这个猜想的前提下，假设有一张坐着 X, Y 的沙发，这两个人不是情侣，为了让他们变开心，我们有两个选择，要么把 Y 替换成 X 的情侣，要么把 X 替换成 Y 的情侣。对于这两个选择，用回溯法都来尝试一遍。

**算法**

对于每张沙发都有两个选择（在这张沙发上坐的不是一对情侣的情况下），首先尝试第一个选择，把答案标记为 `ans1`，接着尝试第二种选择，把答案标记为 `ans2`，这样就可以试完所有的可能找到最小的答案。

```python [solution1-Python]
class Solution(object):
    def minSwapsCouples(self, row):
        N = len(row) / 2
        pairs = [[row[i]/2, row[i+1]/2]
                 for i in xrange(0, 2*N, 2)
                 if row[i]/2 != row[i+1]/2]

        def swap(a, b, c, d):
            pairs[a][b], pairs[c][d] = pairs[c][d], pairs[a][b]

        def solve(i = 0):
            if i == len(pairs): return 0
            x, y = pairs[i]
            if x == y: return solve(i+1)

            for j in xrange(i+1, len(pairs)):
                for k in xrange(2):
                    if pairs[j][k] == x: jx = j, k
                    if pairs[j][k] == y: jy = j, k

            swap(i, 1, *jx)
            ans1 = 1 + solve(i+1)
            swap(i, 1, *jx)

            swap(i, 0, *jy)
            ans2 = 1 + solve(i+1)
            swap(i, 0, *jy)

            return min(ans1, ans2)

        return solve()
```

```java [solution1-Java]
class Solution {
    int N;
    int[][] pairs;

    public int minSwapsCouples(int[] row) {
        N = row.length / 2;
        pairs = new int[N][2];
        for (int i = 0; i < N; ++i) {
            pairs[i][0] = row[2*i] / 2;
            pairs[i][1] = row[2*i+1] / 2;
        }

        return solve(0);
    }

    public void swap(int a, int b, int c, int d) {
        int t = pairs[a][b];
        pairs[a][b] = pairs[c][d];
        pairs[c][d] = t;
    }

    public int solve(int i) {
        if (i == N) return 0;
        int x = pairs[i][0], y = pairs[i][1];
        if (x == y) return solve(i+1);

        int jx=0, kx=0, jy=0, ky=0; // Always gets set later
        for (int j = i+1; j < N; ++j) {
            for (int k = 0; k <= 1; ++k) {
                if (pairs[j][k] == x) {jx = j; kx = k;}
                if (pairs[j][k] == y) {jy = j; ky = k;}
            }
        }

        swap(i, 1, jx, kx);
        int ans1 = 1 + solve(i+1);
        swap(i, 1, jx, kx);

        swap(i, 0, jy, ky);
        int ans2 = 1 + solve(i+1);
        swap(i, 0, jy, ky);

        return Math.min(ans1, ans2);
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N * 2^N)$，其中 $N$ 为情侣对的数量，对于每对情侣都尝试两种可能的交换选择。 

* 空间复杂度: $O(N)$。

#### 方法二： 循环搜索 【通过】

**思路**

假设 ”快乐交换理论“ 是对的，如果一对情侣不坐在一对沙发上，那么就有两种交换的选择将这张沙发上凑成一对情侣。对于这样的交换，其实可以把它化成一张图，举个例子，有沙发 X 和 沙发 Y(可能是同一个沙发），可以通过画一条 X 到 Y 的无向边来表示 X 沙发跟 Y 沙发上可以组成一对情侣。这样最后画成的图把它称作情侣图，这张图每个节点的度为2，图上有一些连通分量。 

![](https://pic.leetcode-cn.com/Figures/765/couples_cycle_finding.png)

每次将一个沙发上凑成一对情侣之后，在图上的变化是多了一个自循环的连通分量。我们的目标是让图中有 `N` 个连通分量，每个连通分量代表一对情侣。每次交换都会将连通分量的数量增加 1，根据 ”快乐交换理论“，问题的答案可以通过 `N` 减去最开始情侣图中连通分量的个数来得到。

现在来证明 ”快乐交换理论“ 是正确的，可以观察到不论怎么交换，一次交换都不可能增加多于一个连通分量，所以每次增加一个连通分量的交换就是最优解。（同时这也可以证明方法一中的假设，因为不管按什么顺序去增加连通分量，结果都不会改变）

**算法**

首先来构建图，定义 `adj[node]` 为当前 `node` 的情侣所处沙发的下标。随后找到所有的联通分量。最后让每个沙发变成一个自循环的连通分量。

```python [solution2-Python]
class Solution(object):
    def minSwapsCouples(self, row):
        N = len(row) / 2

        #couples[x] = [i, j]:
        #x-th couple is at couches i and j
        couples = [[] for _ in xrange(N)]
        for i, x in enumerate(row):
            couples[x/2].append(i/2)
        #adj[x] = [i, j]
        #x-th couch connected to couches i, j by couples
        adj = [[] for _ in xrange(N)]
        for x, y in couples:
            adj[x].append(y)
            adj[y].append(x)
        #Answer is N minus the number of cycles in "adj"
        ans = N
        for start in xrange(N):
            if not adj[start]: continue
            ans -= 1
            x, y = start, adj[start].pop()
            while y != start:
                adj[y].remove(x)
                x, y = y, adj[y].pop()
        return ans
```

```java [solution2-Java]
class Solution {
    public int minSwapsCouples(int[] row) {
        int N = row.length / 2;
        //couples[x] = {i, j} means that
        //couple #x is at couches i and j (1 indexed)
        int[][] couples = new int[N][2];

        for (int i = 0; i < row.length; ++i)
            add(couples[row[i]/2], i/2 + 1);

        //adj[x] = {i, j} means that
        //x-th couch connected to couches i, j (all 1 indexed) by couples
        int[][] adj = new int[N+1][2];
        for (int[] couple: couples) {
            add(adj[couple[0]], couple[1]);
            add(adj[couple[1]], couple[0]);
        }

        // The answer will be N minus the number of cycles in adj.
        int ans = N;
        // For each couch (1 indexed)
        for (int r = 1; r <= N; ++r) {
            // If this couch has no people needing to be paired, continue
            if (adj[r][0] == 0 && adj[r][1] == 0)
                continue;

            // Otherwise, there is a cycle starting at couch r.
            // We will use two pointers x, y with y faster than x by one turn.
            ans--;
            int x = r, y = pop(adj[r]);
            // When y reaches the start 'r', we've reached the end of the cycle.
            while (y != r) {
                // We are at some couch with edges going to 'x' and 'new'.
                // We remove the previous edge, since we came from x.
                rem(adj[y], x);

                // We update x, y appropriately: y becomes new and x becomes y.
                x = y;
                y = pop(adj[y]);
            }
        }
        return ans;
    }

    // Replace the next zero element with x.
    public void add(int[] pair, int x) {
        pair[pair[0] == 0 ? 0 : 1] = x;
    }

    // Remove x from pair, replacing it with zero.
    public void rem(int[] pair, int x) {
        pair[pair[0] == x ? 0 : 1] = 0;
    }

    // Remove the next non-zero element from pair, replacing it with zero.
    public int pop(int[] pair) {
        int x = pair[0];
        if (x != 0) {
            pair[0] = 0;
        } else {
            x = pair[1];
            pair[1] = 0;
        }
        return x;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N)$，其中 $N$ 情侣对的数量。

* 空间复杂度: $O(N)$。

#### 方法三： 贪心 【通过】

**思路**

根据我们的假设，可以制定按顺序让每张沙发上情侣开心的策略。对于每张沙发，找到沙发上第一个人的情侣，如果不在同一个沙发上，就把沙发上的第二人换成第一个人的情侣。

**算法**

如果一个人的编号为 `x`，那么他的情侣的编号为 `x ^ 1`， `^` 在这里是异或操作。对于每张沙发上的第一个人 `x = row[i]`，找到他们的同伴所在的位置 `row[j]`，将 `row[j]` 和 `row[i + 1]` 互相交换。

```python [solution3-Python]
class Solution(object):
    def minSwapsCouples(self, row):
        ans = 0
        for i in xrange(0, len(row), 2):
            x = row[i]
            if row[i+1] == x^1: continue
            ans += 1
            for j in xrange(i+1, len(row)):
                if row[j] == x^1:
                    row[i+1], row[j] = row[j], row[i+1]
                    break
        return ans
```

```java [solution3-Java]
class Solution {
    public int minSwapsCouples(int[] row) {
        int ans = 0;
        for (int i = 0; i < row.length; i += 2) {
            int x = row[i];
            if (row[i+1] == (x ^ 1)) continue;
            ans++;
            for (int j = i+1; j < row.length; ++j) {
                if (row[j] == (x^1)) {
                    row[j] = row[i+1];
                    row[i+1] = x^1;
                    break;
                }
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N^2)$，其中 $N$ 为情侣对的数量。

* 空间复杂度: $O(1)$，互相交换不需要开辟额外的空间。