```
public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if(root != null)
            queue.offer(root);
        while (!queue.isEmpty()){
                int size = queue.size();
                List<Integer> tmp = new ArrayList<>();
                for (int i = 0; i < size; i++){
                    TreeNode treeNode = queue.poll();
                    tmp.add(treeNode.val);
                    if(null != treeNode.left)
                        queue.offer(treeNode.left);
                    if(null != treeNode.right)
                        queue.offer(treeNode.right);
            }
                result.add(0,new ArrayList<>(tmp));
        }
        return result;
    }
```
