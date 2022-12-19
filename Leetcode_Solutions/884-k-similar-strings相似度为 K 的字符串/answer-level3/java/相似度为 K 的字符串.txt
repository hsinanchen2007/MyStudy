#### 概述

我们对字符串 `A` 和 `B` 构造一个包含 `6` 个节点 `a`, `b`, `c`, `d`, `e`, `f` 的基础图。对于字符串中的第 `i` 位 `A[i]` 和 `B[i]`，我们在基础图中连一条 `A[i] -> B[i]` 的有向边，允许重边和自环。如果字符串 `A` 和 `B` 相等，那么基础图中就只有自环。

我们来考虑交换 `A[i]` 和 `A[j]` 会导致图如何变化。例如当 `A` 为 `ca...`，`B` 为 `ab...` 时，基础图中有边 `c -> a` 和 `a -> b`。如果我们交换 `A[0]` 和 `A[1]`，那么图中会剩下边 `c -> b` 和 `a` 的自环。我们把这种“把两条首尾相连的边变成一条新边和一个自环”的操作称为“截断”。可以证明，最优的操作中，所有的操作都是截断操作（证明的方法大致为：首先在任意时刻，图中必须有两条首尾相连的边存在；其次我们的目标是把所有的边变成自环，那么除了 `a -> b` 和 `b -> a` 这种情况之外，其它所有的一次操作最多只能使得图中多出一个自环，因此截断操作是最优的）。

最后我们考虑将基础图拆分为若干个环，拆分的方法并不是唯一的。对于一个长度为 `k` 的环，我们可以用 `k - 1` 次截断操作，把环上所有的边变为自环。因此，如果基础图被拆分为长度为 $C_1, \cdots, C_k$ 的 `k` 个环，需要的截断操作次数为 $\sum_k (C_k - 1)$，这个求和也等于基础图中非自环的边数 `n0` 减去环的个数 `k`。因此，我们的目标对基础图进行一个环数最多的拆分。

#### 方法一：动态规划

我们用 $P_1, P_2, \cdots$ 表示在基础图 $G$ 上所有可能的环，那么 $G$ 可以表示为 $\sum k_i P_i$，其中 $k_i$ 为常数，表示 $P_i$ 出现（被拆分得到）的次数，环的总数为 $\sum k_i$。

对于一个环 $P_i$，我们可以用一个 `01` 数组表示每条边是否出现，例如对于环 `a -> b -> d -> e -> a`，它有 `4` 条边 `a -> b`，`b -> d`，`d -> e` 和 `e -> a`，那么它对应的数组中，有 `4` 个位置（这 `4` 条边对应的位置）的值为 `1`，其它值为 `0`。同样地，基础图 $G$ 也可以用这种方式来表示。

因此我们可以使用动态规划来解决这个问题，令 `numCycles(G)` 表示基础图 $G$ 最多拆分的环的数目。我们枚举环 $C$，检查 $C$ 是否包含于 $G$。状态转移方程为 `numCycles(G) = max{1 + numcycles(G - C)}`。

```Java [sol1]
class Solution {
    String[] alphabet = new String[]{"a", "b", "c", "d", "e", "f"};
    Map<String, Integer> memo;

    public int kSimilarity(String A, String B) {
        if (A.equals(B)) return 0;
        int N = A.length();
        memo = new HashMap();
        int ans = 0;

        int[] count = new int[alphabet.length * alphabet.length];
        for (int i = 0; i < N; ++i)
            if (A.charAt(i) != B.charAt(i)) {
                count[alphabet.length * (A.charAt(i) - 'a') + (B.charAt(i) - 'a')]++;
                ans++;
            }

        List<int[]> possibles = new ArrayList();
        // Enumerate over every cycle
        for (int size = 2; size <= alphabet.length; ++size)
            search: for (String cycle: permutations(alphabet, 0, size)) {
                // Check if cycle is canonical
                for (int i = 1; i < size; ++i)
                    if (cycle.charAt(i) < cycle.charAt(0))
                        continue search;

                // Add count to possibles
                int[] row = new int[count.length];
                for (int i = 0; i < size; ++i) {
                    int u = cycle.charAt(i) - 'a';
                    int v = cycle.charAt((i+1) % size) - 'a';
                    row[alphabet.length * u + v]++;
                }
                possibles.add(row);
            }

        int[] ZERO = new int[count.length];
        memo.put(Arrays.toString(ZERO), 0);
        return ans - numCycles(possibles, count);
    }

    public int numCycles(List<int[]> possibles, int[] count) {
        String countS = Arrays.toString(count);
        if (memo.containsKey(countS)) return memo.get(countS);

        int ans = Integer.MIN_VALUE;
        search: for (int[] row: possibles) {
            int[] count2 = count.clone();
            for (int i = 0; i < row.length; ++i) {
                if (count2[i] >= row[i])
                    count2[i] -= row[i];
                else
                    continue search;
            }
            ans = Math.max(ans, 1 + numCycles(possibles, count2));
        }

        memo.put(countS, ans);
        return ans;
    }

    public List<String> permutations(String[] alphabet, int used, int size) {
        List<String> ans = new ArrayList();
        if (size == 0) {
            ans.add(new String(""));
            return ans;
        }

        for (int b = 0; b < alphabet.length; ++b)
            if (((used >> b) & 1) == 0)
                for (String rest: permutations(alphabet, used | (1 << b), size - 1))
                    ans.add(alphabet[b] + rest);
        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def kSimilarity(self, A, B):
        if A == B: return 0

        N = len(A)
        alphabet = 'abcdef'
        pairs = [(a, b) for a in alphabet for b in alphabet if a != b]
        index = {p: i for i, p in enumerate(pairs)}

        count = [0] * len(index)
        for a, b in itertools.izip(A, B):
            if a != b:
                count[index[a, b]] += 1

        seen = set()
        for size in xrange(2, len(alphabet) + 1):
            for cand in itertools.permutations(alphabet, size):
                i = cand.index(min(cand))
                seen.add(cand[i:] + cand[:i])

        possibles = []
        for cand in seen:
            row = [0] * len(alphabet) * (len(alphabet) - 1)
            for a, b in itertools.izip(cand, cand[1:] + cand[:1]):
                row[index[a, b]] += 1
            possibles.append(row)

        ZERO = tuple([0] * len(row))
        memo = {ZERO: 0}
        def solve(count):
            if count in memo: return memo[count]

            ans = float('-inf')
            for row in possibles:
                count2 = list(count)
                for i, x in enumerate(row):
                    if count2[i] >= x:
                        count2[i] -= x
                    else: break
                else:
                    ans = max(ans, 1 + solve(tuple(count2)))

            memo[count] = ans
            return ans

        return sum(count) - solve(tuple(count))
```

