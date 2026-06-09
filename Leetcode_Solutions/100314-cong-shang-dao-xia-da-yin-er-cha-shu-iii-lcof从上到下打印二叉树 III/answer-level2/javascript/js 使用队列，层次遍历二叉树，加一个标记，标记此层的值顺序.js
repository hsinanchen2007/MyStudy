![image.png](https://pic.leetcode-cn.com/02e6dc3e0349e1a1f2998dbe8f83cebfd652807b6dd17dee41ce18bd9cdf9caf-image.png)

### 解题思路
```js
  与 「从上到下打印二叉树 II」唯一的区别就是加一个变量，标记一下打印的顺序
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
 * @return {number[][]}
 */

var levelOrder = function(root) {
  let queue = [root], ans = [], flag = 'right';
  
  while (queue.length > 0) {
    let size = queue.length;
    let arr = [];
    
    while (size > 0) {
      size--;
      let offer = queue.shift();
      if (offer === null) continue;
      
      flag === 'right' ? arr.push( offer.val ) : arr.unshift( offer.val );
      
      if ( offer && offer.left ) queue.push( offer.left );
      if ( offer && offer.right ) queue.push( offer.right );
    }
    
    if (arr.length > 0) ans.push( arr );
    
    flag = flag === 'left' ? 'right' : 'left';
  }
  
  return ans;
};
```