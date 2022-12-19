#### 方法 1：相邻标记

**想法**

对于每组垂直多米诺骨牌（`'.'`），我们有两个非垂直多米诺骨牌将他们分割开。因为在这个组外的多米诺骨牌不会有影响，我们可以分别分析每组的情况：一共有 9 种可能（由于边界多米诺可能是空）。实际上，如果我们用 `L` 和 `R` 的多米诺骨牌作为边界，最多只有 4 种情况。我们会根据情况的不同使用新字母来表示。

**算法**

继续我们的算法，我们分析以下形式：

* 如果我们有 `"A....B"`，当 `A = B`，那么就变成 `"AAAAAA"`。
* 如果我们有 `"R....L"`，那么结果会变成 `"RRRLLL"` 或者 `"RRR.LLL"` 如果点的个数是奇数。如果初始标记的坐标是 `i` 和 `j`，我们可以检查距离 `k-i` 和 `j-k` 来决定位置 `k` 的形态是 `'L'`，`'R'` 还是 `'.'`。
* 如果我们有 `"L....R"`，就什么都不做，跳过。

```Java []
class Solution {
    public String pushDominoes(String dominoes) {
        int N = dominoes.length();
        int[] indexes = new int[N+2];
        char[] symbols = new char[N+2];
        int len = 1;
        indexes[0] = -1;
        symbols[0] = 'L';

        for (int i = 0; i < N; ++i)
            if (dominoes.charAt(i) != '.') {
                indexes[len] = i;
                symbols[len++] = dominoes.charAt(i);
            }

        indexes[len] = N;
        symbols[len++] = 'R';

        char[] ans = dominoes.toCharArray();
        for (int index = 0; index < len - 1; ++index) {
            int i = indexes[index], j = indexes[index+1];
            char x = symbols[index], y = symbols[index+1];
            char write;
            if (x == y) {
                for (int k = i+1; k < j; ++k)
                    ans[k] = x;
            } else if (x > y) { // RL
                for (int k = i+1; k < j; ++k)
                    ans[k] = k-i == j-k ? '.' : k-i < j-k ? 'R' : 'L';
            }
        }

        return String.valueOf(ans);
    }
}
```

```Python []
class Solution(object):
    def pushDominoes(self, dominoes):
        symbols = [(i, x) for i, x in enumerate(dominoes) if x != '.']
        symbols = [(-1, 'L')] + symbols + [(len(dominoes), 'R')]

        ans = list(dominoes)
        for (i, x), (j, y) in zip(symbols, symbols[1:]):
            if x == y:
                for k in xrange(i+1, j):
                    ans[k] = x
            elif x > y: #RL
                for k in xrange(i+1, j):
                    ans[k] = '.LR'[cmp(k-i, j-k)]

        return "".join(ans)
```


**复杂度分析**

* 时间和空间复杂度：$O(N)$，其中 $N$ 是 `dominoes` 的长度。

#### 方法 2：计算受力

**想法**

我们可以对每个多米诺骨牌计算净受力。我们关心的受力取决于一个多米诺骨牌和最近的左侧 `'R'` 右侧 `'L'` 的距离：哪边近，就受哪边力更多。

**算法**

从左向右扫描，我们的力每轮迭代减少 1.重置为 `N` 当我们遇到一个 `'R'` 时，所以 `force[i]` 比 `force[j]` 大当且仅当 `dominoes[i]` 比 `dominoes[j]` 离最左边的 `'R'` 近。

类似的，从右向左搜啊秒，可以找到向左侧的力，离 `L` 的远近。

对于骨牌的结果 `answer[i]`，如果左右两侧力相等，答案是 `'.'`。否则，哪边力大答案就是哪边。

**样例**

下面是对字符串 `S = 'R.R...L'` 的模拟：我们从左向右暴力得到的结果为 `[7, 6, 7, 6, 5, 4, 0]`，从右向左扫描的结果为 `[0, 0, 0, -4, -5, -6, -7]`。合并之后，合力为 `[7, 6, 7, 2, 0, -2, -7]` 所以最近结果为 `RRRR.LL`。


```Java []
class Solution {
    public String pushDominoes(String S) {
        char[] A = S.toCharArray();
        int N = A.length;
        int[] forces = new int[N];

        // Populate forces going from left to right
        int force = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 'R') force = N;
            else if (A[i] == 'L') force = 0;
            else force = Math.max(force - 1, 0);
            forces[i] += force;
        }

        // Populate forces going from right to left
        force = 0;
        for (int i = N-1; i >= 0; --i) {
            if (A[i] == 'L') force = N;
            else if (A[i] == 'R') force = 0;
            else force = Math.max(force - 1, 0);
            forces[i] -= force;
        }

        StringBuilder ans = new StringBuilder();
        for (int f: forces)
            ans.append(f > 0 ? 'R' : f < 0 ? 'L' : '.');
        return ans.toString();
    }
}
```

```Python []
class Solution(object):
    def pushDominoes(self, dominoes):
        N = len(dominoes)
        force = [0] * N

        # Populate forces going from left to right
        f = 0
        for i in xrange(N):
            if dominoes[i] == 'R': f = N
            elif dominoes[i] == 'L': f = 0
            else: f = max(f-1, 0)
            force[i] += f

        # Populate forces going from right to left
        f = 0
        for i in xrange(N-1, -1, -1):
            if dominoes[i] == 'L': f = N
            elif dominoes[i] == 'R': f = 0
            else: f = max(f-1, 0)
            force[i] -= f

        return "".join('.' if f==0 else 'R' if f > 0 else 'L'
                       for f in force)
```

**复杂度分析**

* 时间和空间复杂度：$O(N)$。