**复杂度分析**

* 时间复杂度：$O(2^{N+W})$，其中 $N$ 是字符串的长度，$W$ 是字母的数量。

* 空间复杂度：$O(2^{N+W})$。

#### 方法二：广度优先搜索

当我们把基础图 `G` 拆分为环并进行截断操作时，我们可以每次截断从左到右第一个 `A[i] != B[i]` 对应的那条边。即在字符串 `A` 和 `B` 中，我们每次找到最左侧满足 `A[i] != B[i]` 的 `i`，并搜索满足 `j > i` 且 `A[j] == B[i]` 的 `j`。

通过这种做法，我们可以使用广度优先搜索遍历所有的状态。可以大致估计出，状态的数量为 $\sum_k \binom{N}{k} 2^k = 3^N$，如果考虑重复的字符，还需要将状态数除以 $\prod (N_i)!$，其中 $N_i$ 表示 `A[i]` 在整个字符串中出现的次数。当 $N \leq 20$ 时，状态数量可以进行广度优先搜索。

```Java [sol2]
class Solution {
    public int kSimilarity(String A, String B) {
        Queue<String> queue = new ArrayDeque();
        queue.offer(A);

        Map<String, Integer> dist = new HashMap();
        dist.put(A, 0);

        while (!queue.isEmpty()) {
            String S = queue.poll();
            if (S.equals(B)) return dist.get(S);
            for (String T: neighbors(S, B)) {
                if (!dist.containsKey(T)) {
                    dist.put(T, dist.get(S) + 1);
                    queue.offer(T);
                }
            }
        }

        throw null;
    }

    public List<String> neighbors(String S, String target) {
        List<String> ans = new ArrayList();
        int i = 0;
        for (; i < S.length(); ++i) {
            if (S.charAt(i) != target.charAt(i)) break;
        }

        char[] T = S.toCharArray();
        for (int j = i+1; j < S.length(); ++j)
            if (S.charAt(j) == target.charAt(i)) {
                swap(T, i, j);
                ans.add(new String(T));
                swap(T, i, j);
            }

        return ans;
    }

    public void swap(char[] T, int i, int j) {
        char tmp = T[i];
        T[i] = T[j];
        T[j] = tmp;
    }
}
```

```Python [sol2]
class Solution(object):
    def kSimilarity(self, A, B):
        def neighbors(S):
            for i, c in enumerate(S):
                if c != B[i]:
                    break

            T = list(S)
            for j in xrange(i+1, len(S)):
                if S[j] == B[i]:
                    T[i], T[j] = T[j], T[i]
                    yield "".join(T)
                    T[j], T[i] = T[i], T[j]

        queue = collections.deque([A])
        seen = {A: 0}
        while queue:
            S = queue.popleft()
            if S == B: return seen[S]
            for T in neighbors(S):
                if T not in seen:
                    seen[T] = seen[S] + 1
                    queue.append(T)
```

**复杂度分析**

* 时间复杂度：$O(\sum_{k=0}^n \binom{N}{k} \frac{\min(2^k, (N-k)!)}{W * (\frac{N-k}{W})!})$，其中 $N$ 是字符串的长度，$W$ 是字母的数量。

* 空间复杂度：$O(N * t)$，其中 $t$ 为时间复杂度。