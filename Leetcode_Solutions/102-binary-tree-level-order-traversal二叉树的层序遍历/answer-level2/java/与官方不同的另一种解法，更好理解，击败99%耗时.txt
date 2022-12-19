用一个List存放每层的treeNode
```
    public List<List<Integer>> levelOrder(TreeNode root) {
        ArrayList<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        ArrayList<TreeNode> treeNodes = new ArrayList<>();
        //第一层
        treeNodes.add(root);
        while (treeNodes.size() != 0) {
            ArrayList<Integer> integers = new ArrayList<>();
            //一个临时list存放下一层node
            ArrayList<TreeNode> treeNodeTmp = new ArrayList<>();
            for (int i = 0; i < treeNodes.size(); i++) {
                TreeNode node = treeNodes.get(i);
                integers.add(node.val);
                if (node.left != null) treeNodeTmp.add(node.left);
                if (node.right != null) treeNodeTmp.add(node.right);
            }
            //替换临时list
            treeNodes = treeNodeTmp;
            result.add(integers);
        }
        return result;
    }
```
