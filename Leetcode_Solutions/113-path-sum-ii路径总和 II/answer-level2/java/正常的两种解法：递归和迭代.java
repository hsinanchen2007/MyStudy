递归：
```
public List<List<Integer>> pathSum(TreeNode root, int sum) {
        //1.
        List<List<Integer>> treeList = new ArrayList<>();
        if (root == null) {
            return treeList;
        }
        //2. 判断是否叶子节点
        if (root.left == null && root.right == null) {
            if (root.val == sum) {
                treeList.add(new ArrayList<Integer>());
                treeList.get(0).add(root.val);
            }
            return treeList;
        }
        //3. 递归左右分支
        List<List<Integer>> leftLists = pathSum(root.left, sum - root.val);
        List<List<Integer>> rightLists = pathSum(root.right, sum - root.val);
        //4. 合并到一个list
        leftLists.addAll(rightLists);
        return getLists2(leftLists, root.val);
    }
    private List<List<Integer>> getLists2(List<List<Integer>> lists, int val) {
        for (List<Integer> list : lists) {
            list.add(0, val);
        }
        return lists;
    }
```

迭代：就是一层一层迭代，代码写的比较烂，就不贴了
