# 解题思路
- 排除边界情况，p与q的null处理
- 初始及递归情况处理，当前节点p与q的val比较
- 递归比对树的子节点
# 代码
```javascript
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
    if(p == null && q == null){
        return true
    }else if(p==null || q==null){
        return false
    }else if(p.val != q.val){
        return false
    }else{
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right)
    }
};
```