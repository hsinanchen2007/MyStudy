### 解题思路
逆中序遍历
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
 * @param {number} k
 * @return {number}
 */
var kthLargest = function(root, k) {
    let res = [];
    var dp = function(node){
        if(node===null)
            return;
        let rightVal = dp(node.right);
        res.push(node.val);
        let leftVal = dp(node.left);
    }
    dp(root);
    return res[k-1];
};
```