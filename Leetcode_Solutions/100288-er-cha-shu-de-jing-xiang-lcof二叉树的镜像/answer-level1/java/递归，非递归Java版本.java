递归版本：
public class Solution {
    public void Mirror(TreeNode root) {
        if (root == null)
            return;
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        Mirror(root.left);
        Mirror(root.right);
    }
}

非递归版本：
public class Solution {
    public void Mirror(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()){
            TreeNode node = queue.poll();
            if (node == null)
                continue;
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;
            queue.add(node.left);
            queue.add(node.right);
        }
    }
