```
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        s1.push(root);
        while(!s1.isEmpty() || !s2.isEmpty()) {     // 不为空交叉打印，如果两个栈都为空，则说明已打印到树的最底层
            List<Integer> list = new ArrayList<>();
            while(!s1.isEmpty()) {
                TreeNode temp = s1.pop();
                list.add(temp.val);
                if(temp.left != null) {
                    s2.push(temp.left);
                }
                if(temp.right != null) {
                    s2.push(temp.right);    
                }  
            }
            if (!list.isEmpty()) {
                res.add(list);
            }
            
            list = new ArrayList<>();
            while(!s2.isEmpty()) {
                TreeNode temp = s2.pop();
                list.add(temp.val);
                if(temp.right != null) {
                    s1.push(temp.right); 
                }
                if(temp.left != null) {
                    s1.push(temp.left);
                }
            }  
            if (!list.isEmpty()) {
                res.add(list);
            }
        }
        return res;
    }
}
```
