### 解题思路
方法1： BFC，广度优先遍历。进入下一层之前加1
方法2： 递归，一个节点往下的深度等于左边节点往下的深度和右边节点往下的深度两者中的最大值加1

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
// 方法1 BFC
var maxDepth = function(root) {
    if(root == null) return 0
    let stack = [];
    stack.push(root)
    let depth = 0
    while(stack.length != 0) {
        depth ++ 
        let temp = []
        for(let node of stack) { 
            if(node.left) temp.push(node.left);
            if(node.right) temp.push(node.right)
        }
        stack = temp
    }
    return depth
};

// 方法2 递归

var maxDepth = function(root) {
    if(root===null) return 0;
    return Math.max(maxDepth(root.left),maxDepth(root.right))+1
};
```