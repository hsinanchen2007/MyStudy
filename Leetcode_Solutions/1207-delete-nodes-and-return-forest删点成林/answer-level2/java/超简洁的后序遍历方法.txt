```java
class Solution {
    private Set<Integer> set = new HashSet<>();
    private List<TreeNode> list = new ArrayList<>();
    public List<TreeNode> delNodes(TreeNode root, int[] dels) {
        if (root == null) {
            return Collections.emptyList();
        }
        for (int del : dels) {
            set.add(del);
        }
        root = dfs(root);
        if (root != null) {
            list.add(root);
        }
        return list;
    }

    private TreeNode dfs(TreeNode root) {
        if (root == null) {
            return null;
        }
        root.left = dfs(root.left);
        root.right = dfs(root.right);

        if (set.contains(root.val)) {
            if (root.left != null) {
                list.add(root.left);
            }
            if (root.right != null) {
                list.add(root.right);
            }
            return null;
        }
        return root;
    }
}
```
