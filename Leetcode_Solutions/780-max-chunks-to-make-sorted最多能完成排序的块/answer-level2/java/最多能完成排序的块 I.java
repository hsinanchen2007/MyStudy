#### 方法一： 暴力

**思路和算法**

首先找到从左块开始最小块的大小。如果前 `k` 个元素为 `[0, 1, ..., k-1]`，可以直接把他们分为一个块。当我们需要检查 `[0, 1, ..., n-1]` 中前 `k+1` 个元素是不是 `[0, 1, ..., k]` 的时候，只需要检查其中最大的数是不是 `k` 就可以了。

```python [solution1-Pyton]
class Solution(object):
    def maxChunksToSorted(self, arr):
        ans = ma = 0
        for i, x in enumerate(arr):
            ma = max(ma, x)
            if ma == i: ans += 1
        return ans
```

```java [solution2-Java]
class Solution {
    public int maxChunksToSorted(int[] arr) {
        int ans = 0, max = 0;
        for (int i = 0; i < arr.length; ++i) {
            max = Math.max(max, arr[i]);
            if (max == i) ans++;
        }
        return ans;
    }
}
```


**复杂度分析**

* 时间复杂度: $O(N)$，其中 $N$ 为数组 `arr` 的长度。

* 空间复杂度: $O(1)$。