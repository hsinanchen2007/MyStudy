#### 方法一：中序遍历

二叉搜索树的中序遍历结果是一个递增的数组，顺序后继是中序遍历中当前节点 _之后_ 最小的节点。

可以分成两种情况来讨论：

1. 如果当前节点有右孩子，顺序后继在当前节点之下，如下图中红色节点所示。

2. 如果当前的话，顺序后继在当前节点之上，如下图中蓝色节点所示。

![img](https://pic.leetcode-cn.com/Figures/285/succ.png)

如果是下图这种情况，找到顺序后继很简单，先找到当前节点的右孩子，然后再持续往左直到左孩子为空。

![pic](https://pic.leetcode-cn.com/Figures/285/right.png)

这种方法的时间复杂度为 $O(H_p)$，其中 $H_p$ 为节点 $p$ 的高度。

下面再来看一个复杂一点的情况，这时候由于无法访问父亲节点，只能从根节点开始中序遍历。中序遍历通常由有递归和非递归的实现方式，这里用非递归的实现方式会更好一点。

直接在中序遍历过程保存前一个访问的节点，判断前一个节点是否为 `p`，如果是的话当前节点就是 `p` 节点的顺序后继。

![pac](https://pic.leetcode-cn.com/Figures/285/case2.png)

中序遍历方法的时间复杂度为 $O(H)$，其中 $H$ 为树的高度。在第一种情况下也可以用中序遍历的方法，但之前的方法更快一点。

**算法**

- 如果当前节点有右孩子，找到右孩子，再持续往左走直到节点左孩子为空，直接返回该节点。

- 如果没有的话，就需要用到非递归的中序遍历。维持一个栈，当栈中有节点时：

    - 往左走直到节点的左孩子为空，并将每个访问过的节点压入栈中。
    
    - 弹出栈中节点，判断当前的前继节点是否为 `p`，如果是则直接返回当前节点。如果不是，将当前节点赋值给前继节点。
    
    - 往右走一步。
    
- 如果走到这一步，说明不存在顺序后继，返回空。

**实现**

```python [solution1-Python]
class Solution:
    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        # the successor is somewhere lower in the right subtree
        # successor: one step right and then left till you can
        if p.right:
            p = p.right
            while p.left:
                p = p.left
            return p
        
        # the successor is somewhere upper in the tree
        stack, inorder = [], float('-inf')
        
        # inorder traversal : left -> node -> right
        while stack or root:
            # 1. go left till you can
            while root:
                stack.append(root)
                root = root.left
                
            # 2. all logic around the node
            root = stack.pop()
            if inorder == p.val:    # if the previous node was equal to p
                return root         # then the current node is its successor
            inorder = root.val
            
            # 3. go one step right
            root = root.right

        # there is no successor
        return None
```

```java [solution1-Java]
class Solution {
  public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
    // the successor is somewhere lower in the right subtree
    // successor: one step right and then left till you can
    if (p.right != null) {
      p = p.right;
      while (p.left != null) p = p.left;
      return p;
    }

    // the successor is somewhere upper in the tree
    ArrayDeque<TreeNode> stack = new ArrayDeque<>();
    int inorder = Integer.MIN_VALUE;

    // inorder traversal : left -> node -> right
    while (!stack.isEmpty() || root != null) {
      // 1. go left till you can
      while (root != null) {
        stack.push(root);
        root = root.left;
      }

      // 2. all logic around the node
      root = stack.pop();
      // if the previous node was equal to p
      // then the current node is its successor
      if (inorder == p.val) return root;
      inorder = root.val;

      // 3. go one step right
      root = root.right;
    }

    // there is no successor
    return null;
  }
}
```


**复杂度分析**

* 时间复杂度：如果节点 `p` 有右孩子，时间复杂度为 $O(H_p)$，其中 $H_p$ 是节点 `p` 的高度。如果没有右孩子，时间复杂度为 $O(H)$，其中 $H$ 为树的高度。

* 空间复杂度：如果节点 `p` 有右孩子，空间复杂度为 $O(1)$。如果没有右孩子，空间复杂度度为 $O(H)$。