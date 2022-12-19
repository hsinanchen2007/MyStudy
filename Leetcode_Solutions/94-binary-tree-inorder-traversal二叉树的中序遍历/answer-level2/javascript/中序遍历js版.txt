### 解题思路
中序遍历，先左子树，后根结点，最后右子树
注意：函数的参数，第二个是自设，初始化为[],不需要传入，才能通过测试。

参考http://www.conardli.top/docs/dataStructure/%E4%BA%8C%E5%8F%89%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86.html#%E9%A2%98%E7%9B%AE


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
var inorderTraversal = function(root,array=[]) {
  if(root){
     inorderTraversal(root.left,array);
     array.push(root.val);
     inorderTraversal(root.right,array);
  }
  return array;
  
};
```