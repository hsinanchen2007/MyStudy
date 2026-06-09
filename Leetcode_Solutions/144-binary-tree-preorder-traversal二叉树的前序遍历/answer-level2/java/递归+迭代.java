## 递归
```
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        traversal(res, root);
        return res;
    }
    
    public void traversal(List<Integer> res, TreeNode root){
        if(root == null){
            return;
        }
        res.add(root.val);
        traversal(res, root.left);
        traversal(res, root.right);
    }
}
```
## 迭代
```
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                res.add(cur.val);
                stack.push(cur.right);
                cur = cur.left;  
            }
            cur = stack.pop();
        }
        return res;
    }
}
```