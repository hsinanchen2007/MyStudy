先序遍历就是深度优先遍历，层序遍历就是广度优先遍历
参考大神：[题解](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/solution/mian-shi-ti-55-i-er-cha-shu-de-shen-du-xian-xu-bia/)
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
 * @return {number}
 */

// 先序遍历／深度优先遍历
var maxDepth = function(root) {
    let depthorder = function(node) {
        if(!node) return 0;
        return Math.max(depthorder(node.left), depthorder(node.right)) + 1;
        
    }
    return depthorder(root);
};
```
