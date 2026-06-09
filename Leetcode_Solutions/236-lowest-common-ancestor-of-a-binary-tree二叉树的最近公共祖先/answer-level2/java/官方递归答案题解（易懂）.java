### 解题思路
以要找的节点分别为p和q为例：

首先分析公共祖先一共可以分为以下三种情况：

- 如果一个节点的左右都能达到终点，那么当前节点一定是公共祖先。
- 如果当前节点左树可以找到一个值，当前节点值等于另一个值，那么祖先也就是当前值。
- 如果当前节点右树可以找到一个值，当前节点值等于另一个值，那么祖先也一定就是当前值。



这三种情况用代码表示就是:

- left=1，right=1，mid=0
- left=1，right=0，mid=1
- left=0，right=2，mid=1

left表示向左子树递归是否能找到通向p/q，能找到赋值1，不能的话赋值0

right表示向右子树递归是否能找到通向p/q，能找到赋值1，不能的话赋值0

mid表示当前节点是否等于p/q，等于的话赋值1，不等于赋值0

所以用代码表示就是：

          if (mid + left + right == 2) {
                this.ans = currentNode;
            }

即只要其中两个值=1当前节点便是公共祖先节点。


### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
     private TreeNode ans = null;
    private boolean recurseTree(TreeNode currentNode, TreeNode p, TreeNode q) {

        if (currentNode == null) {
            return false;
        }

        int left = this.recurseTree(currentNode.left, p, q) ? 1 : 0;

        int right = this.recurseTree(currentNode.right, p, q) ? 1 : 0;

        int mid = (currentNode == p || currentNode == q) ? 1 : 0;


        if (mid + left + right == 2) {
            this.ans = currentNode;
        }

        return (mid + left + right > 0);
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.recurseTree(root, p, q);
        return this.ans;
    }

}
```