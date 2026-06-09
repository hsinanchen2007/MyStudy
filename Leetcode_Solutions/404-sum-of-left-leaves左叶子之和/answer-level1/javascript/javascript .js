当一个左子树无左子树和右子树的时候，它就是所求的左叶子。
左叶子的判断写在判别函数sum中，而每一个节点都要判断，所以主函数中一个sum判断加上该节点的左右子树。
```
if(root==null) return 0;
   return sum(root)+sumOfLeftLeaves(root.left)+sumOfLeftLeaves(root.right) 
   
   function sum(root){
     if(root.left==null) return 0
     if(root.left.left==null&&root.left.right==null) return root.left.val;
     return 0
   }
```
