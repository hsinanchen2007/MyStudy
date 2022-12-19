```
    LinkedList<Integer> data = new LinkedList<>();

    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (root.left != null && !isValidBST(root.left)) {
            return false;
        }
        //左中右遍历，让值依次增大即可
        if (!data.isEmpty()) {
            Integer n = data.peekLast();
            if (n >= root.val) {
                return false;
            }
        }
        data.add(root.val);
        if (root.right != null && !isValidBST(root.right)) {
            return false;
        }
        return true;
    }
```
