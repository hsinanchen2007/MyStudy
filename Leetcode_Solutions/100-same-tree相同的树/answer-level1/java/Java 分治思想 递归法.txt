之前使用递归很不熟练。总结一下，写函数的时候，想明白在什么条件下应该return TorF；在什么条件下应该递归判断子问题。然后把递归模块写在return里面就可以啦~
```
class Solution {
public boolean isSameTree(TreeNode p, TreeNode q) {
        if( p!=null && q!=null && p.val == q.val ){
            return (isSameTree(p.left,q.left) && isSameTree(p.right,q.right));
        }
        else if(p==null && q==null){
            return true;
        }
        else{
            return false;
        }
        
    }
}
```

