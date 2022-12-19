### 解题思路
方法一、递归

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if(p.val>root.val && q.val>root.val){
        return lowestCommonAncestor(root.right,p,q);
    }else if(p.val<root.val && q.val<root.val){
        return lowestCommonAncestor(root.left,p,q);
    }else {
        return root;
    }

};
```
方法二、迭代
```
var lowestCommonAncestor = function(root, p, q) {
    while(root!=null){
        if(p.val>root.val && q.val>root.val){
            root = root.right;
        }else if(p.val<root.val && q.val<root.val){
            root = root.left;
        }else{
            return root;
        }
    }
};
```

