## 递归
```
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        traversal(res, root);
        return res;
    }
    
    public void traversal(List<Integer> res, TreeNode root){
        if(root == null){
            return;
        }
        traversal(res, root.left);
        traversal(res, root.right);
        res.add(root.val);
    }
}
```

## 迭代
```
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while(cur != null || !stack.isEmpty()){
            while(cur != null){
                res.add(cur.val);
                stack.push(cur.left);
                cur = cur.right;  
            }
            cur = stack.pop();
        }
        Collections.reverse(res);
        return res;
    }
}
```