#### 方法一：前缀和与哈希表

**思路**

通常，涉及连续子数组问题的时候，我们使用前缀和来解决。我们令 `P[i] = A[0] + A[1] + ... + A[i]`。那么，每个连续子数组的和 `sum(i, j)` 就可以写成 `P[j] - P[i-1]` （其中 `j > i` 且 `i > 0`） 的形式。那么判断子数组的和能否被 `K` 整除就可以写成 `(P[j] - P[i-1])%K == 0`，根据 [同余定理](https://baike.baidu.com/item/%E5%90%8C%E4%BD%99%E5%AE%9A%E7%90%86/1212360?fr=aladdin) ，只要 `P[j]%K == P[i-1]%K`，就可以保证上面的式子成立。

根据上面的思路，我们只需要一次遍历计算所有前缀和模 `K` 的值的数量，然后用排列组合的方法来计算答案即可。

**算法**

计算所有的 `P[i]` 在模 `K` 的值并使用哈希表统计数量。如果说一共有 $C_x$ 个 $P[i] \equiv x \pmod{K}$。那么，就有 $\sum_x \binom{C_x}{2}$ 个可行的连续子数组。假设 $x$ 为 5，那么两两组合共有 $5*4/2$ 个子数组。

举一个例子，给定数组为 `A = [4,5,0,-2,-3,1]`， `K = 5`。那么 `P = [4,9,9,7,4,5]`，同时 $C_0 = 1, C_2 = 1, C_4 = 4$：

* 对于 $C_4 = 4$（$P[0]$、$P[1]$、$P[2]$、$P[4]$），这表示一共有 $\binom{4}{2} = 6$ 个连续子数组的和能被 $K$ 整除，分别是 $A[1:2]$、$A[1:3]$、$A[1:5]$、$A[2:3]$、$A[2:5]$、$A[3:5]$ （$A[i:j]$ 表示下标从 $i$ 到 $j-1$）。

上面的算法没有考虑到 $P[i]$ 本身就能被 `K` 整除，我们可以在数组 `P` 前面加一个 `0` 处理这种情况。

注意：不同的语言负数取模的值不一定相同，有的语言为负数，对于这种情况需要特殊处理。

**代码**

```golang [fThchWz2-Golang]
func subarraysDivByK(A []int, K int) int {
    m := map[int]int{0: 1}
    sum := 0
    ans := 0
    for i := 0; i < len(A); i++ {
        sum += A[i]
        v := (sum%K + K)%K
        ans += m[v]
        m[v]++
    }
    return ans
}
```

```java [fThchWz2-Java]
class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int N = A.length;
        A[0] %= K;
        for (int i = 1; i < N; ++i)
            A[i] =(A[i] + A[i - 1]) % K;

        int[] count = new int[K];
        count[0]++;
        for (int x: A)
            count[(x % K + K) % K]++;

        int ans = 0;
        for (int v: count)
            ans += v * (v - 1) / 2;
        return ans;
    }
}
```

```python [fThchWz2-Python]
class Solution(object):
    def subarraysDivByK(self, A, K):
        P = [0]
        for x in A:
            P.append((P[-1] + x) % K)

        count = collections.Counter(P)
        return sum(v*(v-1)/2 for v in count.values())
```

```cpp [fThchWz2-cpp]
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map <int, int> pos;
        pos[0]++;
        for (unsigned i = 0; i < A.size(); ++i) {
            A[i] = (((i == 0 ? 0 : A[i - 1]) + A[i]) % K + K) % K;
            pos[A[i]]++;
        }
        int cnt = 0;
        for (auto [k, v]: pos) {
            cnt += (v * (v - 1)) / 2;
        }
        return cnt;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 的长度。

- 空间复杂度：$O(K)$，其中 $K$ 为模数 `K` 的值，哈希表最大为 $K$。