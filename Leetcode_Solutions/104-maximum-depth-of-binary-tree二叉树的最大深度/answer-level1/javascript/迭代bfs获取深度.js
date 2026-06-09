### 解题思路
使用层次遍历，每跳一层level加1 ，最后值就是最大深度

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
 * @return {number}
 */
var maxDepth = function(root) {
    var level = 0;
    if(!root){
        return level;
    }
    var queue = [root];
    while(queue.length){
        var queueLen = queue.length;
        for(let i=0;i<queueLen;i++){
            var cur = queue.pop();
            cur.left && queue.unshift(cur.left);
            cur.right && queue.unshift(cur.right);
        }
        level++;

    }
    return level;
};
```