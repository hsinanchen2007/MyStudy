

```
//递归解法
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if ( t1 == null && t2 == null ) {
            return null;
        }
        
        if ( t1 ==null || t2 == null ) {
            return t1 == null ? t2 : t1;
        }
        t1.val += t2.val;
        t1.left = mergeTrees(t1.left , t2.left);
        t1.right = mergeTrees(t1.right , t2.right);
        return t1;
    }

//迭代解法
public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        if ( t1 == null && t2 == null ) {
            return null;
        }
        if ( t1 ==null || t2 == null ) {
            return t1 == null ? t2 : t1;
        }
        
        Stack<TreeNode> stack1 = new Stack<>();
        Stack<TreeNode> stack2 = new Stack<>();
        stack1.push(t1);
        stack2.push(t2);
        
        while( !stack1.isEmpty() || !stack2.isEmpty() ) {
            
            TreeNode p1 = stack1.pop();
            TreeNode p2 = stack2.pop();
            
            p1.val += p2.val;
            
            if ( p2.left != null ) {
                if ( p1.left == null ) {
                    p1.left = p2.left;
                }
                else {
                    stack1.push(p1.left);
                    stack2.push(p2.left);
                }
            }
            
            if ( p2.right != null ) {
                if( p1.right == null ) {
                    p1.right = p2.right;
                }
                else {
                    stack1.push(p1.right);
                    stack2.push(p2.right);
                }
            }
        }
        return t1;
    }
```
