常规解法，没想到双100%

```
void buildList(TreeNode root, List<TreeNode> list) {
        if (root.left == null && root.right == null) {
            list.add(root);
            return;
        }
        
        if (root.left != null) {
            buildList(root.left, list);
        }
        list.add(root);
        if (root.right != null) {
            buildList(root.right, list);
        }
    }
    
    private TreeNode toBST(List<TreeNode> list, int i, int j) {
        if (i == j) {
            TreeNode node = list.get(i);
            node.left = node.right = null;
            return node;
        }
        int mid = (i + j) / 2;
        TreeNode root = list.get(mid);
        if (i == mid) {
            root.left = null;
        } else {
            root.left = toBST(list, i, mid - 1);
        }
        root.right = toBST(list, mid + 1, j);
        
        return root;
    }
    
    public TreeNode balanceBST(TreeNode root) {
        if (root == null) {
            return root;
        }
        
        List<TreeNode> list = new ArrayList();
        buildList(root, list);
        return toBST(list, 0, list.size() - 1);
    }
```
