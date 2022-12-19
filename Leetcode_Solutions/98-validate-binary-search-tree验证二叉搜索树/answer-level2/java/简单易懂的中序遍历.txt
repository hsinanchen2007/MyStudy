先吐槽一下：这个题真的搞，搞了这么一个数据：[-2147483648]
```java
class Solution {
    public boolean isValidBST(TreeNode root) {
        if(root == null) return true;
        double min = -Double.MAX_VALUE;
        Stack<TreeNode> stack = new Stack<>();
        while(!stack.isEmpty() || root !=  null) {
            if (root != null) {
                stack.push(root);
                root = root.left;
            }else {
                root = stack.pop();
                if (root.val <= min) return false;
                min = root.val;
                root = root.right;
            }
        }
        return true;
    } 
}