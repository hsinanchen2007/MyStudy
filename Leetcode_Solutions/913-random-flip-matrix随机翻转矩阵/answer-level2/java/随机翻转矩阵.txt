#### 分析

由于题目中给出的 `n_rows` 和 `n_cols` 最大能达到 `10000`，因此我们在维护这个矩阵时，要注意以下两点：

- 我们不能使用 $O(\text{n\_rows} * \text{n\_cols})$ 的空间复杂度来维护这个矩阵，这样会超出空间限制。我们应当找到空间复杂度较低的数据结构来表示这个矩阵；

- 我们需要尽量少的调用语言内置的 `random()` 函数来产生随机数，保证每次 `flip()` 操作的时间复杂度尽可能低。

#### 方法一：映射为一维数组

我们可以考虑一个长度为 `n_rows * n_cols` 的一维数组 `V`，对于矩阵中的位置 `(i, j)`，它对应了 `V` 中的元素 `V[i * n_cols + j]`，这样就保证了矩阵和 `V` 的双射。在翻转操作中，我们会修改 `V` 与矩阵的映射，使得当矩阵中有 `k` 个 `0`（即进行了 `k` 次翻转后）时，`V[0 .. k - 1]` 映射到矩阵中的 `0`，而 `V[k ..]` 映射到矩阵中的 `1`。这样的好处是，当我们进行下一次翻转操作时，我们只需要在 `[0, k)` 这个区间生成随机数 `x`，并将 `V[x]` 映射到的位置进行翻转即可。

在将 `V[x]` 进行翻转后，此时矩阵中有 `k - 1` 个 `0`，所以我们需要保证 `V[0 .. k - 2]` 都映射到矩阵中的 `0`。由于此时 `V[x]` 映射到了矩阵中的 `1`，因此我们可以将 `V[x]` 与 `V[k - 1]` 的值进行交换，即将这个新翻转的 `1` 作为 `V[k - 1]` 的映射，而把原本 `V[k - 1]` 映射到的 `0` 交给 `x`。这样我们就保证了在每一次翻转操作后，`V` 中的前 `k` 个元素恰好映射到矩阵中的所有 `k` 个 `0`。

那么我们如何维护这个一维数组 `V` 呢？我们可以发现，`V` 中的大部分映射关系是不会改变的，即矩阵中的 `(i, j)` 映射到 `V[i * n_cols + j]`，因此我们可以使用一个哈希映射（HashMap）仅存储那些被修改了的映射。对于一个数 `x`，如果 `x` 不是 HashMap 中的一个键，那么它直接映射到最开始的 `(x / n_cols, x % n_cols)`；如果 `x` 是 HashMap 中的一个键，那么它映射到其在 HashMap 中对应的值。这样这个 HashMap 的大小仅和翻转次数成正比，因为每一次翻转操作我们会交换 `V` 中两个元素的映射，即最多有两个元素的映射关系被修改。

```C++ [sol1]
class Solution {
public:

    unordered_map<int,int> V;
    int nr, nc, rem;

    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    //uniform random integer in [0, bound]
    int randint(int bound) {
        uniform_int_distribution<int> uni(0, bound);
        return uni(rng);
    }

    Solution(int n_rows, int n_cols) {
        nr = n_rows, nc = n_cols, rem = nr * nc;
    }

    vector<int> flip() {
        int r = randint(--rem);
        int x = V.count(r) ? V[r] : V[r] = r;
        V[r] = V.count(rem) ? V[rem] : V[rem] = rem;
        return {x / nc, x % nc};
    }

    void reset() {
        V.clear();
        rem = nr*nc;
    }
};
```

```Java [sol1]
class Solution {

    Map<Integer, Integer> V = new HashMap<>();
    int nr, nc, rem;
    Random rand = new Random();

    public Solution(int n_rows, int n_cols) {
        nr = n_rows;
        nc = n_cols;
        rem = nr * nc;
    }

    public int[] flip() {
        int r = rand.nextInt(rem--);
        int x = V.getOrDefault(r, r);
        V.put(r, V.getOrDefault(rem, rem));
        return new int[]{x / nc, x % nc};
    }

    public void reset() {
        V.clear();
        rem = nr * nc;
    }
}
```

**复杂度分析**

* 时间复杂度：`flip()` 操作的时间复杂度为 $O(1)$，`reset()` 操作的时间复杂度为 $O(F)$，其中 $F$ 是在上一次 `reset()` 之后执行 `flip()` 的次数。

* 空间复杂度：$O(F)$，和执行 `flip()` 的次数成正比。

