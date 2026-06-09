### 解题思路
递归的方法很多题解都有,能用迭代的方法的时候我倾向于迭代.
对于树中的结点p和q,肯定存在一条唯一的路径是从root到p的,也存在一条唯一的路径是从root到q的.我们可以采用深度优先遍历,把这两条路径找出来,然后反着遍历一条路路径上的结点,如果存在于另一条路径中,说明就是公共祖先.

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
    LinkedList<TreeNode> path1 = new LinkedList<>();

    LinkedList<TreeNode> curpath = new LinkedList<>();

    TreeNode lastNode = null;

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode node = root;
        while (node != null || curpath.size() > 0) {
            while (node != null) {
                curpath.push(node);
                if (node == p || node == q) {
                    if (path1.isEmpty()) {
                        path1 = new LinkedList<>(curpath);
                    } else {
                        return onFind();
                    }
                }
                node = node.left;
            }
            if (curpath.size() <= 0) {
                break;
            }
            node = curpath.peek().right;
            while (node == lastNode || node == null) {
                lastNode = curpath.pop();
                node = curpath.peek().right;
            }
        }
        return null;
    }

    private TreeNode onFind() {
        while (path1.size() > 0) {
            TreeNode node = path1.pop();
            if (curpath.contains(node)) {
                return node;
            }
        }
        return null;
    }
}
```