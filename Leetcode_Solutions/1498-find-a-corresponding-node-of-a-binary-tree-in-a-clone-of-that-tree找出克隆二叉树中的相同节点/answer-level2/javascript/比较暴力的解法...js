### 解题思路
此处撰写解题思路

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
 * @param {TreeNode} original
 * @param {TreeNode} cloned
 * @param {TreeNode} target
 * @return {TreeNode}
 */

var getTargetCopy = function(original, cloned, target) {
    let ans
    function isSameTree(node1, node2) {
        // console.log(node1,node2)
        if(node1 === null && node2 === null) return true
        if(node1 === null || node2 === null) return false
        if(node1.val == node2.val) {
            return isSameTree(node1.left, node2.left) && isSameTree(node1.right, node2.right) 
        }
        return false
    }
    function traversal(node) {
        if(node == null) return
        if(isSameTree(node, target)) {
            // console.log(node)
            ans = node
            return 
        }
        traversal(node.left)
        traversal(node.right)
    }
    traversal(cloned)
    return ans
};
```