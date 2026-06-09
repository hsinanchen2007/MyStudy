#### 方法一：堆 [超出时间限制]

使用堆可以帮我们找到第 `k` 小值。我们将数组排序，此时对于固定的下标 `i`，从小到大的距离分别为 `(i, i + 1)`，`(i, i + 2)`，...，`(i, N - 1)`。因为 `(i, j + 1)` 的距离不会小于 `(i, j)`，因此如果 `(i, j)` 还在堆中，我们没有必要把 `(i, j + 1)` 放入堆中。

因此，我们首先将所有 `(i, i + 1)` 放入堆中，即 `heap = [(i, i + 1) for all i]`。每次取出堆中的最小元素 `(i, j)` 时（元素的大小为 `nums[j] - nums[i]`，即距离），再把 `(i, j + 1)` 放入堆中。直到取出 `k` 个元素，就得到了第 `k` 小的距离。

```Python [sol1]
class Solution(object):
    def smallestDistancePair(self, nums, k):
        nums.sort()
        heap = [(nums[i+1] - nums[i], i, i+1)
                for i in xrange(len(nums) - 1)]
        heapq.heapify(heap)

        for _ in xrange(k):
            d, root, nei = heapq.heappop(heap)
            if nei + 1 < len(nums):
                heapq.heappush((nums[nei + 1] - nums[root], root, nei + 1))

        return d
```

```Java [sol1]
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        PriorityQueue<Node> heap = new PriorityQueue<Node>(nums.length,
            Comparator.<Node> comparingInt(node -> nums[node.nei] - nums[node.root]));
        for (int i = 0; i + 1 < nums.length; ++i) {
            heap.offer(new Node(i, i+1));
        }

        Node node = null;
        for (; k > 0; --k) {
            node = heap.poll();
            if (node.nei + 1 < nums.length) {
                heap.offer(new Node(node.root, node.nei + 1));
            }
        }
        return nums[node.nei] - nums[node.root];
    }
}

class Node {
    int root;
    int nei;
    Node(int r, int n) {
        root = r;
        nei = n;
    }
}
```

**复杂度分析**

* 时间复杂度：$O((k + N) \log N)$，其中 $N$ 为 `nums` 数组的长度。因为 `k` 最大可以达到 `O(N^2)`，因此最坏情况下，时间复杂度为 $O(N^2 \log N)$，超出了时间限制。

* 空间复杂度：$O(N)$。堆中的元素个数是 $O(N)$ 的。

#### 方法二：二分查找 + 前缀和

**分析**

由于第 `k` 小的距离一定在 `[0, W = max(nums) - min(nums)]` 中，我们在这个区间上进行二分。对于当前二分的位置 `guess`，统计距离小于等于 `guess` 的距离对数量，并根据它和 `k` 的关系调整区间的上下界。

我们定义函数 `possible(guess)` 为真，当且仅当距离小于等于 `guess` 的距离对数量比 `k` 大或和 `k` 相等。

**算法**

我们用 `prefix[v]` 表示 `nums` 数组中比 `v` 小或者和 `v` 相等的元素个数，用 `multiplicity[j]` 表示满足 `i < j` 且 `nums[i] == nums[j]` 的 `i` 的个数。这两个数组都可以通过对 `nums` 线性扫描得到。

此时，对于每一个固定的 `i`，满足 `i < j` 且 `nums[j] - nums[i] <= guess` 的 `j` 的个数为 `prefix[x + guess] - prefix[x] + count[i] - multiplicity[i]`，其中 `x = nums[i]`，`count[i]` 表示 `nums[i]` 在数组中出现的次数。我们遍历所有的 `i` 并对上式求和，就得到了所有小于等于 `guess` 的距离对数目。

此外，由于所有 `count[i] - multiplicity[i]` 的和与 `multiplicity[i]` 的和实际上是相等的，在求和时，我们可以把前者替换为后者（但并不会改变时间复杂度）。

