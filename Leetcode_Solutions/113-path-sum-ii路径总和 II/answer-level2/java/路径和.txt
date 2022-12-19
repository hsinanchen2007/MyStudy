```
List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null){
            return ans;
        }
        pathSum(root, sum - root.val, new ArrayList<>());
        return ans;
    }

    public void pathSum(TreeNode root, int sum, List<Integer> path) {
        if (root == null) return;
        path.add(root.val);
        //判断当前值是否为零，并且当前节点是否是叶子节点
        if (sum == 0 && root.left == null && root.right == null){
            ans.add(new ArrayList<>(path));
            return;
        }
    
        if (root.left != null){
            pathSum(root.left, sum - root.left.val, path);
            path.remove(path.size() - 1);
        }
        if (root.right != null){
            pathSum(root.right, sum - root.right.val, path);
            path.remove(path.size() - 1);
        }
    }
```
