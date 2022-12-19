#### 方法一：模拟

我们直接根据题目描述来模拟每一滴水的流动过程。

当一滴水从 `K` 处落下时，我们首先检查它是否可以向左流动而下降。从 `i = K` 开始，每次向左检查是否有 `height[i - 1] <= height[i]`，否则水不可能继续向左流动。如果此时有 `height[i - 1] < height[i]`，那么 `i - 1` 处就是一个可能的水停止的位置。在检查完毕之后，最小的可能的水停止的位置即为答案，如果没有这样的位置，再用相同的方法向右检查。如果仍然没有这样的位置，那么水会停在 `K` 处。

```Python [sol1]
class Solution(object):
    def pourWater(self, H, V, K):
        for _ in xrange(V):
            for d in (-1, 1):
                i = best = K
                while 0 <= i+d < len(H) and H[i+d] <= H[i]:
                    if H[i+d] < H[i]: best = i+d
                    i += d
                if best != K:
                    H[best] += 1
                    break
            else:
                H[K] += 1
        return H
```

```Java [sol1]
class Solution {
    public int[] pourWater(int[] H, int V, int K) {
        while (V-- > 0) droplet: {
            for (int d = -1; d <= 1; d += 2) {
                int i = K, best = K;
                while (0 <= i+d && i+d < H.length && H[i+d] <= H[i]) {
                    if (H[i+d] < H[i]) best = i + d;
                    i += d;
                }
                if (H[best] < H[K]) {
                    H[best]++;
                    break droplet;
                }
            }
            H[K]++;
        }
        return H;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(V * N)$，其中 `N` 是数组 `heights` 的长度。对于每一滴水，我们在最坏情况下可能会检查整个数组（例如 `K` 在最左或最右侧）。

* 空间复杂度：$O(1)$。