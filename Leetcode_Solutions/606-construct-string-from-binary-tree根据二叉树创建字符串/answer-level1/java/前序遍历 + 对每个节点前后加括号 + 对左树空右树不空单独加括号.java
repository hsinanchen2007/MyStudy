![image.png](https://pic.leetcode-cn.com/981abc1a8d107e7176cb2efd4914d36cf5bdff04214e13c31e70a3b3a2f017ef-image.png)

    StringBuilder sb = new StringBuilder();
    public String tree2str(TreeNode t) {
        if(t == null) {
            return "";
        }
        helper(t);
        sb.deleteCharAt(0);
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
    public void helper(TreeNode t) {
        if(t == null) {
            return;
        }
        sb.append('(');
        sb.append(t.val);
        if(t.left == null && t.right != null) {
            sb.append("()");
        }
        helper(t.left);
        helper(t.right);
        sb.append(')');
    }