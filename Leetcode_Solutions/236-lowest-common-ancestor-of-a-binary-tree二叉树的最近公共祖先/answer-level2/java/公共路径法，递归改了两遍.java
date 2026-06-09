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
        List<TreeNode> listp = new ArrayList<>();
        List<TreeNode> listq = new ArrayList<>();
        Traversal(root, p, listp);
        Traversal(root, q, listq);
        return findCommonNode(listp, listq);
    }

    private boolean Traversal(TreeNode root, TreeNode p, List<TreeNode> list) {
        if (root == null) {
            return false;
        }
        if (root == p) {
            list.add(p);
            return true;
        }
        list.add(root);
        boolean found = false;
        found = Traversal(root.left, p, list);
        if (!found) {
            found = Traversal(root.right, p, list);
        }
        if (!found) {
            list.remove(list.size() - 1);
        }
        return found;
    }

    private TreeNode findCommonNode(List<TreeNode> listp, List<TreeNode> listq) {
        int lenp = listp.size();
        int lenq = listq.size();
        int len = lenp >= lenq ? lenq : lenp;
        TreeNode res = new TreeNode(-1);
        for (int i = 0; i < len; i++) {
            if (listp.get(i).val == listq.get(i).val) {
                res.left = listp.get(i).left;
                res.right = listp.get(i).right;
                res.val = listp.get(i).val;
            }
        }
        return res;
    }
}
```