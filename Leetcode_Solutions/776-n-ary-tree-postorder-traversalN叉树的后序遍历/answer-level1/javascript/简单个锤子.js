### 解题思路
后序遍历首先遍历左子树，然后遍历右子树，最后访问根结点，在遍历左、右子树时，仍然先遍历左子树，然后遍历右子树，最后遍历根结点。

递归还要另起一个函数了递归

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 * 执行用时 :76 ms, 在所有 javascript 提交中击败了99.19%的用户
 * 内存消耗 :39.5 MB, 在所有 javascript 提交中击败了100.00%的用户
 */

var postorder = function(root) {
  if(!root) return []
  let list = []
  ;(function (root){
    if(!root) return
    root.children.forEach(item=>{
      arguments.callee(item)
    })
    list.push(root.val)
  })(root)
  return list
};
```