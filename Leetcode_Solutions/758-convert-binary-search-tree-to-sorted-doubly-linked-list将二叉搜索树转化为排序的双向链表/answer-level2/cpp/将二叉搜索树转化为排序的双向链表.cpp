#### 如何遍历树

总的来说，有两种遍历树的策略：
     
- *深度优先搜索* (`DFS`)

    在深度优先搜索中，我们以 `深度` 优先，从根开始先抵达某个叶子，再回退以前往下一个分支。

    深度优先搜索又可以根据根节点、左子结点和右子结点的顺序关系分为`前序遍历`，`中序遍历`和`后序遍历`。
    
- *广度优先搜索* (`BFS`)

    逐层扫描整棵树，按照高度顺序自顶向下。上层的结点比下层更先访问。
    
下图表示了不同策略下的访问顺序，请按照 `1-2-3-4-5` 的顺序来比较不同的策略。

![image.png](https://pic.leetcode-cn.com/5d33034faca455df6f2f8baeb544506113b9f8331aa4d3301d9373f945cfddc3-image.png){:width=600}
{:align=center}

由于原地的要求，本问题需要使用深度优先搜索的中序遍历，利用备忘录法实现。
<br /> 
<br />


---
#### 方法一：递归

**算法**

标准的中序遍历采用 `左 -> 根 -> 右` 的顺序，其中 `左` 和 `右` 的部分调用递归。

本题的处理在于将前一个结点与当前结点链接，因此，必须跟踪最后一个结点，该结点在新的双向链表中是当前最大的。

![image.png](https://pic.leetcode-cn.com/df603862cb30be0aefffcc3a16e84a8ef2f77cdd202224ae22ff840823bc3995-image.png){:width=600}
{:align=center}

另外一个细节：我们也需要保留第一个，也就是最小的结点，以完成闭环。

下面是具体算法：

- 将 `first` 和 `last` 结点 初始化为 null。

- 调用标准中序遍历 `helper(root)` :

    - 若结点不为 null :
        
        - 调用左子树递归 `helper(node.left)`。
        
        - 若 `last` 结点不为空，将 `last` 与当前的 `node` 链接。
        
        - 否则初始化 `first` 结点。
        
        - 将当前结点标记为最后 : `last = node`.
        
        - 调用右子树递归 `helper(node.right)`。

- 将最前与最后的结点链接完成闭环，返回 `first` 。

**实现**

<![image.png](https://pic.leetcode-cn.com/5f5d87481a6c59789b547d0d89bc7e25655b380de65a3cd0da0e61a1fc034dc9-image.png),![image.png](https://pic.leetcode-cn.com/7fe6bbc881dab883e331882fdf2f34dba0cdc86864dd5ded3a03fdf2b575fa54-image.png),![image.png](https://pic.leetcode-cn.com/f71df171c101eea947eabdd46c1d8af571e1aa0af26eac93fa96de1131c417b5-image.png),![image.png](https://pic.leetcode-cn.com/5c180a4d42b136ce46a574a893af016418ed3e318cdea7440b227d2caf302ece-image.png),![image.png](https://pic.leetcode-cn.com/794c144fc758004a76989c6abe295f6ea7364ab7099529de5edb7819a1f2c9ea-image.png),![image.png](https://pic.leetcode-cn.com/3497ceca6e25ad03d220b46e5a26831b3a17642988f7d798d6d176008161e3e3-image.png),![image.png](https://pic.leetcode-cn.com/c48a883a6a48c9c04432451e230ccbfdbfcd28fde4a7a2210c315de7fcc176d1-image.png),![image.png](https://pic.leetcode-cn.com/0f304223d6dac073a486c4d6524d6a999fa82ba4abc49cefd0d0863d341fc1c7-image.png),![image.png](https://pic.leetcode-cn.com/d99fc8bc8e32b2e1383533e75edac468f1cc36dd69cdb19da042886946366f2e-image.png)>


```Python [solution 1]
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def helper(node):
            """
            Performs standard inorder traversal:
            left -> node -> right
            and links all nodes into DLL
            """
            nonlocal last, first
            if node:
                # left
                helper(node.left)
                # node 
                if last:
                    # link the previous node (last)
                    # with the current one (node)
                    last.right = node
                    node.left = last
                else:
                    # keep the smallest node
                    # to close DLL later on
                    first = node        
                last = node
                # right
                helper(node.right)
        
        if not root:
            return None
        
        # the smallest (first) and the largest (last) nodes
        first, last = None, None
        helper(root)
        # close DLL
        last.right = first
        first.left = last
        return first
```

```C++ [solution 1]
class Solution {
  public:
  // the smallest (first) and the largest (last) nodes
  Node* first = NULL;
  Node* last = NULL;

  void helper(Node* node) {
    if (node) {
      // left
      helper(node->left);
      // node 
      if (last) {
        // link the previous node (last)
        // with the current one (node)
        last->right = node;
        node->left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;
      // right
      helper(node->right);
    }
  }

  Node* treeToDoublyList(Node* root) {
    if (!root) return NULL;

    helper(root);
    // close DLL
    last->right = first;
    first->left = last;
    return first;
  }
};
```

```Java [solution 1]
class Solution {
  // the smallest (first) and the largest (last) nodes
  Node first = null;
  Node last = null;

  public void helper(Node node) {
    if (node != null) {
      // left
      helper(node.left);
      // node 
      if (last != null) {
        // link the previous node (last)
        // with the current one (node)
        last.right = node;
        node.left = last;
      }
      else {
        // keep the smallest node
        // to close DLL later on
        first = node;
      }
      last = node;
      // right
      helper(node.right);
    }
  }

  public Node treeToDoublyList(Node root) {
    if (root == null) return null;

    helper(root);
    // close DLL
    last.right = first;
    first.left = last;
    return first;
  }
}
```


**复杂度分析**

* 时间复杂度：${O}(N)$，每个结点被处理一次。
* 空间复杂度：${O}(N)$。需要树高度大小的递归栈，最好情况（平衡树）为 ${O}(\log N)$，最坏情况下（完全不平衡）为 $O(N)$。
