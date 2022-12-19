#### 方法一：排序

**思路与算法**

对于每一个形如 `A[i] = v` 的元素，我们将其索引 `i` 按照对应值 `v` 排序之后的顺序写下。例如， `A[0] = 7, A[1] = 2, A[2] = 5, A[3] = 4`，我们应该这样顺序写下索引值 `i=1, i=3, i=2, i=0`。

然后，当我们写下一个索引 `i` 的时候，我们可以得到候选的宽度答案 `i - min(indexes_previously_written)` （如果这个值是正数的话）。 我们可以用一个变量 `m` 记录已经写下的最小索引。

```java [Kt7xRu2c-Java]
class Solution {
    public int maxWidthRamp(int[] A) {
        int N = A.length;
        Integer[] B = new Integer[N];
        for (int i = 0; i < N; ++i)
            B[i] = i;

        Arrays.sort(B, (i, j) -> ((Integer) A[i]).compareTo(A[j]));

        int ans = 0;
        int m = N;
        for (int i: B) {
            ans = Math.max(ans, i - m);
            m = Math.min(m, i);
        }

        return ans;
    }
}
```
```python [Kt7xRu2c-Python]
class Solution(object):
    def maxWidthRamp(self, A):
        ans = 0
        m = float('inf')
        for i in sorted(range(len(A)), key = A.__getitem__):
            ans = max(ans, i - m)
            m = min(m, i)
        return ans
```


**复杂度分析**

* 时间复杂度：  $O(N \log N)$，其中 $N$ 是 `A` 的长度。

* 空间复杂度：  $O(N)$，基于排序的实现方法。
  

  


---
#### 方法二：二分检索候选位置

**思路**

按照降序考虑 `i` ， 我们希望找到一个最大的 `j` 满足 `A[j] >= A[i]`（如果存在的话）。

因此，候选的 `j` 应该是降序的：如果存在 `j1 < j2` 并且 `A[j1] <= A[j2]` ，那么我们一定会选择 `j2`。

**算法**

我们使用列表记录这些候选的 `j`。举一个例子，当 `A = [0,8,2,7,5]`，对于 `i = 0` 的候选列表应该是 `candidates = [(v=5, j=4), (v=7, j=3), (v=8, j=1)]`。我们要时刻维护候选列表 `candidates` 按照索引值降序，对应值升序。

现在，我们可以使用二分检索的办法找到最大的索引  `j` 满足 `A[j] >= A[i]`：也就是列表中第一个满足 `v >= A[i]` 的那一项。

```java [JNEANGt6-Java]
import java.awt.Point;

class Solution {
    public int maxWidthRamp(int[] A) {
        int N = A.length;

        int ans = 0;
        List<Point> candidates = new ArrayList();
        candidates.add(new Point(A[N-1], N-1));

        // candidates: i's decreasing, by increasing value of A[i]
        for (int i = N-2; i >= 0; --i) {
            // Find largest j in candidates with A[j] >= A[i]
            int lo = 0, hi = candidates.size();
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (candidates.get(mi).x < A[i])
                    lo = mi + 1;
                else
                    hi = mi;
            }

            if (lo < candidates.size()) {
                int j = candidates.get(lo).y;
                ans = Math.max(ans, j - i);
            } else {
                candidates.add(new Point(A[i], i));
            }
        }
        return ans;
    }
}
```
```python [JNEANGt6-Python]
class Solution(object):
    def maxWidthRamp(self, A):
        N = len(A)

        ans = 0
        candidates = [(A[N-1], N-1)]
        # candidates: i's decreasing, by increasing value of A[i]
        for i in xrange(N-2, -1, -1):
            # Find largest j in candidates with A[j] >= A[i]
            jx = bisect.bisect(candidates, (A[i],))
            if jx < len(candidates):
                ans = max(ans, candidates[jx][1] - i)
            else:
                candidates.append((A[i], i))

        return ans
```


**复杂度分析**

* 时间复杂度：  $O(N \log N)​$，其中 $N​$ 是数组 `A` 的长度。

* 空间复杂度：  $O(N)$。
  

  
