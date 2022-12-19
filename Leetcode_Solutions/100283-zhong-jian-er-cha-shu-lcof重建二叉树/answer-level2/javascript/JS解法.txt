### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = null;  
 *     this.right = null;
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    let result = null;
    if(preorder.length > 1){
        let root = preorder[0];
        let index = inorder.indexOf(root);
        let inorderLeft = inorder.slice(0,index);
        let inorderRight = inorder.slice(index+1);
        preorder.shift();
        let preorderLeft = preorder.slice(0, inorderLeft.length);
        let preorderRight = preorder.slice(inorderLeft.length);
        result = {
            val: root,
            left: buildTree(preorderLeft, inorderLeft),
            right: buildTree(preorderRight, inorderRight)
        }
    }else if(preorder.length === 1){
        result = {
            val: preorder[0],
            left: null,
            right: null
        }
    }
    return result 
};
```