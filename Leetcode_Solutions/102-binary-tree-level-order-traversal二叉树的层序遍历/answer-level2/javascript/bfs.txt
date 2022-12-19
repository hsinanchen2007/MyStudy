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
    let queue = []
    let res = []
    if(root) queue.push(root)
    while(queue.length>0){
        let arr = []
        let newQueue = []
        while(queue.length>0){
            let cur = queue.shift()
            arr.push(cur.val)
            if(cur.left) newQueue.push(cur.left)
            if(cur.right) newQueue.push(cur.right)
        }
        queue = newQueue
        if(arr.length>0) {
            res.push(arr)
        }
    }
    return res
};
```