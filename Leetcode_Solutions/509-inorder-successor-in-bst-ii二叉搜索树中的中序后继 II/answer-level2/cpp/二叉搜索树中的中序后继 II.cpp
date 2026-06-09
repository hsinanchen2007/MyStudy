####  前驱和后继
- 前驱：指的是中序遍历的上一个结点，或者说是比当前结点小的最大结点。
- 后继：指的是中序遍历的下一个结点，或者说是比当前结点大的最小结点。

![在这里插入图片描述](https://pic.leetcode-cn.com/dfb62d05f7de7bf54cf581b6c1f70548660d94e9ee13f7dd5606e24baf3e64a9-file_1577945833829){:width=390}


####  方法：迭代
这里可能有两种情况：
- `node` 结点有右孩子，且它的后继在树中相对较低的位置，为了找到后继，我们应该向右走一次，再尽可能的向左走。

![在这里插入图片描述](https://pic.leetcode-cn.com/54009551c599a87d09345be44b9a01072758ec36f0a52c5393108e1cc093f463-file_1577945834027){:width=390}

- `node` 结点没有右孩子，则它的后继在树中相对较高的位置，为了找到后继，我们向上走到直到结点 `tmp` 的左孩子是 `node` 的父节点时，则 `node` 的后继为 `tmp`。若没有找到符合条件的结点说明该结点没有后继。

![在这里插入图片描述](https://pic.leetcode-cn.com/19854db621bcf88185df912ebdf12a457c4a4ff4d4abd9a2e2ad578444c37e23-file_1577945833878){:width=390}
{:align=center}

![在这里插入图片描述](https://pic.leetcode-cn.com/6cb65e3ff8aba6d515f45c952909ff5522cb21b01dc22726dba43fa27d1c31b2-file_1577945833818){:width=390}

**算法：**
- 若 `node` 结点有右孩子，则它的后继在树中相对较低的位置。我们向右走一次，再尽可能的向左走，返回最后所在的结点。
- 若 `node` 结点没有右孩子，则它的后继在树中相对较高的位置。我们向上走到直到结点 `tmp` 的左孩子是 `node` 的父节点时，则 `node` 的后继为 `tmp`。

```python [solution1-Python]
class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':
        # the successor is somewhere lower in the right subtree
        if node.right:
            node = node.right
            while node.left:
                node = node.left
            return node
        
        # the successor is somewhere upper in the tree
        while node.parent and node == node.parent.right:
            node = node.parent
        return node.parent
```

```java [solution1-Java]
class Solution {
  public Node inorderSuccessor(Node x) {
    // the successor is somewhere lower in the right subtree
    if (x.right != null) {
      x = x.right;
      while (x.left != null) x = x.left;
      return x;
    }

    // the successor is somewhere upper in the tree
    while (x.parent != null && x == x.parent.right) x = x.parent;
    return x.parent;
  }
}
```

```c++ [solution1-C++]
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        // the successor is somewhere lower in the right subtree
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;   
        }
        
        // the successor is somewhere upper in the tree
        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(H)$。其中 $H$ 为数的高度。平均时间复杂度为 $\mathcal{O}(\log N)$，最坏的事件复杂度为 $\mathcal{O}(N)$，其中 $N$ 为树的结点数。
* 空间复杂度：$\mathcal{O}(1)$，在计算的过程中没有使用额外空间。