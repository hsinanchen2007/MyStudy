```Java []
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Stack<TreeNode> st_0 = new Stack<TreeNode>();
        Stack<TreeNode> st_1 = new Stack<TreeNode>();
        if(root == null) return res;
        st_0.push(root);
        while(!st_0.empty() || !st_1.empty()){
            List<Integer> oneList = new ArrayList<Integer>();
            if(!st_0.empty()){
                while(!st_0.empty()){
                    TreeNode t = st_0.pop();
                    oneList.add(t.val);
                    if(t.left != null) st_1.push(t.left);
                    if(t.right != null) st_1.push(t.right);
                }
            }else{
                while(!st_1.empty()){
                    TreeNode t = st_1.pop();
                    oneList.add(t.val);
                    if(t.right != null) st_0.push(t.right);
                    if(t.left != null) st_0.push(t.left);
                }
            }
            res.add(oneList);
        }
        return res;
    }
}
```