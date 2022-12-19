```
public boolean isCompleteTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean flag = false;
        TreeNode tmp;
        while (!queue.isEmpty()){
            tmp = queue.poll();
            if (tmp.left == null && tmp.right != null)
                return false;
            if (tmp.left != null){
                if (flag)
                    return false;
                queue.add(tmp.left);
            }else {
                flag = true;
            }
            if (tmp.right != null){
                if (flag)
                    return false;
                queue.add(tmp.right);
            }else {
                flag = true;
            }
        }
        return true;
    }
```
