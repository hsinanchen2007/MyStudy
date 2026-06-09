### 解题思路
此处撰写解题思路

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) {
            return null;
        }

        // 申请题意：二叉搜索树，特点根节点值大于左子树所有节点，小于右子树左右节点
        // 寻找最近祖先，则两个都小于root则左子树继续找；两个都大于则右子树继续找；否则返回当前root即可
        if (p.val < root.val && q.val < root.val) { // 如果都小于root，则走左子树
            return lowestCommonAncestor(root.left, p, q);
        }else if (p.val > root.val && q.val > root.val){ // 如果都大于root，则走左子树
            return lowestCommonAncestor(root.right, p, q);
        }

        return func(root, p, q);
    }

    // 非递归
    private TreeNode lowestCommonAncestor_(TreeNode root, TreeNode p, TreeNode q) {
        while (root != null) {
            if (p.val < root.val && q.val < root.val) {
                root = root.left;
            } else if (p.val > root.val && q.val > root.val) {
                root = root.right;
            } else {
                break;
            }
        }

        return root;
    }
}
```