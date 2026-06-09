![image.png](https://pic.leetcode-cn.com/0bd9efc57ddbc472452519bf8aa353bf0e9f316b9db875197795ae21a9f57eef-image.png)


```
class Solution {
    private List<Integer> results = new ArrayList<>();
    public List<Integer> rightSideView(TreeNode root) {
        this.find(root, 0);
        return this.results;
    }
    private void find(TreeNode root, int depth) {
        if (root == null) return;
        if (this.results.size() == depth) {
            this.results.add(root.val);
        }
        this.find(root.right, depth + 1);
        this.find(root.left, depth + 1);
    }

```