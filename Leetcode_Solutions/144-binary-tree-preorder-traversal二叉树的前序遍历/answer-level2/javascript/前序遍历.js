### 解题思路
前序遍历，就是从根节点开始，先遍历左子树，再遍历右子树
把路过的value都放到数组中
如果子树到了末尾，就直接return

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

var preorderTraversal = function(root) {
    let arr = []
    pre(root ,arr)    
    return arr
};

var pre = function(root,arr){
     if(root == null) {return}
        arr.push(root.val)
        pre(root.left,arr)
        pre(root.right,arr)
    return arr
}
```