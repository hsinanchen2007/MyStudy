#### 方法一：曼哈顿距离【通过】

**思想**

曼哈顿距离是指网格中从 `A` 点到 `B` 点的距离，计算公式为 `dist(A, B) = abs(A.x - B.x) + abs(A.y - B.y)`。

假设我们的起点是 `S`，阻碍者的起点是 `G`，目的地是 `T`。如果我们与阻碍者在 `X` 点相遇，则有 `dist(G, X) <= dist(S, X)`，表示阻碍者要么和我们同时到达 `X` 点，要么比我们更早到 `X` 点。

如果阻碍者从 `G` 出发先到达 `X` 再到达 `T`，与直接到达 `T` 相比有 `dist(G, T) <= dist(G, X) + dist(X, T) <= dist(S, X) + dist(X, T)`。因为三角形两边之和大于第三边，所以 `dist(G, T) <= dist(G, X) + dist(X, T)` 一定成立。

以上分析表明，让阻碍者直接到达目的地 `T`，与让阻碍者先到某个点 `X` 再到达目的地 `T` 的结果是一样的。如果阻碍者直接到达目的地会阻碍我们，那么阻碍者也一定会先于我们到达某一点 `X` ，在此与我们相遇；如果阻碍者直接到达目的地不会阻碍我们，那么阻碍者无论怎么走也无法阻碍我们。

因此，这个问题可以简化为我们与所有阻碍者都在最短时间内直接到达目的地是否会与阻碍者相遇。

**算法**

计算我们到目的地的曼哈顿距离是否小于所有阻碍者到达目的地的曼哈顿距离。

```java [solution1-Java]
class Solution {
    public boolean escapeGhosts(int[][] ghosts, int[] target) {
        int[] source = new int[]{0, 0};
        for (int[] ghost: ghosts)
            if (taxi(ghost, target) <= taxi(source, target))
                return false;
        return true;
    }

    public int taxi(int[] P, int[] Q) {
        return Math.abs(P[0] - Q[0]) + Math.abs(P[1] - Q[1]);
    }
}
```

```python [solution1-Python]
class Solution(object):
    def escapeGhosts(self, ghosts, target):
        def taxi(P, Q):
            return abs(P[0] - Q[0]) + abs(P[1] - Q[1])

        return all(taxi([0, 0], target) < taxi(ghost, target)
                   for ghost in ghosts)
```

**复杂度分析**

* 时间复杂度：$O(\text{ghosts}.\text{length})$。

* 空间复杂度：$O(1)$。