####  二叉搜索树的三个特性：
这些性质最好在面试之前了解清楚：
- 二叉搜索树的中序遍历的序列是递增排序的序列。中序遍历的遍历次序：`Left -> Node -> Right`。

```java [Inorder_traversal-Java]
public LinkedList<Integer> inorder(TreeNode root, LinkedList<Integer> arr) {
  if (root == null) return arr;
  inorder(root.left, arr);
  arr.add(root.val);
  inorder(root.right, arr);
  return arr;
} 
```

```python [Inorder_traversal-Python]
def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []
```
![在这里插入图片描述](https://pic.leetcode-cn.com/0cc0a63c4c063977e74374a94ab4f6ed4e7cad94ddc52b99ab3afcff073738c1-file_1576477912261){:width=500}

- `Successor` 代表的是中序遍历序列的下一个节点。即比当前节点大的最小节点，简称后继节点。 先取当前节点的右节点，然后一直取该节点的左节点，直到左节点为空，则最后指向的节点为后继节点。

```java [Successor-Java]
public int successor(TreeNode root) {
  root = root.right;
  while (root.left != null) root = root.left;
  return root;
} 
```

```python [Successor-Python]
def successor(root):
    root = root.right
    while root.left:
        root = root.left
    return root
```
- `Predecessor` 代表的是中序遍历序列的前一个节点。即比当前节点小的最大节点，简称前驱节点。先取当前节点的左节点，然后取该节点的右节点，直到右节点为空，则最后指向的节点为前驱节点。

```java [Predecessor-Java]
public int predecessor(TreeNode root) {
  root = root.left;
  while (root.right != null) root = root.right;
  return root;
} 
```

```python [Predecessor-Python]
def predecessor(root):
    root = root.left
    while root.right:
        root = root.right
    return root
```
![在这里插入图片描述](https://pic.leetcode-cn.com/309271bd1f94c57fd4e19f5eee624dd2ad3ef8e4d5a3b6eca5556e9f2e43a3bc-file_1576477912310){:width=500}


####  方法：递归
这里有三种可能的情况：
- 要删除的节点为叶子节点，可以直接删除。

![在这里插入图片描述](https://pic.leetcode-cn.com/b86c5d5866fb8b1f6a2f15f47262adf3ae68e56498c9e261a031bbb8ebc55588-file_1576477912302){:width=500}
- 要删除的几点不是叶子节点且拥有右节点，则该节点可以由该节点的后继节点进行替代，该后继节点位于右子树中较低的位置。然后可以从后继节点的位置递归向下操作以删除后继节点。

![在这里插入图片描述](https://pic.leetcode-cn.com/12353e5c71267aafd355319a8b881f0b9efae0680358b7ce738228151a42d3cc-file_1576477912312){:width=500}
- 要删除的节点不是叶子节点，且没有右节点但是有左节点。这意味着它的后继节点在它的上面，但是我们并不想返回。我们可以使用它的前驱节点进行替代，然后再递归的向下删除前驱节点。

![在这里插入图片描述](https://pic.leetcode-cn.com/2a9aa44aab7948e78e06182791e2eaaf00fb72eff054a1f4612030a047dde59a-file_1576477912315){:width=500}


**算法：**
- 如果 `key > root.val`，说明要删除的节点在右子树，`root.right = deleteNode(root.right, key)`。
- 如果 `key < root.val`，说明要删除的节点在左子树，`root.left = deleteNode(root.left, key)`。
- 如果 `key == root.val`，则该节点就是我们要删除的节点，则：
	- 如果该节点是叶子节点，则直接删除它：`root = null`。
	- 如果该节点不是叶子节点且有右节点，则用它的后继节点的值替代 `root.val = successor.val`，然后删除后继节点。
	- 如果该节点不是叶子节点且只有左节点，则用它的前驱节点的值替代 `root.val = predecessor.val`，然后删除前驱节点。
- 返回 `root`。 

![在这里插入图片描述](https://pic.leetcode-cn.com/cabd70de79b533f744f3a9068941c9be10711a47a26b3daed67bd00fed391644-file_1576477912304){:width=500}

```java [solution1-Java]
class Solution {
  /*
  One step right and then always left
  */
  public int successor(TreeNode root) {
    root = root.right;
    while (root.left != null) root = root.left;
    return root.val;
  }

  /*
  One step left and then always right
  */
  public int predecessor(TreeNode root) {
    root = root.left;
    while (root.right != null) root = root.right;
    return root.val;
  }

  public TreeNode deleteNode(TreeNode root, int key) {
    if (root == null) return null;

    // delete from the right subtree
    if (key > root.val) root.right = deleteNode(root.right, key);
    // delete from the left subtree
    else if (key < root.val) root.left = deleteNode(root.left, key);
    // delete the current node
    else {
      // the node is a leaf
      if (root.left == null && root.right == null) root = null;
      // the node is not a leaf and has a right child
      else if (root.right != null) {
        root.val = successor(root);
        root.right = deleteNode(root.right, root.val);
      }
      // the node is not a leaf, has no right child, and has a left child    
      else {
        root.val = predecessor(root);
        root.left = deleteNode(root.left, root.val);
      }
    }
    return root;
  }
}
```

```python [solution1-Python]
class Solution:
    def successor(self, root):
        """
        One step right and then always left
        """
        root = root.right
        while root.left:
            root = root.left
        return root.val
    
    def predecessor(self, root):
        """
        One step left and then always right
        """
        root = root.left
        while root.right:
            root = root.right
        return root.val
        
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return None
        
        # delete from the right subtree
        if key > root.val:
            root.right = self.deleteNode(root.right, key)
        # delete from the left subtree
        elif key < root.val:
            root.left = self.deleteNode(root.left, key)
        # delete the current node
        else:
            # the node is a leaf
            if not (root.left or root.right):
                root = None
            # the node is not a leaf and has a right child
            elif root.right:
                root.val = self.successor(root)
                root.right = self.deleteNode(root.right, root.val)
            # the node is not a leaf, has no right child, and has a left child    
            else:
                root.val = self.predecessor(root)
                root.left = self.deleteNode(root.left, root.val)
                        
        return root

```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log N)$。在算法的执行过程中，我们一直在树上向左或向右移动。首先先用 $\mathcal{O}(H_1)$ 的时间找到要删除的节点，$H_1$ 值得是从根节点到要删除节点的高度。然后删除节点需要 $\mathcal{O}(H_2)$ 的时间，$H_2$ 指的是从要删除节点到替换节点的高度。由于 $\mathcal{O}(H_1 + H_2) = \mathcal{O}(H)$，$H$ 值得是树的高度，若树是一个平衡树则 $H$ = $\log N$。
* 空间复杂度：$\mathcal{O}(H)$，递归时堆栈使用的空间，$H$ 是树的高度。