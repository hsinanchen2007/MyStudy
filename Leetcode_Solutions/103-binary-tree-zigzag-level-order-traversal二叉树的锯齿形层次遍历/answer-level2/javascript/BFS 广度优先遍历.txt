### 解题思路
广度优先遍历

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
var zigzagLevelOrder = function(root) {
    if(root == null) return []
    let queue = [root]
    let direction = false
    let ans = [[root.val]]
    while(queue.length >0 ){
        let cur
        let newQueue = []
        
        for(let i in queue){
            queue[i].left && newQueue.push(queue[i].left)
            queue[i].right && newQueue.push(queue[i].right)
        }

        cur = []
        
        newQueue.forEach(ele => {
            if(direction) {
                cur.push(ele.val)
            } else {
                cur.unshift(ele.val)
            }
        })
        cur.length > 0 && ans.push(cur)
        direction = !direction
        queue = newQueue
    }
    return ans
};
```