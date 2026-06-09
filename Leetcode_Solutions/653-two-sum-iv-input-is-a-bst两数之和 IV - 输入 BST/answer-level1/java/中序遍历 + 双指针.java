    ``` java
    public boolean findTarget(TreeNode root, int k) {
        if(root == null) { return false; }
        List<Integer> list = new ArrayList<>();
        inOrder(list, root);
        int x = 0, y = list.size() - 1, m1, m2, sum;
        while (x < y) {
            m1 = list.get(x);
            m2 = list.get(y);
            sum = m1 + m2;
            if(sum == k) {
                return true;
            } else if (sum < k ) {
                ++x;
            } else {
                --y;
            }
        }
        return false;
    }

    // 中序遍历
    public void inOrder(List<Integer> vs, TreeNode node) {
        // if (null == node) { return; }
        if (node.left != null) { inOrder(vs, node.left); }
        vs.add(node.val);
        if (node.right != null) { inOrder(vs, node.right); }
    }
    ```