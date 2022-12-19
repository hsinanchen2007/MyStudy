```java
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<TreeNode> queue = new LinkedList<>();
        // 每个节点的值都是唯一的
        Map<Integer, Integer> parent = new HashMap<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            Set<Integer> keySet = parent.keySet();
            // 如果该层同时包含两个节点
            if (keySet.contains(x) && keySet.contains(y)) {
                // 并且两个节点的父节点不同, 则是堂兄弟节点
                if (!parent.get(x).equals(parent.get(y)))
                    return true;
            } else {
                // 如果该层只包含一个节点, 则不是
                if (keySet.contains(x) || keySet.contains(y))
                    return false;
            }
            parent.clear();

            int size = queue.size();
            // 遍历该层所有节点, 并将下一层的节点的父节点设置为该层节点
            while (size-- > 0) {
                TreeNode temp = queue.remove();
                if (temp.left != null) {
                    queue.add(temp.left);
                    parent.put(temp.left.val, temp.val);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                    parent.put(temp.right.val, temp.val);
                }
            }
        }
        return false;
    }
```