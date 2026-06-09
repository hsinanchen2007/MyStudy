逆中序，定义一个变量记录累加值



```
class Solution {
    public int a=0;
    
    
    public TreeNode convertBST(TreeNode root) {
    
       in(root); 
        
       return root; 
        
        
    }
    
    public void in(TreeNode root)
    {
       if(root!=null)
       {
           in(root.right);
             a+=root.val;
             root.val=a;;
            in(root.left);  
       }
        
        
        
    }
}  
```

