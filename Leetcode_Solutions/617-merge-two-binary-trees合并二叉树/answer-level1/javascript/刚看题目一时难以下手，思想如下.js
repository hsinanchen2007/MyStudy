```javascript []
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} t1
 * @param {TreeNode} t2
 * @return {TreeNode}
 */
var mergeTrees = function(t1, t2) {
    
   //如果两方树有一个为null，直接返回另一个树
    if(t1 == null){
        return t2;
    }else if(t2 == null){
        return t1;
    }else{
         //两个树都不为null 初始化一颗树 并为其left right赋值 根据执行顺序 碰到mergeTress 会先暂停代码 执行mergeTress执行完之后 继续向下执行 所以等赋值完成之后 才会返回这颗树
    let root = new TreeNode(t1.val+t2.val);
    root.left = mergeTrees(t1.left,t2.left);
    root.right = mergeTrees(t1.right,t2.right);
    return root;
    }
    
};
```


