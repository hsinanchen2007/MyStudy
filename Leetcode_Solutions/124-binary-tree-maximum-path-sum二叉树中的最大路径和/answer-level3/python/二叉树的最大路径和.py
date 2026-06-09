#### 方法 1：递归

**想法**

首先，考虑实现一个简化的函数 `max_gain(node)` ，参数是一个顶点，计算它及其子树的最大贡献。

> 换句话说，就是计算包含这个顶点的最大权值路径。


![124_gains.png](https://pic.leetcode-cn.com/45568450c1b869362937807e70ebb3c287380e9eaf78ae3600040ad83cb7a267-124_gains.png)

因此如果可知最后的最大路径和包含 `root` ，那么答案就是 `max_gain(root)`。

然而，最大路径可能并不包括根节点，比如下面的这棵树：


![124_max_path.png](https://pic.leetcode-cn.com/f5c2c1de7252473f7030373375edf4c8ca5e791f4b91fb8d314e39adb77b3bf9-124_max_path.png)

这意味着我们要修改上面的函数，在每一步都检查哪种选择更好：是继续当前路径或者以当前节点作为最高节点计算新的路径。

**算法**

现在万事俱备，只欠算法。

* 初始化 `max_sum` 为最小可能的整数并调用函数 `max_gain(node = root)`。

* 实现 `max_gain(node)` 检查是继续旧路径还是开始新路径：
  * 边界情况：如果节点为空，那么最大权值是 `0` 。
  * 对该节点的所有孩子递归调用 `max_gain`，计算从左右子树的最大权值：`left_gain = max(max_gain(node.left), 0)` 和 `right_gain = max(max_gain(node.right), 0)`。
  * 检查是维护旧路径还是创建新路径。创建新路径的权值是：`price_newpath = node.val + left_gain + right_gain`，当新路径更好的时候更新 `max_sum`。
  * 对于递归返回的到当前节点的一条最大路径，计算结果为：`node.val + max(left_gain, right_gain)`。

**树的节点**

下面是树节点的结构 `TreeNode` 定义 ：

```Java []
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

```Python []
class TreeNode(object):
    """ Definition of a binary tree node."""
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
```

**实现**

<![image.png](https://pic.leetcode-cn.com/8915f6cc52c428db237eac63b0e413912f9e5b1b6139a4094a12059563847a29-image.png),![image.png](https://pic.leetcode-cn.com/6bb58d28c7473f622a11f02be752beefbeb1e4cd8e9d3e21d80f56143358c5e6-image.png),![image.png](https://pic.leetcode-cn.com/5a8edf72814b12aa219025e90d000cbd99ff71274b292eb019877fa0b45f49c5-image.png),![image.png](https://pic.leetcode-cn.com/aada3389f43b3c52ba29eb6dde7e323c942ec4d57f5511a589757798b5194dbc-image.png),![image.png](https://pic.leetcode-cn.com/8051c2dc50e9e1aa913d5ea2ff59571d5b535836bb94fd44f96f63c361a751ed-image.png),![image.png](https://pic.leetcode-cn.com/e289d02f8e8d9f35a0a25939ca44ac700d0ac76de2b5457e1fd0ef7eb7873342-image.png),![image.png](https://pic.leetcode-cn.com/9b559438eba92bd372f95c0df32600b2502b260ffe4486ec3bef74d62e573b6c-image.png)>


```Java []
class Solution {
  int max_sum = Integer.MIN_VALUE;

  public int max_gain(TreeNode node) {
    if (node == null) return 0;

    // max sum on the left and right sub-trees of node
    int left_gain = Math.max(max_gain(node.left), 0);
    int right_gain = Math.max(max_gain(node.right), 0);

    // the price to start a new path where `node` is a highest node
    int price_newpath = node.val + left_gain + right_gain;

    // update max_sum if it's better to start a new path
    max_sum = Math.max(max_sum, price_newpath);

    // for recursion :
    // return the max gain if continue the same path
    return node.val + Math.max(left_gain, right_gain);
  }

  public int maxPathSum(TreeNode root) {
    max_gain(root);
    return max_sum;
  }
}
```

```Python []
class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def max_gain(node):
            nonlocal max_sum
            if not node:
                return 0

            # max sum on the left and right sub-trees of node
            left_gain = max(max_gain(node.left), 0)
            right_gain = max(max_gain(node.right), 0)
            
            # the price to start a new path where `node` is a highest node
            price_newpath = node.val + left_gain + right_gain
            
            # update max_sum if it's better to start a new path
            max_sum = max(max_sum, price_newpath)
        
            # for recursion :
            # return the max gain if continue the same path
            return node.val + max(left_gain, right_gain)
   
        max_sum = float('-inf')
        max_gain(root)
        return max_sum
```


**复杂度分析**

* 时间复杂度：$O(N)$ 其中 $N$ 是结点个数。我们对每个节点访问不超过 2 次。
* 空间复杂度：$O(\log(N))$。我们需要一个大小与树的高度相等的栈开销，对于二叉树空间开销是 $O(\log(N))$。
