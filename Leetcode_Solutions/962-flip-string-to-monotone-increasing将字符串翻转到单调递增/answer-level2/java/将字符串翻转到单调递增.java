#### 方法一：前缀和

**思路**

对于一个包含 5 个数字的字符串来说，答案可能是 `'00000'`，`'00001'`，`'00011'`，`'00111'`，`'01111'`，`'11111'` 中的任何一个。可以依次原始字符串转换成每个答案的代价，其中计算分成两个部分，左边全 `0` 的部分和右边全 `1` 的部分。

显然，这个问题可以简化成： 对于每种分割方法，左边有多少个 `1` 需要去反转，右边有多少个 `0` 需要去反转。

对这个问题，可以用全缀和来解决。定义 `P[i+1] = A[0] + A[1] + ... + A[i]`，`P` 可以在线性时间计算出来。

假设最终答案是 `x` 个 `0` 跟 `N - x` 个 `1`，那么就必须反转 `P[x]` 个 `1`， `(N-x) - (P[N] - P[x])` 个 `0`。 其中 `P[N] - P[x]` 是右边全 `1` 部分原本 `1` 的个数。

**算法**

举个例子，对于 `S = "010110"`： `P = [0, 0, 1, 1, 2, 3, 3]`。假设 `x=3`，即最终答案左边有三个 `0`。

有 `P[3] = 1` 个 `1` 在左边全 `0` 部分，`P[6] - P[3] = 2` 个 `1` 在右边全 `1` 部分。

所以，左边有 `P[3] = 1` 个 `1` 需要反转，右边有 `(N-x) - (P[N] - P[x]) = 1` 个 `0` 需要去反转。

```java [solution1-Java]
class Solution {
    public int minFlipsMonoIncr(String S) {
        int N = S.length();
        int[] P = new int[N + 1];
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + (S.charAt(i) == '1' ? 1 : 0);

        int ans = Integer.MAX_VALUE;
        for (int j = 0; j <= N; ++j) {
            ans = Math.min(ans, P[j] + N-j-(P[N]-P[j]));
        }

        return ans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def minFlipsMonoIncr(self, S):
        P = [0]
        for x in S:
            P.append(P[-1] + int(x))

        return min(P[j] + len(S)-j-(P[-1]-P[j])
                   for j in xrange(len(P)))
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是 `S` 的长度。

* 空间复杂度： $O(N)$。