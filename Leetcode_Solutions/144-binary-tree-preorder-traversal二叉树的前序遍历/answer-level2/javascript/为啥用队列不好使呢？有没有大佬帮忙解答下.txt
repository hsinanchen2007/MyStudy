### 解题思路
这道题按照栈的思路来做就OK，但是如果换成队列，root->left->right就不好使呢

### 代码
* 这个是栈的，可以ac
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
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    let arr = [], q = root && [root] || []
    while(q.length) {
        let top = q.pop()
        arr.push(top.val)
        top.right && q.push(top.right)
        top.left && q.push(top.left)
        
    }
    return arr
};
```
*  这个是队列的，解答错误
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
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    let arr = [], q = root && [root] || []
    while(q.length) {
        let top = q.shift()
        arr.push(top.val)
        top.left && q.push(top.left)
        top.right && q.push(top.right)
       
        
    }
    return arr
};
```