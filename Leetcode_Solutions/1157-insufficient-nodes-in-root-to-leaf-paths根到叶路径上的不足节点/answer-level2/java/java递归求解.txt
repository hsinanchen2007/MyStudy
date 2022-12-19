非常适合递归求解。

先判断节点是否为叶子节点，如果是叶子节点，判断limit，如果不是，使用
```
root.left = sufficientSubset(root.left, limit - root.val);
root.right = sufficientSubset(root.right, limit - root.val);
```
将问题分解




```
public TreeNode sufficientSubset(TreeNode root, int limit) {
        
        //如果是叶子节点，判断是否满足limit，不满足返回null
        if(root.left == null && root.right == null){
            if(root.val < limit){
                return null;
            }
        }else{
            
            //如果是非叶子节点，将问题转化为两个子问题。
            
            if(root.left != null){
                root.left = sufficientSubset(root.left, limit - root.val);
            }
            if(root.right != null){
                root.right = sufficientSubset(root.right, limit - root.val);
            }
            //特别注意的是，如果左右两子树都不满足，则直接删除该节点
            if(root.left == null && root.right == null)
                return null;
            else{
                return root;
            }
        }
        return root;
        
    }
```