#### 方法一：贪心

对于每一列，我们检查它是否是有序的。如果它有序，则将答案增加 1，否则它必须被删除。

```Java [sol1]
class Solution {
    public int minDeletionSize(String[] A) {
        int ans = 0;
        for (int c = 0; c < A[0].length(); ++c)
            for (int r = 0; r < A.length - 1; ++r)
                if (A[r].charAt(c) > A[r+1].charAt(c)) {
                    ans++;
                    break;
                }

        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def minDeletionSize(self, A):
        ans = 0
        for col in zip(*A):
            if any(col[i] > col[i+1] for i in xrange(len(col) - 1)):
                ans += 1
        return ans
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是数组 `A` 中的元素个数。

* 空间复杂度：$O(1)$。