### 解题思路
判断是否存在树, 存在就进入递归, 用个中间变量进行左右交换, 用解构赋值也行就是时间久了点

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
 * @return {TreeNode}
 */
var invertTree = function(root) {
   if(root){
     let midNode = root.left
     root.left = invertTree(root.right)
     root.right = invertTree(midNode)

    // [root.left,root.right] = [invertTree(root.right),invertTree(root.left)]
   }
    return root
};
```