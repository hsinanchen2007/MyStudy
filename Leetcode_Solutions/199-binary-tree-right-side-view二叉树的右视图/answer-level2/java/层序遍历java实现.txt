```
public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        if (root == null){
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode node = root;
        queue.add(node);
        TreeNode currentLast = node;
        TreeNode nextLast = null;
        while (!queue.isEmpty()){
            node = queue.poll();
            if (node.left!=null){
                queue.add(node.left);
                nextLast = node.left;
            }

            if (node.right != null){
                queue.add(node.right);
                nextLast = node.right;
            }

            if (node == currentLast){
                result.add(node.val);
                currentLast = nextLast;
            }
        }
        return result;
    }
```