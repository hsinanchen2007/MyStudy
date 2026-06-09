####  方法一：插入到排序结构中 
让我们按开花的顺序添加花。当每一朵花开花时，我们会检查它的邻居，看他们是否能满足当前的条件。

**算法：**
我们将维护 `active`、排序的数据结构，其中包含当前开花的每一朵花。当我们在 `active` 中添加一朵花时，我们应该检查它是应该放在哪。如果某个邻居满足了这个条件，我们就知道这个条件是在今天发生的。 

**复杂度分析**

* 时间复杂度(Java)：$O(N \log N)$。其中 $N$ 是花的长度。每次插入和搜索都是 $O(\log N)$。 
* 时间复杂度(Python)：$O(N^2)$。如上所述，除了`list.insert` 是 $O(N)$。  
* 空间复杂度：$O(N)$，`active` 的大小。


####  方法二：最小队列 
对于花盆中 `K` 个相邻块（“窗口”），如果此窗口的最小开花日期大于左邻居和右邻居的开花日期，我们知道它满足问题陈述中的条件。 

由于这些窗口重叠，我们可以使用滑动窗口结构更有效地计算答案。 

**算法：**
- `days[x] = i` 是第 `x` 花盆的花开花的时间。对于k天的每个窗口，让我们使用 `MinQueue`（为该任务构建的数据结构）在固定时间内查询该窗口的最小值。如果这个最小值大于它的两个邻居，那么我们知道这是一个发生 “k空槽” 的地方，我们记录下这个候选答案。 
- 要操作 `MinQueue`，关键是不变量 `mins` 是查询 `MinQueue.min` 的候选答案的增加列表。 
- 例如，如果队列是 `[1, 3, 6, 2, 4, 8]`，那么 `mins` 将是 `[1, 2, 4, 8]`。当我们 `MinQueue.popleft` 时，`mins` 将变为 `[2, 4, 8]`，然后在 `3` 个 `popleft` 之后将变为 `[4, 8]`，再 `1` 个 `popleft` 之后将变为 `[8]`。 
- 在 `MinQueue.append` 中，我们应该维护这个不变量。我们通过弹出任何大于插入元素的元素来实现。例如，如果我们将 `5` 添加到 `[1, 3, 6, 2, 4, 8]`，那么 `mins`（即 `[1, 2, 4, 8]` 变为 `[1, 2, 4, 5]`。

**复杂度分析**

* 时间复杂度： $O(N)$。其中 $N$ 是花盆的长度。
* 空间复杂度：$O(N)$，`window` 的大小。


####  方法三：滑动窗口
在方法 2 中， `days[x] = i` 为在位置 `x` 处的花开花的时间。我们希望找到候选间隔 `[left, right]`，其中 `days[left], days[right]` 是 `[days[left], days[left+1], ..., days[right]]` 中的两个最小值且 `right - left = k + 1` 。

这些候选间隔不能相交：例如，如果候选间隔为 `[left1, right1]` 和 `[left2, right2]` 且`left1<left2<right1<right2`，则有 `days[left2] > days[right1]` 和 `days[right1] > days[left2]` 产生矛盾。

**算法：** 
- 和方法 2 一样，我们构建了数组 `days`。 
- 然后，对于每个间隔 `[left, right]`（从第一个有效的间隔开始），我们将检查它是否是一个候选答案：对于 `left < i < right`，是否是 `days[i] > days[left]` 和 `days[i] > days[right]`。 
- 如果检索失败了，那么我们从未访问过的最小的 `days[i]` 开始，我们应该检查新的间隔 `[i, i+k+1]`。如果符合条件，那么这是一个候选答案，我们将检查新的间隔 `[right, right+k+1]`。 

```Python [ ]
class Solution(object):
    def kEmptySlots(self, flowers, k):
        days = [0] * len(flowers)
        for day, position in enumerate(flowers, 1):
            days[position - 1] = day

        ans = float('inf')
        left, right = 0, k+1
        while right < len(days):
            for i in xrange(left + 1, right):
                if days[i] < days[left] or days[i] < days[right]:
                    left, right = i, i+k+1
                    break
            else:
                ans = min(ans, max(days[left], days[right]))
                left, right = right, right+k+1

        return ans if ans < float('inf') else -1
```

```Java [ ]
class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] days = new int[flowers.length];
        for (int i = 0; i < flowers.length; i++) {
            days[flowers[i] - 1] = i + 1;
        }

        int ans = Integer.MAX_VALUE;
        int left = 0, right = k+1;

        search: while (right < days.length) {
            for (int i = left+1; i < right; ++i) {
                if (days[i] < days[left] || days[i] < days[right]) {
                    left = i;
                    right = i + k + 1;
                    continue search;
                }
            }
            ans = Math.min(ans, Math.max(days[left], days[right]));
            left = right;
            right = left + k + 1;
        }

        return ans < Integer.MAX_VALUE ? ans : -1;
    }
}
```

**复杂度分析**

* 时空复杂度： $O(N)$。分析与方法 2 中的分析相同。