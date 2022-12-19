### 解题思路
见代码注释

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
        private Map<TreeNode, TreeNode> parent;
        private Set<TreeNode> set;
        private int flag = 0;

        /**
         * 1. 递归记录从root结点到p或q的路径
         * 2. 从p或q同时反向向上遍历，将parent同时保存到一个set中，add之前判断set中是否已包含此节点，若包含则就是最近公共祖先
         *
         * @param root
         * @param p
         * @param q
         * @return
         */
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (root == null || p == null || q == null) return null;
            parent = new HashMap<>();
            set = new HashSet<>();
            dfs(root, p, q);
            while (p != null || q != null) {
                if (set.contains(q)) return q;
                else set.add(q);
                if (set.contains(p)) return p;
                else set.add(p);
                p = parent.get(p);
                q = parent.get(q);
            }
            return null;
        }

        private void dfs(TreeNode root, TreeNode p, TreeNode q) {
            if (root == null) return;
            if ((root == p || root == q) && ++flag == 2) return;
            parent.put(root.left, root);
            parent.put(root.right, root);
            dfs(root.left, p, q);
            dfs(root.right, p, q);
        }

}
```