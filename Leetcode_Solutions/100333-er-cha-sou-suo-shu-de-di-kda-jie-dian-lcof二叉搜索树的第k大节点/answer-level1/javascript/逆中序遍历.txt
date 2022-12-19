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
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthLargest = function(root, k) {
    let res = []
    const helper = (root) => {
        if(root == null) return 0
        if(root.right) helper(root.right)
        res.push(root.val)
        if(root.left) helper(root.left)
    }
    helper(root)
    for(let i=0; i<res.length; i++){
        if((i+1) === k) return res[i]
    }
    return 0
};
```