```Python [sol1]
class Solution(object):
    def smallestDistancePair(self, nums, k):
        def possible(guess):
            #Is there k or more pairs with distance <= guess?
            return sum(prefix[min(x + guess, W)] - prefix[x] + multiplicity[i]
                       for i, x in enumerate(nums)) >= k

        nums.sort()
        W = nums[-1]

        #multiplicity[i] = number of nums[j] == nums[i] (j < i)
        multiplicity = [0] * len(nums)
        for i, x in enumerate(nums):
            if i and x == nums[i-1]:
                multiplicity[i] = 1 + multiplicity[i - 1]

        #prefix[v] = number of values <= v
        prefix = [0] * (W + 1)
        left = 0
        for i in xrange(len(prefix)):
            while left < len(nums) and nums[left] == i:
                left += 1
            prefix[i] = left

        lo = 0
        hi = nums[-1] - nums[0]
        while lo < hi:
            mi = (lo + hi) / 2
            if possible(mi):
                hi = mi
            else:
                lo = mi + 1

        return lo
```

```Java [sol1]
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int WIDTH = 2 * nums[nums.length - 1];

        //multiplicity[i] = number of nums[j] == nums[i] (j < i)
        int[] multiplicity = new int[nums.length];
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == nums[i-1]) {
                multiplicity[i] = 1 + multiplicity[i - 1];
            }
        }

        //prefix[v] = number of values <= v
        int[] prefix = new int[WIDTH];
        int left = 0;
        for (int i = 0; i < WIDTH; ++i) {
            while (left < nums.length && nums[left] == i) left++;
            prefix[i] = left;
        }

        int lo = 0;
        int hi = nums[nums.length - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0;
            for (int i = 0; i < nums.length; ++i) {
                count += prefix[nums[i] + mi] - prefix[nums[i]] + multiplicity[i];
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(W + N \log W + N \log N)$，其中 $N$ 为 `nums` 数组的长度，$W$ 为 `nums` 数组中最大值与最小值的差，即 `nums[nums.length - 1] - nums[0]`（对 `nums` 数组进行排序之后）。其中计算 `prefix` 的时间复杂度为 $O(W)$，二分查找的时间复杂度为 $\log W$，计算 `possible(guess)` 函数的时间复杂度为 $O(N)$，对 `nums` 数组进行排序的时间复杂度为 $O(N\log N)$。

* 空间复杂度：$O(N + W)$，用来存储数组 `multiplicity` 和 `prefix`。

#### 方法三：二分查找 + 双指针 [通过]

**分析**

在方法二中，我们计算 `possible(guess)` 时用到了很多预先处理好的数组，我们可以优化这个过程，减少预处理的时间复杂度，例如计算 `prefix` 的时间复杂度 $O(W)$。

**方法**

我们可以使用双指针来计算出所有小于等于 `guess` 的距离对数目。我们维护 `left` 和 `right`，其中 `right` 通过循环逐渐递增，`left` 在每次循环中被维护，使得它满足 `nums[right] - nums[left] <= guess` 且最小。这样对于 `nums[right]`，以它为右端的满足距离小于等于 `guess` 的距离对数目即为 `right - left`。我们在循环中对这些 `right - left` 进行累加，就得到了所有小于等于 `guess` 的距离对数目。

```Python [sol3]
class Solution(object):
    def smallestDistancePair(self, nums, k):
        def possible(guess):
            #Is there k or more pairs with distance <= guess?
            count = left = 0
            for right, x in enumerate(nums):
                while x - nums[left] > guess:
                    left += 1
                count += right - left
            return count >= k

        nums.sort()
        lo = 0
        hi = nums[-1] - nums[0]
        while lo < hi:
            mi = (lo + hi) / 2
            if possible(mi):
                hi = mi
            else:
                lo = mi + 1

        return lo
```

```Java [sol3]
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);

        int lo = 0;
        int hi = nums[nums.length - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.length; ++right) {
                while (nums[right] - nums[left] > mi) left++;
                count += right - left;
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1;
        }
        return lo;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N \log W + N \log N)$，其中 $N$ 为 `nums` 数组的长度，$W$ 为 `nums` 数组中最大值与最小值的差，即 `nums[nums.length - 1] - nums[0]`（对 `nums` 数组进行排序之后）。其中二分查找的时间复杂度为 $\log W$，计算 `possible(guess)` 函数的时间复杂度为 $O(N)$，对 `nums` 数组进行排序的时间复杂度为 $O(N\log N)$。

* 空间复杂度：$O(1)$。
