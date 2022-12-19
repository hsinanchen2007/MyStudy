后序遍历右节点和根节点永远在左节点的后面，符合栈先进后出的特点。将temp栈按顺序弹出就是遍历结果。

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        Stack<TreeNode> temp = new Stack<>();
        TreeNode curr = root;
        while(curr!=null || !stack.isEmpty()){
            while(curr!=null){
                temp.push(curr);
                stack.push(curr);
                curr = curr.right;
            }
            curr = stack.pop();
            curr = curr.left;
        }
        while(!temp.isEmpty()){
            res.add(temp.pop().val);
        }
        return res;
    }
}