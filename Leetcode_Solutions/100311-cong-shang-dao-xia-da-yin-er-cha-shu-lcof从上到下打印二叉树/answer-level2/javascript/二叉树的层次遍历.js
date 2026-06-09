### 解题思路
广度优先搜索（二叉树的层次遍历）；
时间复杂度：O（nlogn）
空间复杂度：O(n)

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
    if (!root)return [];
    const result = [];
    const queue = [root];
    while(queue.length) {
        for (let i = 0; i < queue.length; i++){
            let cur = queue.shift();
            cur.left && queue.push(cur.left);
            cur.right && queue.push(cur.right);
            result.push(cur.val);
        }
    }return result;
};
```