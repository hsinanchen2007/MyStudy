```
// java双栈
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        List<Integer> row = new LinkedList<>();
        Stack<TreeNode> s1 = new Stack();
        Stack<TreeNode> s2 = new Stack();
        if(root == null)
            return res;
        int cur = 0;
        s1.push(root);
        TreeNode node, flag;
        while(!s1.isEmpty() || !s2.isEmpty()){
            if((cur & 0x1) == 0){
                while(!s1.isEmpty()){
                    node = s1.peek();
                    s1.pop();
                    row.add(node.val);
                    if(node.left != null)
                        s2.push(node.left);
                    if(node.right != null)
                        s2.push(node.right);
                }
                cur++;
                res.add(row);
                row = new LinkedList<>();
            }else{
                while(!s2.isEmpty()){
                    node = s2.peek();
                    s2.pop();
                    row.add(node.val);
                    if(node.right != null)
                        s1.push(node.right);
                    if(node.left != null)
                        s1.push(node.left);
                }
                cur++;
                res.add(row);
                row = new LinkedList<>();
            }
        }
        return res;
    }
}
```
