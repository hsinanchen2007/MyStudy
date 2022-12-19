#### 想法

如果 `x` 是当前数组中绝对值最小的元素，那么它一定会配对 `2*x`，因为不存在 `x/2` 可以和它配对。

#### 算法

直接改写最后的结果数组。

按照绝对值大小检查整个数组。当检查到元素 `x` 并且没有被使用时，它一定要配对 `2*x`。我们将尝试记录 `x，2x`。如果没有元素 `2x` 则返回答案 `false`。如果所有元素都被访问，答案是 `true`。

为了记录哪些元素还没有被访问，可以用 `count` 来记录。

```java []
class Solution {
    public boolean canReorderDoubled(int[] A) {
        // count[x] = the number of occurrences of x in A
        Map<Integer, Integer> count = new HashMap();
        for (int x: A)
            count.put(x, count.getOrDefault(x, 0) + 1);

        // B = A as Integer[], sorted by absolute value
        Integer[] B = new Integer[A.length];
        for (int i = 0; i < A.length; ++i)
            B[i] = A[i];
        Arrays.sort(B, Comparator.comparingInt(Math::abs));

        for (int x: B) {
            // If this can't be consumed, skip
            if (count.get(x) == 0) continue;
            // If this doesn't have a doubled partner, the answer is false
            if (count.getOrDefault(2*x, 0) <= 0) return false;

            // Write x, 2*x
            count.put(x, count.get(x) - 1);
            count.put(2*x, count.get(2*x) - 1);
        }

        // If we have written everything, the answer is true
        return true;
    }
}
```

```python []
class Solution(object):
    def canReorderDoubled(self, A):
        count = collections.Counter(A)
        for x in sorted(A, key = abs):
            if count[x] == 0: continue
            if count[2*x] == 0: return False
            count[x] -= 1
            count[2*x] -= 1

        return True
```

#### 算法复杂度

* 时间复杂度：$O(N \log{N})$，其中 $N$ 是数组 `A` 的长度。
* 空间复杂度：$O(N)$。
