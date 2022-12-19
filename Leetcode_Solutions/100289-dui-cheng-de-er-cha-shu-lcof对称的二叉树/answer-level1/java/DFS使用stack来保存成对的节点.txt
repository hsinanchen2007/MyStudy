class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
                Stack<TreeNode> s = new Stack<>();
                s.push(root.left);
                s.push(root.right);
                while(!s.empty()) {
                    TreeNode right = s.pop();
                    TreeNode left = s.pop();

                    if(left == null && right == null) continue;
                    if(left == null || right == null) return false;
                    if(left.val != right.val) return false;
                
                    s.push(left.left);
                    s.push(right.right);
                    s.push(left.right);
                    s.push(right.left);
                }
        return true;
    }
}