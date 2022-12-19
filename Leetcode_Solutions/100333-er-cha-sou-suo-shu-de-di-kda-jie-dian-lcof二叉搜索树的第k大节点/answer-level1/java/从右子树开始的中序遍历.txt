
```
    List<TreeNode> nodes = new ArrayList<>();

    public int kthLargest(TreeNode root, int k) {
        pre(root, k);
        return nodes.get(k-1).val;
    }

    public void pre(TreeNode root, int k) {
        if (root.right != null) {
            pre(root.right,k);
        }
        nodes.add(root);
        if (nodes.size() == k){
            return;
        }
        if (root.left != null) {
            pre(root.left, k);
        }
    }
```
