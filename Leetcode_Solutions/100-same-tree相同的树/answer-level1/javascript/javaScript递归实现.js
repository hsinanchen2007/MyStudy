一开始写起来经常有`can't read x of p`类似的报错，感觉用递归写就是`if`的顺序要放好
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {   
    if(!p && !q) return true
    if(p && q && p.val === q.val && !p.left && !p.right && !q.left && !q.right) return true
    
    if(p && !q || !p && q) return false
    if(p.val !== q.val) return false
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
};
```