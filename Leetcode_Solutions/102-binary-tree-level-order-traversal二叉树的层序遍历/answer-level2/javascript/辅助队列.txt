### 解题思路
构建一个辅助队列，每次将下一层的元素入队。

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
    const res = [];
    let queue = [root];
    while (queue.length) {
        res.push(queue.map(item => item.val));
        const currentLevel = [];
        while(queue.length) {
            const current = queue.shift();
            if (current.left) currentLevel.push(current.left);
            if (current.right) currentLevel.push(current.right);
        }
        queue = currentLevel;
    }
    return res;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)