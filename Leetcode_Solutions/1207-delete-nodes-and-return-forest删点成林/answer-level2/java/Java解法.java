一开始想用先序遍历的，所以方法名取了个fstScan
但这里用后序遍历删节点更方便，所以后来就改成后序遍历了
不过方法名还是没改……
14ms,100%（估计用Java写的还没几个）
```
class Solution {
    private List<TreeNode> res = new ArrayList<>();
    private Set<Integer> toDelete = new HashSet<>();
    private TreeNode root;
    
    private void fstScan(TreeNode node) {
        if (node == null) return;
        fstScan(node.left);
        fstScan(node.right);
        if (toDelete.contains(node.val)) {
            //如果当前节点需要删除且它的左右子节点不在删除名单中，就把不在删除名单中的子节点加入res。
            if (node.left != null && !toDelete.contains(node.left.val)) res.add(node.left);
            if (node.right != null && !toDelete.contains(node.right.val)) res.add(node.right);
            //在树中删除当前节点
            delNode(node, root);
            fstScan(node.left);
            fstScan(node.right);
            return;
        }
    }
    
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        if (root == null) return res;
        for (int i : to_delete) {
            toDelete.add(i);
        }
        if (!toDelete.contains(root.val)) res.add(root); //这里对根节点单独进行判断
        this.root = root;
        fstScan(root);
        
        return res;
    }
    //删除指定节点（无法删除根节点）
    private void delNode(TreeNode node, TreeNode root) {
        if (root == null) return;
        delNode(node, root.left);
        delNode(node, root.right);
        if (root.left != null && root.left == node) {
            root.left = null;
        }
        if (root.right != null && root.right == node) {
            root.right = null;
        }
    }
}
```
