![image.png](https://pic.leetcode-cn.com/a0bddf8d7405221a77f3c373259521e6873570fd447a8c4668a21656f8f5b7f0-image.png)

### 解题思路
```js
笨方法：中序遍历二叉树，放到数组中，进行双指针查找目标值
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
 * @param {number} k
 * @return {boolean}
 */

var findTarget = function(root, k) {
  let arr = [], ans = false;
  
  function bst(node) {
    if (node === null) return ;
    
    bst(node.left);
    arr.push( node.val );
    bst(node.right);
  }
  
  bst(root);
  
  let left = 0, right = arr.length - 1;
  while (left < right) {
    let sum = arr[left] + arr[right];
    if (sum === k) {
      ans = true;
      break;
    } else if (sum > k) {
      right--;
    } else {
      left++;
    }
  }
  
  return ans;
};
```