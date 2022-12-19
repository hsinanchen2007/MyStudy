![image.png](https://pic.leetcode-cn.com/16e1f39ae59b91a12a62e1fcf1b138b8c8b50051c023340959bfe81ddd0e7c8e-image.png)

### 解题思路
```js
  利用队列层次遍历二叉树，遇见的第一个变成面试题之后，难度从简单变中等了
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
 * @return {number[]}
 */

var levelOrder = function(root) {
  let queue = [root], ans = [];
  
  while (queue.length > 0) {
    let size = queue.length;
    
    while (size > 0) {
      size--;
      let offer = queue.shift();
      if (offer === null) continue;
      
      ans.push( offer.val );
      if ( offer && offer.left ) queue.push( offer.left );
      if ( offer && offer.right ) queue.push( offer.right );
    }
  }
  
  return ans;
};
```