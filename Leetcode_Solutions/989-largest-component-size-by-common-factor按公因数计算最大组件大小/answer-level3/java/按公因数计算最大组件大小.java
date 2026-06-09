#### 方法一： 并查集

**思路**

设 $W = \max(A[i])$，$R = \sqrt{W}$。对于数组 $A$ 中的每个数，最多只有一个非本身的质因数 $p$ 满足 $p \geq R$。

这就意味着最多只有 $R + A\text{.length}$ 个不同的质因数： 为本身的质因数最多有 $A\text{.length}$ 个，非本身的质因数一定比 $R$ 小，最多有 $R$ 个。 

**算法**

提取数组 $A$ 中每个数的质因数，对每个质因数建立索引。接着，用并查集把 $A$ 中的质因数合并起来。最后计算每个集合的大小。

```java [solution1-Java]
class Solution {
    public int largestComponentSize(int[] A) {
        int N = A.length;

        // factored[i] = a list of unique prime factors of A[i]
        ArrayList<Integer>[] factored = new ArrayList[N];
        for (int i = 0; i < N; ++i) {
            factored[i] = new ArrayList<Integer>();
            int d = 2, x = A[i];
            while (d * d <= x) {
                if (x % d == 0) {
                    while (x % d == 0)
                        x /= d;
                    factored[i].add(d);
                }

                d++;
            }

            if (x > 1 || factored[i].isEmpty())
                factored[i].add(x);
        }

        // primesL : a list of all primes that occur in factored
        Set<Integer> primes = new HashSet();
        for (List<Integer> facs: factored)
            for (int x: facs)
                primes.add(x);

        int[] primesL = new int[primes.size()];
        int t = 0;
        for (int x: primes)
            primesL[t++] = x;

        // primeToIndex.get(v) == i  iff  primes[i] = v
        Map<Integer, Integer> primeToIndex = new HashMap();
        for (int i = 0; i < primesL.length; ++i)
            primeToIndex.put(primesL[i], i);

        DSU dsu = new DSU(primesL.length);
        for (List<Integer> facs: factored)
            for (int x: facs)
                dsu.union(primeToIndex.get(facs.get(0)), primeToIndex.get(x));

        int[] count = new int[primesL.length];
        for (List<Integer> facs: factored)
            count[dsu.find(primeToIndex.get(facs.get(0)))]++;

        int ans = 0;
        for (int x: count)
            if (x > ans)
                ans = x;
        return ans;
    }
}

class DSU {
    int[] parent;
    public DSU(int N) {
        parent = new int[N];
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    public int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    public void union(int x, int y) {
        parent[find(x)] = find(y);
    }
}
```

```python [solution1-Python]
class DSU:
    def __init__(self, N):
        self.p = range(N)

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr

class Solution(object):
    def largestComponentSize(self, A):
        B = []
        for x in A:
            facs = []
            d = 2
            while d * d <= x:
                if x % d == 0:
                    while x % d == 0:
                        x /= d
                    facs.append(d)
                d += 1

            if x > 1 or not facs:
                facs.append(x)
            B.append(facs)

        primes = list({p for facs in B for p in facs})
        prime_to_index = {p: i for i, p in enumerate(primes)}

        dsu = DSU(len(primes))
        for facs in B:
            for x in facs:
                dsu.union(prime_to_index[facs[0]], prime_to_index[x])

        count = collections.Counter(dsu.find(prime_to_index[facs[0]]) for facs in B)
        return max(count.values())
```

**复杂度分析**

* 时间复杂度： $O(N\sqrt{W})$，其中 $N$ 是 `A` 的长度，$W = \max(A[i])$。

* 空间复杂度： $O(N)$。