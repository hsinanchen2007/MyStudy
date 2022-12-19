**树的定义**

首先，给出 ```TreeNode``` 的定义，后面会用到。

```Java [solution 1]
// Definition for a binary tree node.
public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}
```

```Python [solution 1]
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```
<br />
---
#### 方法一：递归

首先来计数需要构建的二叉树数量。可能的二叉搜素数数量是一个 [卡特兰数](https://baike.baidu.com/item/%E5%8D%A1%E7%89%B9%E5%85%B0%E6%95%B0/6125746?fr=aladdin)。

我们跟随上文的逻辑，只是这次是构建具体的树，而不是计数。
 
**算法**

我们从序列 `1 ..n` 中取出数字 `i`，作为当前树的树根。于是，剩余 `i - 1` 个元素可用于左子树，`n - i` 个元素用于右子树。 
如 [前文所述](https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/)，这样会产生 `G(i - 1)` 种左子树 和 `G(n - i)` 种右子树，其中 `G` 是卡特兰数。 

![image.png](https://pic.leetcode-cn.com/f709dff506c20ac970d4cd7ace0436aafca7828c67b510cdbaaa60d54f5479b3-image.png){:width=500}
{:align=center}

现在，我们对序列 `1 ... i - 1` 重复上述过程，以构建所有的左子树；然后对 `i + 1 ... n` 重复，以构建所有的右子树。

这样，我们就有了树根 `i` 和可能的左子树、右子树的列表。

最后一步，对两个列表循环，将左子树和右子树连接在根上。

```Java [solution 1]
class Solution {
  public LinkedList<TreeNode> generate_trees(int start, int end) {
    LinkedList<TreeNode> all_trees = new LinkedList<TreeNode>();
    if (start > end) {
      all_trees.add(null);
      return all_trees;
    }

    // pick up a root
    for (int i = start; i <= end; i++) {
      // all possible left subtrees if i is choosen to be a root
      LinkedList<TreeNode> left_trees = generate_trees(start, i - 1);

      // all possible right subtrees if i is choosen to be a root
      LinkedList<TreeNode> right_trees = generate_trees(i + 1, end);

      // connect left and right trees to the root i
      for (TreeNode l : left_trees) {
        for (TreeNode r : right_trees) {
          TreeNode current_tree = new TreeNode(i);
          current_tree.left = l;
          current_tree.right = r;
          all_trees.add(current_tree);
        }
      }
    }
    return all_trees;
  }

  public List<TreeNode> generateTrees(int n) {
    if (n == 0) {
      return new LinkedList<TreeNode>();
    }
    return generate_trees(1, n);
  }
}
```

```Python [solution 1]
class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def generate_trees(start, end):
            if start > end:
                return [None,]
            
            all_trees = []
            for i in range(start, end + 1):  # pick up a root
                # all possible left subtrees if i is choosen to be a root
                left_trees = generate_trees(start, i - 1)
                
                # all possible right subtrees if i is choosen to be a root
                right_trees = generate_trees(i + 1, end)
                
                # connect left and right subtrees to the root i
                for l in left_trees:
                    for r in right_trees:
                        current_tree = TreeNode(i)
                        current_tree.left = l
                        current_tree.right = r
                        all_trees.append(current_tree)
            
            return all_trees
        
        return generate_trees(1, n) if n else []
```


**复杂度分析**

* 时间复杂度 : 主要的计算开销在于构建给定根的全部可能树，也就是卡特兰数 $G_n$。该过程重复了 $n$ 次，也就是 $nG_n$。卡特兰数以 $\frac{4^n}{n^{3/2}}$ 增长。因此，总的时间复杂度为 $O(\frac{4^n}{n^{1/2}})$。这看上去很大，但别忘了，我们可是要生成 $G_n\sim\frac{4^n}{n^{3/2}}$ 棵树的。

* 空间复杂度 :$G_n$ 棵树，每个有 `n` 个元素，共计 $n G_n$。也就是 $O(\frac{4^n}{n^{1/2}})$。