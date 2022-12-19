

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> leafs1 = getLeafs(root1);
        List<Integer> leafs2 = getLeafs(root2);

        if (leafs1.size() != leafs2.size()) {
            return false;
        }
        for (int i = 0; i < leafs1.size(); i++) {
            if (!leafs1.get(i).equals(leafs2.get(i))) {
                return false;
            }
        }
        return true;
    }

    private List<Integer> getLeafs(TreeNode root) {
        if (root == null) {
            return Collections.emptyList();
        }
        List<Integer> leafs = new ArrayList<>();
        dfs(root, leafs);
        return leafs;
    }

    private void dfs(TreeNode root, List<Integer> leafs) {
        if (root == null) {
            return;
        }
        if (root.right == null && root.left == null) {
            leafs.add(root.val);
        }
        dfs(root.left, leafs);
        dfs(root.right, leafs);
    }
}
```