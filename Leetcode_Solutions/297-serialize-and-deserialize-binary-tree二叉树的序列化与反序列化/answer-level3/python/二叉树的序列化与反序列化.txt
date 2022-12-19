####  方法一：深度优先搜索

![image.png](https://pic.leetcode-cn.com/22aa4f1f4325669c02d898729d72d5cd56cb47ea00d82528d4df15239ed46c35-image.png){:width="500"}
{:align=center}

`Binary Search Tree` 的序列化本质上是对其值进行编码，更重要的是对其结构进行编码。可以遍历树来完成上述任务。众所周知，我们有两个一般策略： 
- 广度优先搜索（BFS） 
我们按照高度的顺序从上到下逐级扫描树。更高级别的节点将先于较低级别的节点访问。 
- 深度优先搜索（DFS)
在这个策略中，我们采用深度作为优先顺序，这样我们就可以从一个根开始，一直延伸到某个叶，然后回到根，到达另一个分支。 
根据根节点、左节点和右节点之间的相对顺序，可以进一步将DFS策略区分为 `preorder`、`inorder` 和 `postorder` 。

然而，在这个任务中，`DFS` 策略更适合我们的需要，因为相邻节点之间的链接自然地按顺序编码，这对后面的反序列化任务非常有帮助。 

因此，在这个解决方案中，我们用 `preorder` DFS 策略演示了一个示例。您可以在 leetcode explore上查看有关二叉搜索树的更多教程。 

**算法：**
首先，这里是 `TreeNode`  的定义，我们将在下面的实现中使用它。 

```Java [ ]
/* Definition for a binary tree node. */
public class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(int x) {
    val = x;
  }
}
```

```Python [ ]
class TreeNode(object):
    """ Definition of a binary tree node."""
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```
先序遍历的 DNS 按 `root -> left subtree -> right subtree` 的顺序递归进行。 

作为一个例子，让我们序列化下面的树。请注意，序列化包含有关节点值的信息以及有关树结构的信息。 

<![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_1.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_2.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_3.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_4.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_5.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_6.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_7.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_8.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_9.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_10.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_11.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/297/297_sl_12.png)>

我们从根节点 `1` 开始，序列化字符串是 `1,`。然后我们跳到根节点 `2` 的左子树，序列化字符串变成 `1,2,`。现在从节点 `2` 开始，我们访问它的左节点 `3`（`1,2,3，none，none，`）和右节点 `4`。 
(`1,2,3,None,None,4,None,None`)。`None,None,`  是用来标记缺少左、右子节点，这就是我们在序列化期间保存树结构的方式。最后，我们回到根节点 `1` 并访问它的右子树，它恰好是叶节点 `5`。最后，序列化字符串是按 `1,2,3,None,None,4,None,None,5,None,None,`.

```Java [ ]
// Serialization
public class Codec {
  public String rserialize(TreeNode root, String str) {
    // Recursive serialization.
    if (root == null) {
      str += "null,";
    } else {
      str += str.valueOf(root.val) + ",";
      str = rserialize(root.left, str);
      str = rserialize(root.right, str);
    }
    return str;
  }

  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    return rserialize(root, "");
  }
};
```

```Python [ ]
# Serialization 
class Codec:

    def serialize(self, root):
        """ Encodes a tree to a single string.
        :type root: TreeNode
        :rtype: str
        """
        def rserialize(root, string):
            """ a recursive helper function for the serialize() function."""
            # check base case
            if root is None:
                string += 'None,'
            else:
                string += str(root.val) + ','
                string = rserialize(root.left, string)
                string = rserialize(root.right, string)
            return string
        
        return rserialize(root, '')
```

现在让我们反序列化 `1,2,3,None,None,4,None,None,5,None,None,` 字符串。它沿着字符串运行，初始化节点值，然后调用自身来构造其左、右子节点。 

```Java [ ]
public class Codec {
  public TreeNode rdeserialize(List<String> l) {
    // Recursive deserialization.
    if (l.get(0).equals("null")) {
      l.remove(0);
      return null;
    }

    TreeNode root = new TreeNode(Integer.valueOf(l.get(0)));
    l.remove(0);
    root.left = rdeserialize(l);
    root.right = rdeserialize(l);

    return root;
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    String[] data_array = data.split(",");
    List<String> data_list = new LinkedList<String>(Arrays.asList(data_array));
    return rdeserialize(data_list);
  }
};
```

```Python [ ]
# Deserialization 
class Codec:

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        def rdeserialize(l):
            """ a recursive helper function for deserialization."""
            if l[0] == 'None':
                l.pop(0)
                return None
                
            root = TreeNode(l[0])
            l.pop(0)
            root.left = rdeserialize(l)
            root.right = rdeserialize(l)
            return root

        data_list = data.split(',')
        root = rdeserialize(data_list)
        return root
```

**复杂度分析**

* 时间复杂度：在序列化和反序列化函数中，我们只访问每个节点一次，因此时间复杂度为 $O(n)$，其中 $n$ 是节点数，即树的大小。 
* 空间复杂度：在序列化和反序列化函数中，我们将整棵树保留在开头或结尾，因此，空间复杂性为 $O(n)$。 

具有 BFS 或其他 DFS 策略的解决方案通常具有相同的时间和空间复杂性。 

**进一步空间优化 :**
在以上解决方案，我们存储节点值和对 `None` 节点的引用 ，这意味 $N \cdot V + 2N$ 复杂性，其中 $V$ 是大小的值。这称为自然序列化，并已在上面实现。

这里的 $N\cdot V$ 是值的编码，不能进一步优化，但是有一种方法可以减少 $2N$ 部分，就是树结构的编码。

可以使用 `n` 个节点构造的唯一二叉树结构的数目是 $C(n)$，其中 $C(n)$ 是 `nth` 加泰罗尼亚数。

有 $C(n)$ 可能的具有 `n` 个节点的二叉树结构配置，因此我们可能需要存储的最大索引值是 $c(n)-1$。这意味着存储索引值可能最多需要 1 位当 $n\leq 2$ ，或者需要 $\lceil log_2(C(n) - 1) \rceil$位 当 $n>2$。

这样，可以将树结构的编码减少 $\log n$。更准确地说，加泰罗尼亚语的数字增长为 $C(n) \sim \frac{4^n}{n^{3/2}\sqrt{\pi}}$ ，因此，可以实现的树结构的理论最小存储量是 
 $log(C(n)) \sim 2n - \frac{3}{2}\log(n) - \frac{1}{2}\log(\pi)$