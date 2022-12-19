![image.png](https://pic.leetcode-cn.com/14f4930017d12306ea6450c468a0dc76bf198c33bdccf2096c313232b47741ad-image.png)

### 解题思路
```js
  1. 遍历A，一旦遇到与 B 根节点相等的节点，那么递归去比较这个节点是否完全包含 B 
  2. 需要一个判断一棵树是否包含另一颗树的方法 isInclude: function
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
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */

var isSubStructure = function(A, B) {
  if (B === null) return false;
  
  // m 是否包含 n
  function isInclude(m, n) {
    if (m === null && n === null) return true;
    if (m === null) return false;
    if (n === null) return true;
    
    if (m.val === n.val) {
      return isInclude(m.left, n.left) && isInclude(m.right, n.right);
    } else {
      return false;
    }
  }
  
  // 遍历树
  function bst(node) {
    if (ans === true || node === null) return ;
    
    if (node.val === B.val) {
      if (isInclude(node, B)) {
        return ans = true;
      }
    }
    bst(node.left);
    bst(node.right);
  }
  
  let ans = false;
  
  bst(A);
  
  return ans;
};
```