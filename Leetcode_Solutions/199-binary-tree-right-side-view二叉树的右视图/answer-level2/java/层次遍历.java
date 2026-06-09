想到的是层次遍历，只是在层次遍历的过程中需要两个变量记录上一层和下一层最后一个节点

```
   
 public List<Integer> rightSideView(TreeNode root) {
        List<Integer> resultList = new ArrayList<>();
        if (root == null) {
            return resultList;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        TreeNode preLevelLast = root;
        TreeNode nextLevelLast = root;
        while (!queue.isEmpty()) {
            TreeNode curr = queue.poll();
            if (curr.left != null) {
                queue.offer(curr.left);
                nextLevelLast = curr.left;
            }
            if (curr.right != null) {
                queue.offer(curr.right);
                nextLevelLast = curr.right;
            }
            if (curr == preLevelLast) {
                resultList.add(curr.val);
                preLevelLast = nextLevelLast;
            }
        }

        return resultList;
    }

```
