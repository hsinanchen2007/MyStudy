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
    // 存储所有的结果
    let result = [];
    /**
     * 优先广度遍历
     * @param tree 递归树
     * @param i 用于层数的指针
     */
    function recursion(tree,i) {
        if(!tree) return ;
        // 广度遍历
        recursion(tree.left,i+1);
        recursion(tree.right,i+1);
        // 初始化数组
        if(!result[i]) result[i] = [];
        result[i].push(tree.val)
    }
    recursion(root,0);
    return result;
};
```