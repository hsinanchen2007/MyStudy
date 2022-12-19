### 解题思路

层遍历

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
var largestValues = function(root) {
    if (!root) return []
    let q = [root]
    let ans = []
    while(q.length > 0){
        let k = q.length
        let max = 1 << 31;
        for (let m = 0; m < k; m++){
            let node = q[0]
            q.shift()
            max = Math.max(max, node.val)
            node.left && q.push(node.left)
            node.right && q.push(node.right)
        }
        ans.push(max)
    }
    return ans
};
```