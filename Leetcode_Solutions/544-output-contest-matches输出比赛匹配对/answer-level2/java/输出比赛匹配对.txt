#### 方法 1：模拟

**想法**

`team[i]` 为当前轮第 `i` 强的队伍。我们依照轮次维护这些信息。

**算法**

每轮中，第 `i` 个队伍变成 `"(" + team[i] + "," + team[n-1-i] + ")"`，然后只剩下一半的队伍。

```python []
class Solution(object):
    def findContestMatch(self, n):
        team = map(str, range(1, n+1))

        while n > 1:
            for i in xrange(n / 2):
                team[i] = "({},{})".format(team[i], team.pop())
            n /= 2

        return team[0]
```

```java []
class Solution {
    public String findContestMatch(int n) {
        String[] team = new String[n];
        for (int i = 1; i <= n; ++i)
            team[i-1] = "" + i;

        for (; n > 1; n /= 2)
            for (int i = 0; i < n / 2; ++i)
                team[i] = "(" + team[i] + "," + team[n-1-i] + ")";

        return team[0];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N\log N)$，$O(\log N)$ 轮每轮会有 $O(N)$ 的工作。
* 空间复杂度：$O(N\log N)$。

#### 方法 2：线性输出

**想法**

尝试在线性时间内解决这个问题。我们可以把这个问题看成两个部分：输出正确序列的括号和逗号，输出正确的队伍编号。显然可以证明这个线性时间算法是存在的。

**算法**

首先观察括号。通过递归我们会发现这个结果，例如 `N = 8` 令 `R = log_2(N) = 3` 是轮数。括号和逗号形如：

```python
(((x,x),(x,x)),((x,x),(x,x)))
```

这个仅仅通过递归实现

```python
"(" + (sequence for R = 2) + "," + (sequence for R = 2) + ")"
= "(" + "((x,x),(x,x))" + "," + "((x,x),(x,x))" + ")"
```

现在观察队伍编号，对于 `N = 16` 的情况为：

`team = [1, 16, 8, 9, 4, 13, 5, 12, 2, 15, 7, 10, 3, 14, 6, 11]`

我们会发现相邻两个元素的和为 `17`。更具体化会有，坐标 0 和 1（在模 2 情况下）和为 `17`，坐标 0 和 2（在模 4 情况下）和为 `9`，坐标 0 和 4（在模 8 情况下）和为 `5`，以此类推。

通俗表示为：坐标 `0` 和 `2^r`（在模 `2^{r+1}` 情况下）和为 `N * 2^{-r} + 1`。

如果我们希望找到下一个 `team[i]`，那么最低位的 `i` 会帮助我们决定他的邻居。例如：`team[12] = team[0b1100]` 的最低位是 `w = 4 = 0b100`，所以 `12` 最近的邻居是 `12 - w = 8`，所以这两个编号之和为 `N / w + 1`。



```python []
class Solution(object):
    def findContestMatch(self, n):
        team = []
        ans = []
        def write(r):
            if r == 0:
                i = len(team)
                w = i & -i
                team.append(n/w+1 - team[i-w] if w else 1)
                ans.append(str(team[-1]))
            else:
                ans.append("(")
                write(r-1)
                ans.append(",")
                write(r-1)
                ans.append(")")

        write(int(math.log(n, 2)))
        return "".join(ans)
```

```java []
class Solution {
    int[] team;
    int t;
    StringBuilder ans;
    public String findContestMatch(int n) {
        team = new int[n];
        t = 0;
        ans = new StringBuilder();
        write(n, Integer.numberOfTrailingZeros(n));
        return ans.toString();
    }

    public void write(int n, int round) {
        if (round == 0) {
            int w = Integer.lowestOneBit(t);
            team[t] = w > 0 ? n / w + 1 - team[t - w] : 1;
            ans.append("" + team[t++]);
        } else {
            ans.append("(");
            write(n, round - 1);
            ans.append(",");
            write(n, round - 1);
            ans.append(")");
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，我们按顺序打印 $O(N)$ 个字符。
* 空间复杂度：$O(N)$。