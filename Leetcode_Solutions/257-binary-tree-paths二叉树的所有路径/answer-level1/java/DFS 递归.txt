用dfs遍历，每次遍历一个节点时判断它是否是叶子节点，如果是叶子节点，将结果记录到数组中，否则将该节点记录到路径中。
```
 public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<String>();
        if (root == null) return list;
        helper(root,String.valueOf(root.val),list);
        return list;
    }
    public void helper(TreeNode root,String path,List<String > list)
    {
        if (root == null) return;

        if (root.left == null && root.right == null) list.add(path);
        if (root.left != null)
            helper(root.left,path + "->" + root.left.val,list);
        if (root.right != null)
            helper(root.right,path + "->" + root.right.val,list);
    }
```
