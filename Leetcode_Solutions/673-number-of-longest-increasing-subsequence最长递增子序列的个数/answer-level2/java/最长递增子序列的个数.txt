##  解决方法：
####  方法一：动态规划
**算法：**
- 假设对于以 `nums[i]` 结尾的序列，我们知道最长序列的长度 `length[i]`，以及具有该长度的序列的 `count[i]`。
- 对于每一个 `i<j` 和一个 `A[i]<A[j]`，我们可以将一个 `A[j]` 附加到以 `A[i]` 结尾的最长子序列上。
- 如果这些序列比 `length[j]` 长，那么我们就知道我们有`count[i]` 个长度为 `length` 的序列。如果这些序列的长度与 `length[j]` 相等，那么我们就知道现在有 `count[i]` 个额外的序列（即 `count[j]+=count[i]`）。 

```Python [ ]
class Solution(object):
    def findNumberOfLIS(self, nums):
        N = len(nums)
        if N <= 1: return N
        lengths = [0] * N #lengths[i] = longest ending in nums[i]
        counts = [1] * N #count[i] = number of longest ending in nums[i]

        for j, num in enumerate(nums):
            for i in xrange(j):
                if nums[i] < nums[j]:
                    if lengths[i] >= lengths[j]:
                        lengths[j] = 1 + lengths[i]
                        counts[j] = counts[i]
                    elif lengths[i] + 1 == lengths[j]:
                        counts[j] += counts[i]

        longest = max(lengths)
        return sum(c for i, c in enumerate(counts) if lengths[i] == longest)
```

```Java [ ]
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int N = nums.length;
        if (N <= 1) return N;
        int[] lengths = new int[N]; //lengths[i] = length of longest ending in nums[i]
        int[] counts = new int[N]; //count[i] = number of longest ending in nums[i]
        Arrays.fill(counts, 1);

        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < j; ++i) if (nums[i] < nums[j]) {
                if (lengths[i] >= lengths[j]) {
                    lengths[j] = lengths[i] + 1;
                    counts[j] = counts[i];
                } else if (lengths[i] + 1 == lengths[j]) {
                    counts[j] += counts[i];
                }
            }
        }

        int longest = 0, ans = 0;
        for (int length: lengths) {
            longest = Math.max(longest, length);
        }
        for (int i = 0; i < N; ++i) {
            if (lengths[i] == longest) {
                ans += counts[i];
            }
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N^2)$。其中 $N$ 是 `nums` 的长度。有两个 for 循环是 $O(1)$。 
* 空间复杂度：$O(N)$，`lengths` 和 `counts` 所用的空间。 


####  方法二：线段树
假设我们知道每一个长度 `L`，长度为 `L` 以 `x` 结尾的序列的数目，那么在考虑 `nums` 的下一个元素时，更新我们知道长度 `L-1` 以 `y<x` 结尾的序列的数目。这种对间隔的查询类型很适合使用某种树。 

我们可以尝试使用 Fenwick 树，但我们必须存储 $N$ 的树，这可能是 $O(N^2)$ 的空间。我们重点介绍一个线段树的实现。 

**算法：**
本文将更详细地讨论如何实现线段树。在这种方法中，我们将尝试一种不使用延迟传播的线段树变体。 

- 首先，让我们称递增子序列的最长长度以及该区间中此类子序列的数量为区间的 “值”。
- 每个节点都知道它正在考虑的 `nums` 值的间隔 `[node.range_left，node.range_right]` 和 `node.val` 
- 它包含有关区间的信息。节点还具有 `node.left` 和 `node.right` 子级，表示区间节点所考虑左右两部分。这些子节点根据需要创建。 
- 现在，`query(node, key)` 将告诉我们由 `node` 指定的区间值，除非我们排除 `key` 以上的任何内容 。当 `key` 超出节点指定的区间时 ，我们返回答案。否则，我们将把区间划分为两个，查询两个区间，然后`merge` 结果。 
- `merge(v1, v2)` 的作用是什么？假设两个节点指定相邻的区间，并具有相应的值 `v1 = node1.val, v2 = node2.val`。`v=merge(v1, v2)` 应该是什么？如果一个节点中有较长的子序列，那么 `v` 就是它。如果两个节点都有长度相等的最长子序列，那么我们应该计算两个节点中的子序列。请注意，我们不必考虑产生较大子序列的情况，因为这些子序列是由 `insert` 处理的。 
- `insert(node, key, val)` 是什么功能？我们重复地将 `key` 插入节点指定的区间（可能是一个点），插入之后，该节点的值可能会更改，因此我们再次将这些值合并在一起。 
- 最后，在我们的主算法中，对于 `num in nums`，我们 `query` 值 `length`、 num 以下区间的 `count `，我们将计算 `count` 长度为 `length + 1` 的其他序列。然后我们用这些更新我们的树。 

```Java [ ]
class Solution {
    public Value merge(Value v1, Value v2) {
        if (v1.length == v2.length) {
            if (v1.length == 0) return new Value(0, 1);
            return new Value(v1.length, v1.count + v2.count);
        }
        return v1.length > v2.length ? v1 : v2;
    }

