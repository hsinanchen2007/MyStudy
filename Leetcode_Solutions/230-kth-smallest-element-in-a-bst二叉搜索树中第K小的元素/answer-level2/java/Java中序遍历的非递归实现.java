public class _230_KthSmallest {

    // inorder
    public static int kthSmallest(TreeNode root, int k) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNode> stack = new Stack<>();
        ArrayList<Integer> array = new ArrayList<>();
        TreeNode node = root;
        while (true) {
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else if (stack.isEmpty()) {
                break;
            } else {
                node = stack.pop();
                array.add(node.val);
                node = node.right;
            }
        }
        
        return array.get(k - 1);
    }
}