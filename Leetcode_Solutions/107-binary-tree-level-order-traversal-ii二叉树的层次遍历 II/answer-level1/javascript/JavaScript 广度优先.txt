```
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
 * 广度优先
 */
var levelOrderBottom = function(root) {
    let queue = [root]
    if (!root)
        return [];
    let res = [];
    while(queue.length) {
        let nextQueue = [],
            resItem = [];
        for (let i = 0; i < queue.length; i++) {
            resItem.push(queue[i].val);
            queue[i].left ? nextQueue.push(queue[i].left) : null;
            queue[i].right ? nextQueue.push(queue[i].right) : null;
        }
        res.push(resItem);
        queue = nextQueue;
    }
    return res.reverse();
};
```