    public void insert(Node node, int key, Value val) {
        if (node.range_left == node.range_right) {
            node.val = merge(val, node.val);
            return;
        } else if (key <= node.getRangeMid()) {
            insert(node.getLeft(), key, val);
        } else {
            insert(node.getRight(), key, val);
        }
        node.val = merge(node.getLeft().val, node.getRight().val);
    }

    public Value query(Node node, int key) {
        if (node.range_right <= key) return node.val;
        else if (node.range_left > key) return new Value(0, 1);
        else return merge(query(node.getLeft(), key), query(node.getRight(), key));
    }

    public int findNumberOfLIS(int[] nums) {
        if (nums.length == 0) return 0;
        int min = nums[0], max = nums[0];
        for (int num: nums) {
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        Node root = new Node(min, max);
        for (int num: nums) {
            Value v = query(root, num-1);
            insert(root, num, new Value(v.length + 1, v.count));
        }
        return root.val.count;
    }
}

class Node {
    int range_left, range_right;
    Node left, right;
    Value val;
    public Node(int start, int end) {
        range_left = start;
        range_right = end;
        left = null;
        right = null;
        val = new Value(0, 1);
    }
    public int getRangeMid() {
        return range_left + (range_right - range_left) / 2;
    }
    public Node getLeft() {
        if (left == null) left = new Node(range_left, getRangeMid());
        return left;
    }
    public Node getRight() {
        if (right == null) right = new Node(getRangeMid() + 1, range_right);
        return right;
    }
}

class Value {
    int length;
    int count;
    public Value(int len, int ct) {
        length = len;
        count = ct;
    }
}
```

```Python [ ]
class Node(object):
    def __init__(self, start, end):
        self.range_left, self.range_right = start, end
        self._left = self._right = None
        self.val = 0, 1 #length, count
    @property
    def range_mid(self):
        return (self.range_left + self.range_right) / 2
    @property
    def left(self):
        self._left = self._left or Node(self.range_left, self.range_mid)
        return self._left
    @property
    def right(self):
        self._right = self._right or Node(self.range_mid + 1, self.range_right)
        return self._right

def merge(v1, v2):
    if v1[0] == v2[0]:
        if v1[0] == 0: return (0, 1)
        return v1[0], v1[1] + v2[1]
    return max(v1, v2)

def insert(node, key, val):
    if node.range_left == node.range_right:
        node.val = merge(val, node.val)
        return
    if key <= node.range_mid:
        insert(node.left, key, val)
    else:
        insert(node.right, key, val)
    node.val = merge(node.left.val, node.right.val)

def query(node, key):
    if node.range_right <= key:
        return node.val
    elif node.range_left > key:
        return 0, 1
    else:
        return merge(query(node.left, key), query(node.right, key))

class Solution(object):
    def findNumberOfLIS(self, nums):
        if not nums: return 0
        root = Node(min(nums), max(nums))
        for num in nums:
            length, count = query(root, num-1)
            insert(root, num, (length+1, count))
        return root.val[1]
```


**复杂度分析**

* 时间复杂度：$O(N\log {N})$。其中 $N$ 是 nums 的长度，在我们的主函数中 for 循环中执行 $O(\log{N})$ 工作来 `query` 和 `insert`。  
* 空间复杂度：$O(N)$，线段树使用的空间。