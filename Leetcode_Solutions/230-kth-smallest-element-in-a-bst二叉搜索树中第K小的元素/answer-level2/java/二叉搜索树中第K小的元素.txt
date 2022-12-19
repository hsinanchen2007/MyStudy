####  概述：
**怎么遍历树：**

- 深度优先搜索（`DFS`）

在这个策略中，我们从根延伸到某一片叶子，然后再返回另一个分支。根据根节点，左节点，右节点的相对顺序，`DFS` 还可以分为前序，中序，后序。 

- 广度优先搜索（`BFS`）

在这个策略中，我们逐层，从上到下扫描整个树。

下图展示了不同的遍历策略：
![在这里插入图片描述](https://pic.leetcode-cn.com/40cb9af2a0c21fdc1ce72e6e24b48bd73d5f280c0f4b207ce3d7cf0c19fbdf21-file_1579413216186){:width=500}
{:align=center}

为了解决这个问题，可以使用 BST 的特性：BST 的中序遍历是升序序列。

####  方法一：递归
**算法：**

通过构造 BST 的中序遍历序列，则第 `k-1` 个元素就是第 `k` 小的元素。

![在这里插入图片描述](https://pic.leetcode-cn.com/7dc3fe454519e27105c5aaf57d20b26137bd77c56bb0289830bf18116627de12-file_1579413216156){:width=500}
{:align=center}


```python [solution1-Python]
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def inorder(r):
            return inorder(r.left) + [r.val] + inorder(r.right) if r else []
    
        return inorder(root)[k - 1]
```

```java [solution1-Java]
class Solution {
  public ArrayList<Integer> inorder(TreeNode root, ArrayList<Integer> arr) {
    if (root == null) return arr;
    inorder(root.left, arr);
    arr.add(root.val);
    inorder(root.right, arr);
    return arr;
  }

  public int kthSmallest(TreeNode root, int k) {
    ArrayList<Integer> nums = inorder(root, new ArrayList<Integer>());
    return nums.get(k - 1);
  }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，遍历了整个树。
* 空间复杂度：$O(N)$，用了一个数组存储中序序列。


####  方法二：迭代
**算法：**

在栈的帮助下，可以将方法一的递归转换为迭代，这样可以加快速度，因为这样可以不用遍历整个树，可以在找到答案后停止。

![在这里插入图片描述](https://pic.leetcode-cn.com/25159a5137867644b75f203ee1917645d2cd454d8f4871e371d7edfa67bef083-file_1579413216176){:width=500}
{:align=center}


```python [solution2-Python]
class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        stack = []
        
        while True:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            k -= 1
            if not k:
                return root.val
            root = root.right
```

```java [solution2-Java]
class Solution {
  public int kthSmallest(TreeNode root, int k) {
    LinkedList<TreeNode> stack = new LinkedList<TreeNode>();

    while (true) {
      while (root != null) {
        stack.add(root);
        root = root.left;
      }
      root = stack.removeLast();
      if (--k == 0) return root.val;
      root = root.right;
    }
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(H + k)$，其中 $H$ 指的是树的高度，由于我们开始遍历之前，要先向下达到叶，当树是一个平衡树时：复杂度为 $\mathcal{O}(\log N + k)$。当树是一个不平衡树时：复杂度为 $\mathcal{O}(N + k)$，此时所有的节点都在左子树。
* 空间复杂度：$\mathcal{O}(H + k)$。当树是一个平衡树时：$\mathcal{O}(\log N + k)$。当树是一个非平衡树时：$\mathcal{O}(N + k)$。