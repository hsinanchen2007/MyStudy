思路很简单
```
   List<Integer> result=new ArrayList<>();
    public List<Integer> rightSideView(TreeNode root) {
        if(root==null){
            return result;
        }
        List<TreeNode> treeNodes=new ArrayList<>();
        treeNodes.add(root);
        bfs(treeNodes);
        return result;
    }

    private void bfs(List<TreeNode> curLevel) {
        if (curLevel.size() == 0) {
            return;
        }
        result.add(curLevel.get(curLevel.size() - 1).val);
        List<TreeNode> nextLevel = new ArrayList<>();
        for (TreeNode treeNode : curLevel) {
            if (treeNode.left != null) {
                nextLevel.add(treeNode.left);

            }
            if (treeNode.right != null) {
                nextLevel.add(treeNode.right);
            }
        }
        bfs(nextLevel);

    }
```
