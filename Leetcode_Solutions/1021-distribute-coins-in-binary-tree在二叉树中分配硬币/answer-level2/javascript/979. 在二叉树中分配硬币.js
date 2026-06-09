### 解题思路
深度优先遍历的时候要保留两个值才能保证返回。
- 首先要保留深度优先遍历移动之后该节点的值
- 然后在深度优先遍历过程中迭代步长

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
var distributeCoins = function(root) {
   let path = 0; 
   let helper = function(node){
        if(node == null) return 0;
        let rightVal = helper(node.right);
        let leftVal = helper(node.left);
        path += Math.abs(rightVal)+Math.abs(leftVal);
        return rightVal+leftVal+node.val-1;
   }
   helper(root);
   return path;
};
```