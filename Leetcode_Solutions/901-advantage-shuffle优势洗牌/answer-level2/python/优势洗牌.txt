#### 方法：贪心

**思路**

如果 `A` 中最小的牌 `a` 能击败 `B` 中最小的牌 `b`，那么我们应当将它们配对。否则， `a` 将无益于我们的比分，因为它无法击败任何牌。

我们为什么要在 `a > b` 时将 `a` 和 `b` 配对呢？这是因为此时在 `A` 中的每张牌都比 `b` 要大，所以不管我们在 `b` 前面放置哪张牌都可以得分。我们可以用手中最弱的牌来与 `b` 配对，这样会使 `A` 中剩余的牌严格地变大，因此会有更多得分点。

**算法**

我们可以根据上面的思路来创造一种贪心算法。目前在 `B` 中要被击败的最小的牌将始终是 `b = sortedB[j]`。对于在 `sortedA` 中的每张卡 `a`，要么 `a` 能够击败牌 `b`（将 `a` 放入 `assigned[b]`），要么把 `a` 扔掉（将 `a` 放入 `remaining`）。

之后，我们可以使用此前标注的 `assigned` 和 `remaining` 来重构答案。详细情况请查阅注释。


```java [L5ToovSe-Java]
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        int[] sortedA = A.clone();
        Arrays.sort(sortedA);
        int[] sortedB = B.clone();
        Arrays.sort(sortedB);

        // assigned[b] = list of a that are assigned to beat b
        Map<Integer, Deque<Integer>> assigned = new HashMap();
        for (int b: B) assigned.put(b, new LinkedList());

        // remaining = list of a that are not assigned to any b
        Deque<Integer> remaining = new LinkedList();

        // populate (assigned, remaining) appropriately
        // sortedB[j] is always the smallest unassigned element in B
        int j = 0;
        for (int a: sortedA) {
            if (a > sortedB[j]) {
                assigned.get(sortedB[j++]).add(a);
            } else {
                remaining.add(a);
            }
        }

        // Reconstruct the answer from annotations (assigned, remaining)
        int[] ans = new int[B.length];
        for (int i = 0; i < B.length; ++i) {
            // if there is some a assigned to b...
            if (assigned.get(B[i]).size() > 0)
                ans[i] = assigned.get(B[i]).pop();
            else
                ans[i] = remaining.pop();
        }
        return ans;
    }
}
```
```python [L5ToovSe-Python]
class Solution(object):
    def advantageCount(self, A, B):
        sortedA = sorted(A)
        sortedB = sorted(B)

        # assigned[b] = list of a that are assigned to beat b
        # remaining = list of a that are not assigned to any b
        assigned = {b: [] for b in B}
        remaining = []

        # populate (assigned, remaining) appropriately
        # sortedB[j] is always the smallest unassigned element in B
        j = 0
        for a in sortedA:
            if a > sortedB[j]:
                assigned[sortedB[j]].append(a)
                j += 1
            else:
                remaining.append(a)

        # Reconstruct the answer from annotations (assigned, remaining)
        return [assigned[b].pop() if assigned[b] else remaining.pop()
                for b in B]
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是 `A` 和 `B` 的长度。

* 空间复杂度：$O(N)$。