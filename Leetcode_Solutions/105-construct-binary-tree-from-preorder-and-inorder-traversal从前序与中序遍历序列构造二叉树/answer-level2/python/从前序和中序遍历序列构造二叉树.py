#### 如何遍历一棵树

有两种通用的遍历树的策略：

* *宽度优先搜索*（`BFS`）

  我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到。

* *深度优先搜索*（`DFS`）

  在这个策略中，我们采用`深度`作为优先级，以便从跟开始一直到达某个确定的叶子，然后再返回根到达另一个分支。

  深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为`前序遍历`，`中序遍历`和`后序遍历`。

下图中的顶点按照访问的顺序编号，按照 `1-2-3-4-5` 的顺序来比较不同的策略。

![102.png](https://pic.leetcode-cn.com/b61ff2d47852e4264f5dfe0a5b00101bdeca2b0ba216aa83ca3cb6fac42ebb84-102.png){:width="500px"}
{:align=center}

本问题就是从前序和中序遍历序列构造对应的二叉树。

#### 方法 1：递归

**结构定义**

首先，定义树的存储结构 `TreeNode` 。

```Java []
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

```Python []
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

**算法**

如上文所提到的，先序遍历的顺序是 `Root -> Left -> Right`，这就能方便的从根开始构造一棵树。

首先，*preorder* 中的第一个元素一定是树的根，这个根又将 *inorder* 序列分成了左右两棵子树。现在我们只需要将先序遍历的数组中删除根元素，然后重复上面的过程处理左右两棵子树。

<![image.png](https://pic.leetcode-cn.com/fdd9e62011477fcd4a3ebcddc1f35d99a901e3a553e10dd796ab9e0abf919cae-image.png),![image.png](https://pic.leetcode-cn.com/fe2a4e8b83dd8f2b9caf3f1cac2dc46e253a54571d9c5822cea3a4ab892280be-image.png),![image.png](https://pic.leetcode-cn.com/500854d776e58340f39ffe7641bad58d747122e28ed8ce816ec36e6b518987e0-image.png),![image.png](https://pic.leetcode-cn.com/f839b10def0240ed3efb46deaa6fb2222073588beb56cffaf4c9d09d8b2dafb0-image.png),![image.png](https://pic.leetcode-cn.com/8eba1d34b8dcf5d6910373a4c52103e5c805849131354161165ac494d2cd657c-image.png),![image.png](https://pic.leetcode-cn.com/b6249568d4cacfd2644edc87ea3a3d6709f151568732a6b813f4f18e3d31a11c-image.png),![image.png](https://pic.leetcode-cn.com/50e012d2b880833bb52d797a21c618a42e2ac6b674d7c8df796dbf2cae3d7867-image.png),![image.png](https://pic.leetcode-cn.com/10a420ba0da93b8418e7ab809eec91774fe17dee79674978b274049097514331-image.png),![image.png](https://pic.leetcode-cn.com/49d1642e2e30083141b60ba636a8c7ddd838b475681032fe2a31cd46957571cd-image.png),![image.png](https://pic.leetcode-cn.com/07beedacc2b4b8de97f90bfa083b8ea213e3ed8478988ad414dcb3ef87584a2d-image.png),![image.png](https://pic.leetcode-cn.com/fe6070672567b1651e6943c5d917f5b4b6b9649f17a4fca1b6a711eb7bbd5a12-image.png),![image.png](https://pic.leetcode-cn.com/1cfde8308922fe135be6f5704abccd0140bc2fddd4730988fa395149dee04927-image.png)>


```Java []
class Solution {
  // start from first preorder element
  int pre_idx = 0;
  int[] preorder;
  int[] inorder;
  HashMap<Integer, Integer> idx_map = new HashMap<Integer, Integer>();

  public TreeNode helper(int in_left, int in_right) {
    // if there is no elements to construct subtrees
    if (in_left == in_right)
      return null;

    // pick up pre_idx element as a root
    int root_val = preorder[pre_idx];
    TreeNode root = new TreeNode(root_val);

    // root splits inorder list
    // into left and right subtrees
    int index = idx_map.get(root_val);

    // recursion 
    pre_idx++;
    // build left subtree
    root.left = helper(in_left, index);
    // build right subtree
    root.right = helper(index + 1, in_right);
    return root;
  }

  public TreeNode buildTree(int[] preorder, int[] inorder) {
    this.preorder = preorder;
    this.inorder = inorder;

    // build a hashmap value -> its index
    int idx = 0;
    for (Integer val : inorder)
      idx_map.put(val, idx++);
    return helper(0, inorder.length);
  }
}
```

```Python []
class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def helper(in_left = 0, in_right = len(inorder)):
            nonlocal pre_idx
            # if there is no elements to construct subtrees
            if in_left == in_right:
                return None
            
            # pick up pre_idx element as a root
            root_val = preorder[pre_idx]
            root = TreeNode(root_val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[root_val]

            # recursion 
            pre_idx += 1
            # build left subtree
            root.left = helper(in_left, index)
            # build right subtree
            root.right = helper(index + 1, in_right)
            return root
        
        # start from first preorder element
        pre_idx = 0
        # build a hashmap value -> its index
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper()
```

**复杂度分析**

* 时间复杂度：$O(N)$，我们用[主定理](https://baike.baidu.com/item/%E4%B8%BB%E5%AE%9A%E7%90%86/3463232?fr=aladdin)来计算时间复杂度：

  $T(N) = aT\left(\frac{N}{b}\right) + \Theta(N^d)$

  这个方程表示在 $\Theta(N^d)$ 的时间内将问题分成 $a$ 个大小为 $\frac{N}{b}$ 的子问题解决。

  当前将问题分解成了两个子问题 `a = 2`，每个子问题（计算左右两棵子树）的大小是原始问题的一般 `b = 2`，同时划分只需要常数的时间 `d = 0`。

  这意味着 $\log_b(a) > d$，因此适用于主定理的[第一种情况](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms)#Case_1_example)，时间复杂度为 $O(N^{\log_b(a)}) = O(N)$。


* 空间复杂度：$O(N)$，存储整棵树的开销。