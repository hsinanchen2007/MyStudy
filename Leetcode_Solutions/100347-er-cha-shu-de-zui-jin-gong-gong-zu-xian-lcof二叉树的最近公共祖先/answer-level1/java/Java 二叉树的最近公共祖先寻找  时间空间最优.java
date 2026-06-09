### 解题思路
本题是二叉树，没有任何特性。
以一个小子树为例分析，要么p和q分别在root的左右子树上，要么都在root的左子树，要么都在root的右子树。
所以当从左子树和右子树寻找p和q时，如果均返回找到了（无论找到哪一个），则此时root即最近祖先。
如果只在左子树或者只在右子树找到，则表明就是在找到的这颗子树上，返回left和right非空的节点。
如果左右子树都没有找到则返回null。
**递归结束条件：root为null、 root是p、 root是q。**

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
    // 上一个题目是二叉搜索树，这次题目仅是二叉树！！！！
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }
        
        // 在左子树找
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        // 在右子树找
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        
        // 在左子树和右子树分别找到p或q，则返回root
        if (left != null && right != null) {
            return root;
        }
        
        // 其中一个为null则返回非null的即可，如果均为null，直接返回null即可
        return right == null ? left : right;
    }
}
```