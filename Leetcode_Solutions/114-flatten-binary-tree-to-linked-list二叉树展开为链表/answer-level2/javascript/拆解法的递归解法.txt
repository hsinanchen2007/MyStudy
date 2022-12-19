
```
    1
   / \
  2   5
 / \   \
3   4   6

//将 1 的左子树插入到右子树的地方
    1
     \
      2         5
     / \         \
    3   4         6        
//将原来的右子树接到左子树的最右边节点
    1
     \
      2          
     / \          
    3   4  
         \
          5
           \
            6
            
 //将 2 的左子树插入到右子树的地方
    1
     \
      2          
       \          
        3       4  
                 \
                  5
                   \
                    6   
        
 //将原来的右子树接到左子树的最右边节点
    1
     \
      2          
       \          
        3      
         \
          4  
           \
            5
             \
              6         
  


```

```
var flatten = function(root) {
    helper(root);
};

function helper(root){
    if(root==null){
        return null;
    }
    var temp;
    //如果左节点不为空，说明需要移位操作
    if(root.left!=null){
        temp=root.right;
        //把左节点挪到右节点
        root.right=root.left;
        root.left=null;
        //找到最右下得节点
        var right=findRight(root.right);
        把之前拆解下的右节点接到最右下节点
        right.right=temp;
    }
    //递归下一个右节点，知道最后
    return helper(root.right);
}
//找到一个数的最右下节点
function findRight(root){
   if(root.right==null){
       return root;
   }
   return findRight(root.right);
}
```
