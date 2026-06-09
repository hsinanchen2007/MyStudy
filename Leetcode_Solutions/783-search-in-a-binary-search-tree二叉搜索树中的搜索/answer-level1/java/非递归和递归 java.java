```
class Solution {//非递归
    public TreeNode searchBST(TreeNode root, int val) {
     Stack<TreeNode> stack=new Stack();
     if(root!=null){
         stack.push(root);
         while(!stack.isEmpty()){
             TreeNode ss=stack.pop();
             if(ss.val==val)     return ss;
             if(ss.right!=null)  stack.push(ss.right);
             if(ss.left!=null)   stack.push(ss.left);
         }
     }
         return null;
    }
}
```

```
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
    
    
        
    if(root!=null){   
    if(root.val<val)   return searchBST(root.right,val);
    else if(root.val>val)  return searchBST(root.left,val);
    else  if(root.val==val) return root;
    }  
    
        
 return null;   
}
}
```