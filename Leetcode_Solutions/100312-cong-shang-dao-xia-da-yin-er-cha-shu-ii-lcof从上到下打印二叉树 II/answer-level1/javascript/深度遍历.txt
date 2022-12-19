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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    var len = 1; // 该层节点数量
    var queue = [root] // 当前层级节点数量
    var res = []
    var temp = [];
    while(queue.length) {
        var node = queue.shift();
        temp.push(node.val);
        node.left && queue.push(node.left);
        node.right && queue.push(node.right);
        len--;
        if (!len) {
            res.push(temp);
            temp = [];
            len = queue.length;
        }
    }
    return res;
};
```