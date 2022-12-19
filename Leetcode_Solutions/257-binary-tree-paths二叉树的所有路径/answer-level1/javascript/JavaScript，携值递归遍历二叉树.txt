### 解题思路
递归过程中，每个节点携带着自己遍历过的值，一旦达到叶子节点。就把携带的值放到result中即可

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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    let result = []
    function traverse(node, payload){
        if(node == null) return;
        payload.push(node.val)
        if(node.left == null && node.right == null) {
            result.push(payload.join('->'))
            return;
        }
        if(node.left) {
            traverse(node.left,[...payload])
        }
        if(node.right) {
            traverse(node.right,[...payload]) 
        }
    }
    traverse(root,[])
    return result
};
```