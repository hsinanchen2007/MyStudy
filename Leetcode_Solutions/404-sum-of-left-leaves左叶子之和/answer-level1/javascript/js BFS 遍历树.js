![image.png](https://pic.leetcode-cn.com/5b3aa4d7a70835c75338ed575866835c0d34857813211bf8b7009bea6e606a52-image.png)

### 解题思路
```js
BFS，层层遍历树，直到遇到节点为叶子节点，并且为左叶子节点，加起来即可
队列的每一项 [节点, 是否为左节点]
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

var sumOfLeftLeaves = function(root) {
  let sum = 0, queue = [];
  
  queue.push( [root, false] );
  
  while (queue.length > 0) {
    let size = queue.length;
    while (size > 0) {
      let offer = queue.shift();
      if (offer[1] === true && offer[0].left === null && offer[0].right === null) {
        sum += offer[0].val;
      }
      if (offer[0] && offer[0].left) queue.push([offer[0].left, true]);
      if (offer[0] && offer[0].right) queue.push([offer[0].right, false])
      size--;
    }
  }
  
  return sum;
};
```