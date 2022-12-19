终止条件
+ 根节点为叶子节点，val小于叶子节点值则置于左孩子，val大于叶子节点值置于右孩子
+ 根节点不为叶子节点，左孩子为空并val小于叶子节点值则置于左孩子，右孩子为空并val大于叶子节点值置于右孩子
```js
var insertIntoBST = function(root, val) {
    var node = new TreeNode(val);
    dfs(root);
    return root;
    function dfs(root){
        if(!root) return;
        if(root && !root.left && !root.right){
            if(root.val > val){
                root.left = node;
            }else if(root.val < val){
                root.right = node;
            }
        }
        if(root.val < val){
            if(!root.right){
                root.right = node;
                return;
            }
            dfs(root.right);
        }
        if(root.val > val){
            if(!root.left){
                root.left = node;
                return;
            }
            dfs(root.left);
        }
    }
};
```