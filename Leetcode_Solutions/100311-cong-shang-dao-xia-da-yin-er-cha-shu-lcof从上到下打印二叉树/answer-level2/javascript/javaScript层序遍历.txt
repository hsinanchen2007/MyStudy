
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
 * @return {number[]}
 */

var levelOrder = function(root) {
    var queue = [];
    var res = [];
    if(!root) return res;
    queue.push(root);
    while(queue.length){
        var item = queue.shift();
        res.push(item.val);
        if(item.left) queue.push(item.left);
        if(item.right) queue.push(item.right);
    }
    return res;
};
```