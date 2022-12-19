#### 方法 1：前缀和与二分搜索

**想法**

让 $\text{tot} = \sum_{i=0}^{N-1}w[i]$ ，其中 $N = \text{len}(w)$。

如果我们从 [半开区间](http://mathworld.wolfram.com/Half-ClosedInterval.html) $[0, \text{tot})$ 中随机选择一个整数会发生什么？

是否有办法将每一个可能的整数映射到 $w$ 中一个下标，使得每个下标映射的数目与下标的权重对应呢？

是否有办法使用少于 $O(\text{tot})$ 的空间呢？

**算法**

求出前缀和数组 $p$，其中 $p[x] = \sum_{i=0}^{x}w[i]$。

在范围 $[0, \text{tot})$ 中随机选择一个整数 $\text{targ}$。

使用二分查找来找到下标 $x$，其中 $x$ 是满足 $\text{targ} < p[x]$ 的最小下标。

对于某些下标 $i$，所有满足 $p[i] - w[i] \leq v < p[i]$ 的整数 $v$ 都映射到这个下标。因此，所有的下标都与下标权重成比例。

```C++ []
class Solution {
public:
    vector<int> psum;
    int tot = 0;
    //c++11 random integer generation
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;

    Solution(vector<int> w) {
        for (int x : w) {
            tot += x;
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int>{0, tot - 1};
    }

    int pickIndex() {
        int targ = uni(rng);

        int lo = 0, hi = psum.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
```

```Java []
class Solution {

    List<Integer> psum = new ArrayList<>();
    int tot = 0;
    Random rand = new Random();

    public Solution(int[] w) {
        for (int x : w) {
            tot += x;
            psum.add(tot);
        }
    }

    public int pickIndex() {
        int targ = rand.nextInt(tot);

        int lo = 0;
        int hi = psum.size() - 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            if (targ >= psum.get(mid)) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$ 的预处理。 $\text{priceIndex}$ 需要花费 $O(\log(N))$ 的时间。
* 空间复杂度：$O(N)$。