#### 方法二：分块

我们可以考虑另一种方法来维护这个一维数组 `V`。假设我们把这 `n_rows * n_cols` 个位置放到 `k` 个桶中，第一个桶对应 `V[0 .. a1]`，第二个桶对应 `V[a1 + 1 .. a2]`，以此类推。我们用 `cnt[i]` 表示第 `i` 个桶中还剩下几个 `0`，并给每个桶分配一个集合（HashSet）存放桶中哪些位置对应的是 `1`（即被翻转过）。

假设当前矩阵中还有 `m` 个 `0`，我们从 `[1, m]` 中随机出一个整数 `x`，并遍历所有的桶，根据所有的 `cnt[i]` 可以找出第 `x` 个 `0` 属于哪个桶。假设其属于第 `i` 个桶，那么 `x` 应该满足 `sum[i - 1] < x <= sum[i]`，其中 `sum[i]` 表示前 `i` 个桶的 `cnt[i]` 之和，即前 `i` 个桶中 `0` 的个数。随后我们令 `y = x - sum[i - 1]`，即我们需要找到第 `i` 个桶中的第 `y` 个 `0`。我们可以依次遍历 `[ai + 1 .. a(i+1)]` 中的数，根据第 `i` 个桶对应的集合，找出第 `y` 个 `0` 的位置。最后我们将这个 `0` 进行翻转。

由于 `V` 被分成了 `k` 个桶，因此每个桶的平均长度为 `n / k`，其中 `n = n_rows * n_cols`。在上述的方法中，遍历所有的桶的时间复杂度为 $O(k)$，而遍历第 `i` 个桶的时间复杂度为 $O(n / k)$，因此总时间复杂度为 $O(k + n / k)$。根据均值不等式，可以得知在 $k = \sqrt{n}$ 时间复杂度达到最小值 $O(\sqrt{n})$。

```C++ [sol2]
class Solution {
public:

    int nr, nc, rem, b_size;
    vector<unordered_set<int>> buckets;

    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    //uniform random integer in [0, bound)
    int randint(int bound) {
        uniform_int_distribution<int> uni(0, bound - 1);
        return uni(rng);
    }

    Solution(int n_rows, int n_cols) {
        nr = n_rows, nc = n_cols, rem = nr * nc;
        b_size = sqrt(nr * nc);
        for (int i = 0; i < nr * nc; i += b_size)
            buckets.push_back({});
    }

    vector<int> flip() {
        int c = 0;
        int c0 = 0;
        int k = randint(rem);
        for (auto& b1 : buckets) {
            if (c0 + b_size - b1.size() > k) {
                while (true) {
                    if (!b1.count(c)) {
                        if (c0 == k) {
                            b1.insert(c);
                            rem--;
                            return {c / nc, c % nc};
                        }
                        c0++;
                    }
                    c++;
                }
            }
            c += b_size;
            c0 += b_size - b1.size();
        }
    }

    void reset() {
        for (auto& b1 : buckets)
            b1.clear();
        rem = nr * nc;
    }
};
```

```Java [sol2]
class Solution {

    int nr, nc, rem, b_size;
    List<Set<Integer>> buckets = new ArrayList<>();
    Random rand = new Random();

    public Solution(int n_rows, int n_cols) {
        nr = n_rows;
        nc = n_cols;
        rem = nr * nc;
        b_size = (int) Math.sqrt(nr * nc);
        for (int i = 0; i < nr * nc; i+= b_size)
            buckets.add(new HashSet<Integer>());
    }

    public int[] flip() {
        int c = 0;
        int c0 = 0;
        int k = rand.nextInt(rem);
        for (Set<Integer> b1 : buckets) {
            if (c0 + b_size - b1.size() > k) {
                while (true) {
                    if (!b1.contains(c)) {
                        if (c0 == k) {
                            b1.add(c);
                            rem--;
                            return new int[]{c / nc, c % nc};
                        }
                        c0++;
                    }
                    c++;
                }
            }
            c += b_size;
            c0 += b_size - b1.size();
        }
        return null;
    }

    public void reset() {
        for (Set<Integer> b1 : buckets)
            b1.clear();
        rem = nr * nc;
    }
}
```

**复杂度分析**

* 时间复杂度：`flip()` 操作的时间复杂度为 $O(\sqrt{n})$，`reset()` 操作的时间复杂度为 $O(F)$，其中 $F$ 是在上一次 `reset()` 之后执行 `flip()` 的次数。

* 空间复杂度：$O(\sqrt{n} + F)$。