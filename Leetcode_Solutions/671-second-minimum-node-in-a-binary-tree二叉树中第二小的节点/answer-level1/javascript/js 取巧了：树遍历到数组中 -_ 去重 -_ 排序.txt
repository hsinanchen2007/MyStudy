![image.png](https://pic.leetcode-cn.com/ed3cfa0b025aea9fc0e1de5ce4a3e89c26097897d7e4f173ac9f0bd70bc10a3c-image.png)

### 解题思路
```js
1.遍历树的所有非空节点放到数组中
2.使用 Set 结构去重
3.排序，返回答案
```

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

var findSecondMinimumValue = function(root) {
  let arr = [];
  
  function recursion(node) {
    if (node === null) return ;
    arr.push( node.val );
    recursion(node.left);
    recursion(node.right);
  }
  
  recursion(root);
  
  arr = [...new Set(arr)];
  
  arr.sort((a, b) => a - b);
  
  return arr.length < 2 ? -1 : arr[1];
};
```