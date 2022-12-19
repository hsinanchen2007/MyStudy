#### 方法一：深度优先搜索

**直觉**

给定树中的一个结点，若其满足下面条件中的一个，则子树同值:

   1. 该节点没有子结点 （基本情况）
   2. 该节点的所有子结点都为同值子树，且结点与其子结点值相同。

这样我们可以在树中使用深度优先搜索，自底向上的判断每个子树是否为同值子树。

<![image.png](https://pic.leetcode-cn.com/0938545f946dd2ca65595bacebb32c69a68db6e58f3187ec339da68cf0801d76-image.png),![image.png](https://pic.leetcode-cn.com/a5538c324ce05c201d0558196936d03de237ff7a8d6fd29f548b50bd18887f4a-image.png),![image.png](https://pic.leetcode-cn.com/1957ca2808b9fff0f0eee3f6a5462d792ebf9e1eeac60f0a9874066b37cd437f-image.png),![image.png](https://pic.leetcode-cn.com/4956024c2e4848286ae837d55573cc6f38bda0dae611fdfae5f982b5af741df8-image.png),![image.png](https://pic.leetcode-cn.com/bc7f358f20bb514d8409240774551aba6bbaa4cc4b0312a78ed816d831ca76de-image.png),![image.png](https://pic.leetcode-cn.com/89b922355f4bdecce7eb41e6f123c6cfaf28dc3f86bcec9cc673e87c34731297-image.png),![image.png](https://pic.leetcode-cn.com/e64ebb63584737d21608b9a3181d5fd9187c5852ab3b8fa16d351bb855b88836-image.png)>


**算法**

```Python [solution 1]
class Solution:
    def countUnivalSubtrees(self, root):
        if root is None: return 0
        self.count = 0
        self.is_uni(root)
        return self.count

    def is_uni(self, node):

        # base case - if the node has no children this is a univalue subtree
        if node.left is None and node.right is None:

            # found a univalue subtree - increment
            self.count += 1
            return True

        is_uni = True

        # check if all of the node's children are univalue subtrees and if they have the same value
        # also recursively call is_uni for children
        if node.left is not None:
            is_uni = self.is_uni(node.left) and is_uni and node.left.val == node.val

        if node.right is not None:
            is_uni = self.is_uni(node.right) and is_uni and node.right.val == node.val

        # increment self.res and return whether a univalue tree exists here
        self.count += is_uni
        return is_uni
```

```Java [solution 1]
public class Solution {
    int count = 0;
    boolean is_uni(TreeNode node) {

        //base case - if the node has no children this is a univalue subtree
        if (node.left == null && node.right == null) {

            // found a univalue subtree - increment
            count++;
            return true;   
        }

        boolean is_unival = true;

        // check if all of the node's children are univalue subtrees and if they have the same value
        // also recursively call is_uni for children
        if (node.left != null) {
            is_unival = is_uni(node.left) && is_unival && node.left.val == node.val;
         }

        if (node.right != null) {
            is_unival = is_uni(node.right) && is_unival && node.right.val == node.val;
        }

        // return if a univalue tree exists here and increment if it does
        if (!is_unival) return false;
        count++;
        return true;
    }
    public int countUnivalSubtrees(TreeNode root) {
        if (root == null) return 0;
        is_uni(root);
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度 : $O(N)$。由于算法的深度优先特性，每个结点的 `is_uni` 状态是自底向上计算的。给定子结点的`is_uni` ，计算结点自身的 `is_uni` 只需要 $O(1)$ 的时间。故每个结点需要 $O(1)$ 时间，总复杂度为 $O(N)$。

* 空间复杂度 : $O(H)$， 其中 `H` 为树的高度。每次 `is_uni` 递归调用都需要栈空间。由于我们在调用 `is_uni(node.right)` 前会先处理完 `is_uni(node.left)`，递归栈的大小由从根到叶的最长路径决定 - 换而言之，是树的高度。
<br />
<br />

---

#### 方法二：传父值的深度优先搜索

**算法**

我们可以利用方法一的思路进一步简化算法。我们不检查结点是否有子结点，而是将 `null` 值看做同值子树，只是不计数。

这样，如果一个结点有 `null` 子结点，该子结点被自动判定为有效的子树，这样算法就只检查其他子结点是否有效。

最后，辅助函数检查当前节点是否是有效的子树，它返回一个布尔值，指示该节点是否为其父节点的有效组成。这可以通过传入父节点的值来完成。


```Python [solution 2]
class Solution:
    def countUnivalSubtrees(self, root):
        self.count = 0
        self.is_valid_part(root, 0)
        return self.count


    def is_valid_part(self, node, val):

        # considered a valid subtree
        if node is None: return True

        # check if node.left and node.right are univalue subtrees of value node.val
        if not all([self.is_valid_part(node.left, node.val),
                    self.is_valid_part(node.right, node.val)]):
            return False

        # if it passed the last step then this a valid subtree - increment
        self.count += 1

        # at this point we know that this node is a univalue subtree of value node.val
        # pass a boolean indicating if this is a valid subtree for the parent node
        return node.val == val
```

```Java [solution 2]
public class Solution {
    int count = 0;
    boolean is_valid_part(TreeNode node, int val) {

        // considered a valid subtree
        if (node == null) return true;

        // check if node.left and node.right are univalue subtrees of value node.val
        // note that || short circuits but | does not - both sides of the or get evaluated with | so we explore all possible routes
        if (!is_valid_part(node.left, node.val) | !is_valid_part(node.right, node.val)) return false;

        // if it passed the last step then this a valid subtree - increment
        count++;

        // at this point we know that this node is a univalue subtree of value node.val
        // pass a boolean indicating if this is a valid subtree for the parent node
        return node.val == val;
    }
    public int countUnivalSubtrees(TreeNode root) {
        is_valid_part(root, 0);
        return count;
    }
}
```



**复杂度分析**

* 时间复杂度 : $O(N)$。 与上个方法相同。

* 空间复杂度 : $O(H)$。 与上个方法相同。
