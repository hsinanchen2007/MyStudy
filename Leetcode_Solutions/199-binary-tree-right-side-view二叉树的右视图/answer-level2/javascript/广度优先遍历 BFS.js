### 解题思路
BFS

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
var rightSideView = function(root) {
    if(!root) return []
    root.count = 0
    let queue = [root]
    let ans = [root.val]
    while (queue.length) {
        let cur = queue.pop()
        if(cur.right) {
            cur.right.count = cur.count + 1
            queue.unshift(cur.right)
            // ans.unshift(cur.right.val)
            if(ans[cur.count + 1] == undefined) ans[cur.count + 1] = cur.right.val
        } 
        if (cur.left) {
            cur.left.count = cur.count + 1
            queue.unshift(cur.left)
            if(ans[cur.count + 1] == undefined) ans[cur.count + 1] = cur.left.val
        }
        // console.log(queue)
    }
    return ans
};
```