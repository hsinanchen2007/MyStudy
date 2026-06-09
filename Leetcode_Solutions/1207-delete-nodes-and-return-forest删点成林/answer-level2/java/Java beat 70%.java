
```
class Solution {
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) { 
        List<TreeNode> forest = new ArrayList<>(16);
        if (null == root) return forest;
        Set<Integer> toDeleteSet = new HashSet<>(16);
        for (int e : to_delete) {
            toDeleteSet.add(e);
        }
        root = delNodes(root, forest, toDeleteSet);
        if (null != root) forest.add(root);
        return forest;
    }
    // 思路
    // 如果是root待删除，则将其两个子指针 置空
    // 如果是中间某节点待删除，则将两个子指针置空，同时需要将其父节点指向自己的连接置空。
    // 递归解决。
    
    public TreeNode delNodes(TreeNode root, List<TreeNode> forest, Set<Integer> toDeleteSet) {
        if (null == root) return null;
        root.left = delNodes(root.left, forest, toDeleteSet);
        root.right = delNodes(root.right, forest, toDeleteSet);      
        if (toDeleteSet.contains(root.val)) {
            if (null != root.left) forest.add(root.left);
            if (null != root.right) forest.add(root.right);
            return null;
        }
        return root;
    }
}
```
