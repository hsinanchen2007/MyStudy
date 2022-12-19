#### 二叉搜索树

二叉搜索树是一棵二叉树，每个节点都有以下特性：

- 大于左子树上任意一个节点的值，

- 小于右子树上任意一个节点的值。

一个二叉搜索树的例子：

![](https://pic.leetcode-cn.com/Figures/700/bst.png){:width=480}

二叉搜索树中复杂度为对数时间的操作：

- 查找。

- [插入](https://leetcode.com/articles/insert-into-a-bst/)。

- [删除](https://leetcode.com/articles/delete-node-in-a-bst/)。


#### 方法一：递归

**算法**

递归实现非常简单：

- 如果根节点为空 `root == null` 或者根节点的值等于搜索值 `val == root.val`，返回根节点。

- 如果 `val < root.val`，进入根节点的左子树查找 `searchBST(root.left, val)`。

- 如果 `val > root.val`，进入根节点的右子树查找 `searchBST(root.right, val)`。

- 返回根节点。

![](https://pic.leetcode-cn.com/Figures/700/recursion.png){:width=480}

**实现**

```java [solution1-Java]
class Solution {
  public TreeNode searchBST(TreeNode root, int val) {
    if (root == null || val == root.val) return root;

    return val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
  }
}
```

```python [solution1-Python]
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None or val == root.val:
            return root
        
        return self.searchBST(root.left, val) if val < root.val \
            else self.searchBST(root.right, val)
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(H)$，其中 $H$ 是树高。平均时间复杂度为 $\mathcal{O}(\log N)$，最坏时间复杂度为 $\mathcal{O}(N)$。
    使用[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)计算时间复杂度。
    $T(N) = aT\left(\frac{N}{b}\right) + \Theta(N^d)$。 
    该公式表示花费 $\Theta(N^d)$ 时间分解一个问题，得到 $a$ 个规模为 $\frac{N}{b}$ 的子问题。
    在二叉搜索中，每次分解后只有一个子问题 `a = 1`，其规模为初始问题的一半 `b = 2`，每次分解花费恒定时间 `d = 0`，即 $\log_b{a} = d$。
    根据主定理，时间复杂度为 $\mathcal{O}(n^{\log_b{a}} \log^{d + 1} N) = \mathcal{O}(\log N)$。

* 空间复杂度：$\mathcal{O}(H)$，递归栈的深度为 $H$。平均情况下深度为 $\mathcal{O}(\log N)$，最坏情况下深度为 $\mathcal{O}(N)$。


#### 方法二：迭代

为了降低空间复杂度，将递归转换为迭代：

- 如果根节点不空 `root != null` 且根节点不是目的节点 `val != root.val`：

    - 如果 `val < root.val`，进入根节点的左子树查找 `root = root.left`。
    
    - 如果 `val > root.val`，进入根节点的右子树查找 `root = root.right`。

- 返回 `root`。

![](https://pic.leetcode-cn.com/Figures/700/iteration.png){:width=480}

**实现**

```java [solution2-Java]
class Solution {
  public TreeNode searchBST(TreeNode root, int val) {
    while (root != null && val != root.val)
      root = val < root.val ? root.left : root.right;
    return root;
  }
}
```

```python [solution2-Python]
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        while root is not None and root.val != val:
            root = root.left if val < root.val else root.right
        return root
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(H)$，其中 $H$ 是树高。平均时间复杂度为 $\mathcal{O}(\log N)$，最坏时间复杂度为 $\mathcal{O}(N)$。
    使用[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)计算时间复杂度。
    $T(N) = aT\left(\frac{N}{b}\right) + \Theta(N^d)$。 
    该公式表示花费 $\Theta(N^d)$ 时间分解一个问题，得到 $a$ 个规模为 $\frac{N}{b}$ 的子问题。
    在二叉搜索中，每次分解后只有一个子问题 `a = 1`，其规模为初始问题的一半 `b = 2`，每次分解花费恒定时间 `d = 0`，即 $\log_b{a} = d$。
    根据主定理，时间复杂度为 $\mathcal{O}(n^{\log_b{a}} \log^{d + 1} N) = \mathcal{O}(\log N)$。

* 空间复杂度：$\mathcal{O}(1)$，恒定的额外空间。