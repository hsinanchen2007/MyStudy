#### 方法一：动态规划【通过】

**思路**

在一个长度为 `k`，以 `pairs[i]` 结尾的数对链中，如果 `pairs[i][1] < pairs[j][0]`，则将该数对加入链中，数对链长度变为 `k+1`。

**算法**

根据数对的第一个数排序所有的数对，`dp[i]` 存储以 `pairs[i]` 结尾的最长链的长度。当 `i < j` 且 `pairs[i][1] < pairs[j][0]` 时，扩展数对链，更新 `dp[j] = max(dp[j], dp[i] + 1)`。

```python [solution1-Python]
class Solution(object): #Time Limit Exceeded
    def findLongestChain(self, pairs):
        pairs.sort()
        dp = [1] * len(pairs)

        for j in xrange(len(pairs)):
            for i in xrange(j):
                if pairs[i][1] < pairs[j][0]:
                    dp[j] = max(dp[j], dp[i] + 1)

        return max(dp)
```

```java [solution1-Java]
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        int N = pairs.length;
        int[] dp = new int[N];
        Arrays.fill(dp, 1);

        for (int j = 1; j < N; ++j) {
            for (int i = 0; i < j; ++i) {
                if (pairs[i][1] < pairs[j][0])
                    dp[j] = Math.max(dp[j], dp[i] + 1);
            }
        }

        int ans = 0;
        for (int x: dp) if (x > ans) ans = x;
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$，其中 $N$ 是 `pairs` 的长度，两层循环共需要 $N^2$ 次计算。

* 空间复杂度：$O(N)$。用于排序和存储数组 `dp`。


#### 方法二：贪心算法【通过】

**思路**

使用贪心思想扩展数对链，在所有可作为下一个数对的集合中选择第二个数最小的数对添加到数对链。

**算法**

根据思路中的描述，按照数对第二个数的升序序列遍历所有数对，如果当前数对可以加入链，则加入。

```python [solution2-Python]
class Solution(object):
    def findLongestChain(self, pairs):
        cur, ans = float('-inf'), 0
        for x, y in sorted(pairs, key = operator.itemgetter(1)):
            if cur < x:
                cur = y
                ans += 1
        return ans
```

```java [solution2-Java]
class Solution {
    public int findLongestChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
        int cur = Integer.MIN_VALUE, ans = 0;
        for (int[] pair: pairs) if (cur < pair[0]) {
            cur = pair[1];
            ans++;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是数对的长度。排序步骤复杂度最高，其余步骤是线性复杂度。

* 空间复杂度：$O(N)$。使用常数空间存储 `cur` 和 `ans`，但是排序的空间复杂度为 $O(N)$，这与使用的语言有关。