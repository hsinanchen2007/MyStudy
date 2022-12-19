####  方法：哈希表 [通过]
以 `A=[12，28，46]`，`B=[46，12，28]` 为例。我们想知道 `12`，`28`，`46` 在 B 中的位置，如果有一个字典（哈希表）`D = {46: 0, 12: 1, 28: 2}`，那么这个问题可以很轻松的被解决。

**算法：**

按上述创建哈希表 `D`，则答案为 `D[A[i]]，i = 0, 1, ...` 组成的列表。

```python [solution1-Python]
class Solution(object):
    def anagramMappings(self, A, B):
        D = {x: i for i, x in enumerate(B)}
        return [D[x] for x in A]
```

```java [solution1-Java]
class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        Map<Integer, Integer> D = new HashMap();
        for (int i = 0; i < B.length; ++i)
            D.put(B[i], i);

        int[] ans = new int[A.length];
        int t = 0;
        for (int x: A)
            ans[t++] = D.get(x);
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。其中 $N$ 为 $A$ 的长度。
* 空间复杂度：$O(N)$，哈希表所使用的空间。