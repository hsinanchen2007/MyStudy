####  方法一：线性时间
**算法：**

最简单的解决方法就是用递归一个一个的计算节点。

```python [solution1-Python]
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        return 1 + self.countNodes(root.right) + self.countNodes(root.left) if root else 0
```

```java [solution1-Java]
class Solution {
  public int countNodes(TreeNode root) {
    return root != null ? 1 + countNodes(root.right) + countNodes(root.left) : 0;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。
* 空间复杂度：$\mathcal{O}(d) = \mathcal{O}(\log N)$，其中 $d$ 指的是树的的高度，运行过程中堆栈所使用的空间。


####  方法二：二分搜索
方法一没有利用完全二叉树的特性。完全二叉树中，除了最后一层外，其余每层节点都是满的，并且最后一层的节点全部靠向左边。

这说明如果第 `k` 层不是最后一层，则在第 `k` 层中将有 `2^k` 个节点。由于最有一层可能没有完全填充，则节点数在 `1` 到 `2^d` 之间，其中 `d` 指的是树的高度。

![在这里插入图片描述](https://pic.leetcode-cn.com/2293520a523283862915355971ed5be3f814e85e7b0381494a837e56a929bb31-file_1579413022832){:width=500}
{:align=center}

我们可以直接计算除了最后一层以外的所有结点个数：$\sum_{k = 0}^{k = d - 1}{2^k} = 2^d - 1$。那么我们可以将问题简化为计算完全二叉树最后一层有多少个节点。

![在这里插入图片描述](https://pic.leetcode-cn.com/94f3ee424f71a9bb30b64593eddd69fa0f27b101e1e44d9e196437524d365b34-file_1579413022881){:width=500}
{:align=center}

现在有两个问题：
1. 最后一层我们需要检查多少个节点？
2. 一次检查的最佳的时间性能是什么？

让我们从第一个问题开始思考。最后一层的叶子节点全部靠向左边，我们可以用二分搜索只检查 $\log(2^d) = d$ 个叶子代替检查全部叶子。

![在这里插入图片描述](https://pic.leetcode-cn.com/15f4b68c947aa61183ef42f97d2520ee2e8d1de5c6ce69dedda32e2c0367f248-file_1579413022897){:width=500}
{:align=center}

让我们思考第二个问题，最后一层的叶子节点索引在 `0` 到 `$2^d - 1$` 之间。如何检查第 `idx` 节点是否存在？让我们来用二分搜索来构造从根节点到 `idx` 的移动序列。如，`idx = 4`。`idx` 位于 `0,1,2,3,4,5,6,7` 的后半部分，因此第一步是向右移动；然后 `idx` 位于 `4,5,6,7` 的前半部分，因此第二部是向左移动；`idx` 位于 `4,5` 的前半部分，因此下一步是向左移动。一次检查的时间复杂度为 $\mathcal{O}(d)$。

![在这里插入图片描述](https://pic.leetcode-cn.com/1eb3983f8ed6ae77a8c903c48590d48dda68f11e91ce8da8f59325fd8835a42c-file_1579413022902){:width=500}
{:align=center}

我们需要 $\mathcal{O}(d)$ 次检查，一次检查需要 $\mathcal{O}(d)$，所以总的时间复杂度为 $\mathcal{O}(d^2)$。

**算法：**

- 如果树为空，返回 `0`。
- 计算树的高度 `d`。
- 如果 `d == 0`，返回 `1`。
- 除最后一层以外的所有节点数为 `2^d-1`。最后一层的节点数通过二分搜索，检查最后一层有多少个节点。使用函数 `exists(idx, d, root)` 检查第 `idx` 节点是否存在。
- 使用二分搜索实现 `exists(idx, d, root)`。
- 返回 `2^d - 1 + 最后一层的节点数`。


```python [solution2-Python]
class Solution:
    def compute_depth(self, node: TreeNode) -> int:
        """
        Return tree depth in O(d) time.
        """
        d = 0
        while node.left:
            node = node.left
            d += 1
        return d

    def exists(self, idx: int, d: int, node: TreeNode) -> bool:
        """
        Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        Return True if last level node idx exists. 
        Binary search with O(d) complexity.
        """
        left, right = 0, 2**d - 1
        for _ in range(d):
            pivot = left + (right - left) // 2
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
        return node is not None
        
    def countNodes(self, root: TreeNode) -> int:
        # if the tree is empty
        if not root:
            return 0
        
        d = self.compute_depth(root)
        # if the tree contains 1 node
        if d == 0:
            return 1
        
        # Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
        # Perform binary search to check how many nodes exist.
        left, right = 1, 2**d - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if self.exists(pivot, d, root):
                left = pivot + 1
            else:
                right = pivot - 1
        
        # The tree contains 2**d - 1 nodes on the first (d - 1) levels
        # and left nodes on the last level.
        return (2**d - 1) + left
```

```java [solution2-Java]
class Solution {
  // Return tree depth in O(d) time.
  public int computeDepth(TreeNode node) {
    int d = 0;
    while (node.left != null) {
      node = node.left;
      ++d;
    }
    return d;
  }

  // Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
  // Return True if last level node idx exists. 
  // Binary search with O(d) complexity.
  public boolean exists(int idx, int d, TreeNode node) {
    int left = 0, right = (int)Math.pow(2, d) - 1;
    int pivot;
    for(int i = 0; i < d; ++i) {
      pivot = left + (right - left) / 2;
      if (idx <= pivot) {
        node = node.left;
        right = pivot;
      }
      else {
        node = node.right;
        left = pivot + 1;
      }
    }
    return node != null;
  }

  public int countNodes(TreeNode root) {
    // if the tree is empty
    if (root == null) return 0;

    int d = computeDepth(root);
    // if the tree contains 1 node
    if (d == 0) return 1;

    // Last level nodes are enumerated from 0 to 2**d - 1 (left -> right).
    // Perform binary search to check how many nodes exist.
    int left = 1, right = (int)Math.pow(2, d) - 1;
    int pivot;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (exists(pivot, d, root)) left = pivot + 1;
      else right = pivot - 1;
    }

    // The tree contains 2**d - 1 nodes on the first (d - 1) levels
    // and left nodes on the last level.
    return (int)Math.pow(2, d) - 1 + left;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(d^2) = \mathcal{O}(\log^2 N)$，其中 $d$ 指的是树的高度。 
* 空间复杂度：$\mathcal{O}(1)$。