    public int kthSmallest_v1(TreeNode root, int k) {
        return kthSmallest_recursion(root, k, new int[1]);
    }

    private int kthSmallest_recursion(TreeNode root, int k, int[] res) {
        if(root == null)return 0;
        int val = kthSmallest_recursion(root.left, k, res);
        if(res[0] == k) return val;
        else if(++res[0] == k) return root.val;
        return kthSmallest_recursion(root.right, k, res);
    }

局部变量能解决的，能不用成员变量还是不要用，对性能有影响，从设计模式上来说也不好。