#### 方法一： 滑动窗口 【通过】

**思路**

首先还是要找到从左边开始最小的块。

**算法**

可以注意到，如果 $a_1, a_2, \dots, a_m$ 是一个分块，同时 $a_1, a_2, \dots, a_n$ 也是一个分块 ($m < n$)，那么 $a_{m+1}, a_{m+2}, \dots, a_n$ 一定是一个分块。对于这种形式的问题，实际是可以用贪心算法来找到最多的块数的。

我们知道数组 `arr` 在排序之后一定跟整个数组排序后相应的地方完全相同，即 `expect = sorted(arr)`。如果前 `k` 个元素的个数减去排序后前 `k` 个元素的个数都为 `0` 的话，那这前 `k` 个元素是可以成为一个合法的分块的。对于整个数组可以重复这一过程。

用变量 `nonzero` 来计数目前差值不等于 `0` 的字符的个数。

```python [solution1-Python]
class Solution(object):
    def maxChunksToSorted(self, arr):
        count = collections.defaultdict(int)
        ans = nonzero = 0

        for x, y in zip(arr, sorted(arr))
            count[x] += 1
            if count[x] == 0: nonzero -= 1
            if count[x] == 1: nonzero += 1

            count[y] -= 1
            if count[y] == -1: nonzero += 1
            if count[y] == 0: nonzero -= 1

            if nonzero == 0: ans += 1

        return ans
```

```java [solution1-Java]
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Map<Integer, Integer> count = new HashMap();
        int ans = 0, nonzero = 0;

        int[] expect = arr.clone();
        Arrays.sort(expect);

        for (int i = 0; i < arr.length; ++i) {
            int x = arr[i], y = expect[i];

            count.put(x, count.getOrDefault(x, 0) + 1);
            if (count.get(x) == 0) nonzero--;
            if (count.get(x) == 1) nonzero++;

            count.put(y, count.getOrDefault(y, 0) - 1);
            if (count.get(y) == -1) nonzero++;
            if (count.get(y) == 0) nonzero--;

            if (nonzero == 0) ans++;
        }

        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N \log N)$，其中 $N$ 为 `arr` 的长度。

* 空间复杂度: $O(N)$。

#### 方法二： 排序计数 【通过】

**思路**

与前一种方法相同，还是要找到从左边开始最小的块，对于这个分块 `expect = sorted(arr)`。

在元素各不相同的情况下，找到最小的 `k` 只要满足 `max(arr[:k+1]) == expect[k]` 就可以了，这时候 `arr[:k+1]` 一定是 `expect[:k+1]` 的某种排列组合。

但题目给出的条件元素是可能重复出现的，这时候就不能这么做了。但可以做一个简单的转换，将元素本身的值加上这个元素出现的个数作为一个组合，这个组合是一定唯一的。

**算法**

用 `(x, count)` 来代替 `x`，其中 `count` 的取值范围为 `1` 到 `x` 出现在 `arr` 中的数量。

用 `cur` 来表示 `counted[:k+1]` 的累计和，在 `Y=expect[k]` 的情况下，分块次数就可以加 `1`。

```python [solution2-Python]
class Solution(object):
    def maxChunksToSorted(self, arr):
        count = collections.Counter()
        counted = []
        for x in arr:
            count[x] += 1
            counted.append((x, count[x]))

        ans, cur = 0, None
        for X, Y in zip(counted, sorted(counted)):
            cur = max(cur, X)
            if cur == Y:
                ans += 1
        return ans
```

```java [solution2-Java]
class Solution {
    public int maxChunksToSorted(int[] arr) {
        Map<Integer, Integer> count = new HashMap();
        List<Pair> counted = new ArrayList();
        for (int x: arr) {
            count.put(x, count.getOrDefault(x, 0) + 1);
            counted.add(new Pair(x, count.get(x)));
        }

        List<Pair> expect = new ArrayList(counted);
        Collections.sort(expect, (a, b) -> a.compare(b));

        Pair cur = counted.get(0);
        int ans = 0;
        for (int i = 0; i < arr.length; ++i) {
            Pair X = counted.get(i), Y = expect.get(i);
            if (X.compare(cur) > 0) cur = X;
            if (cur.compare(Y) == 0) ans++;
        }

        return ans;
    }
}

class Pair {
    int val, count;
    Pair(int v, int c) {
        val = v; count = c;
    }
    int compare(Pair that) {
        return this.val != that.val ? this.val - that.val : this.count - that.count;
    }
}
```

**复杂度分析**

* 时间复杂度: $O(N \log N)$，其中 $N$ 为数组 `arr` 的长度。

* 空间复杂度: $O(N)$。