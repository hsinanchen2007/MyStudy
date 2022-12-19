
## 递归
递归即采用分治算法的思想。
```java
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if(root==null) return result;
        result.addAll(postorderTraversal(root.left));
        result.addAll(postorderTraversal(root.right));
        result.add(root.val);
        return result;
    }
```

## 迭代
用栈暂存访问的路径，对已经访问过的节点分支进行着色。
```java
public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if(root==null) return result;
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode node = stack.pop();
            if(node.left!=null) {
                TreeNode temp = node.left;
                // 用null来着色，表示当前节点的左子节点已经访问过                
                node.left=null;
                stack.push(node);
                stack.push(temp);
            }else if(node.right!=null){
                TreeNode temp = node.right;
                // 用null来着色，表示当前节点的右子节点已经访问过                
                node.right=null;
                stack.push(node);
                stack.push(temp);
            }else{
                result.add(node.val);
            }  
        }
        return result;
    }
```