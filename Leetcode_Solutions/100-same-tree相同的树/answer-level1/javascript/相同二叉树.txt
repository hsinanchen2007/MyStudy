### 解题思路
整体使用递归调用的思路
通过题目描述找到 递归的 调用的规律
第一步判断val 是否相等
第二部判断 左值和右值为null 的情况
第三部判断在左值和有值 两个对象同时不为空的情况下递归调用左值和右值
第四部 如果两个对象左值和右值都为空，则返回true

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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    if(p === null && q === null) return true
    if((!p && q) || (p && !q)) return false

    function nodeCompare(a,b){
        if(a.val !== b.val){
            return false
        }else if((a.left && !b.left) || (a.right && !b.right) || (!a.left && b.left) || (!a.right && b.right)){
            return false
        }else if(a.left && b.left && a.right && b.right){
            return nodeCompare(a.left,b.left) && nodeCompare(a.right,b.right)
        }else if(a.left && b.left && !a.right && !b.right){
            return nodeCompare(a.left,b.left)
        }else if(!a.left && !b.left && a.right && b.right){
            return nodeCompare(a.right,b.right)
        }else {
            return true
        }
    }

     return nodeCompare(p,q)
};
```