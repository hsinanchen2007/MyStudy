```
    public int findSecondMinimumValue(TreeNode root) {

        int min = root.val;
        int min2 = Integer.MAX_VALUE;
        boolean flag = false;
        List<TreeNode> queue = new ArrayList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.remove(0);
            if (node.val < min) {
                min2 = min;
                min = node.val;
            }
            if (node.val < min2 && node.val > min) {
                min2 = node.val;
                flag = true;
            }

            if (node.left != null) {
                queue.add(node.left);
                queue.add(node.right);
            }
        }
        if (flag) {
            return min2;
        }else{
            return -1;
        }

    }
```
不知道为啥，对于我来说我总觉的迭代比递归好理解多了[捂脸]
