//从root一次遍历出来 再去除set里面出现的项
```
class Solution {
     List<TreeNode> list = new ArrayList<>();

    public  List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> set = new HashSet();
        for (int de : to_delete)
            set.add(de);
        if (!set.contains(root.val))
            list.add(root);
        dfs(set, root);
        
       for (int i = list.size() - 1; i >= 0; i--) {
            if (set.contains(list.get(i).val)){
                list.remove(list.get(i));
                continue;
            }
            deleteNode(set, list.get(i));
        }
        return list;
    }

    public  void deleteNode(Set<Integer> set, TreeNode root) {
        if (root == null)
            return;
        if (root.left != null && set.contains(root.left.val))
            root.left = null;
        else
            deleteNode(set, root.left);
        if (root.right != null && set.contains(root.right.val))
            root.right = null;
        else
            deleteNode(set, root.right);
    }

    public  void dfs(Set<Integer> set, TreeNode root) {
        if (root == null)
            return;
        if (set.contains(root.val)) {
            if (isExist(set, root.left))
                dfs(set, root.left);
            if (root.left != null)
                list.add(root.left);
            if (isExist(set, root.right))
                dfs(set, root.right);
            if (root.right != null)
                list.add(root.right);
        } else {
            dfs(set, root.left);
            dfs(set, root.right);
        }
    }

    private  boolean isExist(Set<Integer> set, TreeNode root) {
        if (root == null)
            return false;
        if (set.contains(root.val))
            return true;
        return isExist(set, root.left) || isExist(set, root.right);
    }
} 
```
