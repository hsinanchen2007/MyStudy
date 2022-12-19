####  概述
二叉搜索树的巨大优势就是：在平均情况下，能够在 $\mathcal{O}(\log N)$ 的时间内完成搜索和插入元素。

二叉搜索树的插入方法非常简单，我们将插入的节点作为叶子节点的子节点插入。插入到哪个叶节点可以遵循以下原则：
- 若 `val > node.val`，插入到右子树。
- 若 `val < node.val`，插入到左子树。

![在这里插入图片描述](https://pic.leetcode-cn.com/d5278ceb4f7d22c58dcf1d4a4cfa4450bfe0a8e927ba68204202e5502643feae-file_1578973047486){:width=500}

####  方法一：递归
**算法：**

- 若 `root == null`，则返回 `TreeNode(val)`。
- 若 `val > root.val`，插入到右子树。
- 若 `val < root.val`，插入到左子树。
- 返回 `root`。

![在这里插入图片描述](https://pic.leetcode-cn.com/c7321b9420dcc103a8dba32be48194c1f0560960cc23340508d24dca6b9aef6c-file_1578973047499){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/03fe4eee857793011419264b6c0ac16e14faa40b26af16409aa23084495517dd-file_1578973047471){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/77b2c2e31c57b902866405156827832e7fbabfe5f19b977f886c2c6a80a572a4-file_1578973047476){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/2d68318a065bc389c3365c920c0c354e1bc59f5d3199dcf50ac0bdab17080347-file_1578973047382){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/f8b7344b30919ee41e29e201f7f557a3c9f37d9d081694f73540bf26b452b88d-file_1578973047501){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/9e9aa625e5252943be1956d548eeb6f40f091bdfa6c8259e1eafe986c563c3e4-file_1578973047495){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/040f1e9aa348f3729d9495c147f8f67b95710daa278abe87816938efe575af38-file_1578973047413){:width=500}


```python [solution1-Python]
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        
        if val > root.val:
            # insert into the right subtree
            root.right = self.insertIntoBST(root.right, val)
        else:
            # insert into the left subtree
            root.left = self.insertIntoBST(root.left, val)
        return root
```

```java [solution1-Java]
class Solution {
  public TreeNode insertIntoBST(TreeNode root, int val) {
    if (root == null) return new TreeNode(val);

    // insert into the right subtree
    if (val > root.val) root.right = insertIntoBST(root.right, val);
    // insert into the left subtree
    else root.left = insertIntoBST(root.left, val);
    return root;
  }
}
```

**复杂度分析**

* 时间复杂度：$O(H)$，其中 $H$ 指的是树的高度。平均情况下 $\mathcal{O}(\log N)$，最坏的情况下 $\mathcal{O}(N)$。
* 空间复杂度：平均情况下 $\mathcal{O}(H)$。最坏的情况下是 $\mathcal{O}(N)$，是在递归过程中堆栈使用的空间。


####  方法二：迭代
上面的递归可以转换成迭代的解决方案。

```python [solution1-Python]
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        node = root
        while node:
            # insert into the right subtree
            if val > node.val:
                # insert right now
                if not node.right:
                    node.right = TreeNode(val)
                    return root
                else:
                    node = node.right
            # insert into the left subtree
            else:
                # insert right now
                if not node.left:
                    node.left = TreeNode(val)
                    return root
                else:
                    node = node.left
        return TreeNode(val)
```

```java [solution1-Java]
class Solution {
  public TreeNode insertIntoBST(TreeNode root, int val) {
    TreeNode node = root;
    while (node != null) {
      // insert into the right subtree
      if (val > node.val) {
        // insert right now
        if (node.right == null) {
          node.right = new TreeNode(val);
          return root;
        }
        else node = node.right;
      }
      // insert into the left subtree
      else {
        // insert right now
        if (node.left == null) {
          node.left = new TreeNode(val);
          return root;
        }
        else node = node.left;
      }
    }
    return new TreeNode(val);
  }
}
```

**复杂度分析**

* 时间复杂度：$O(H)$，其中 $H$ 指的是树的高度。平均情况下 $\mathcal{O}(\log N)$，最坏的情况下 $\mathcal{O}(N)$。
* 空间复杂度：$O(1)$。