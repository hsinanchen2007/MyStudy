![image.png](https://pic.leetcode-cn.com/30aac563bf1bb98876f806155405c8c7a907b514cf116279be7426a0c6696f23-image.png)

### 解题思路
```js
  BFS 层层遍历，每隔一层，返回的层结果逆序就可以了
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

var zigzagLevelOrder = function(root) {
  if (!root) return [];
  let ans = [], queue = [root], positive = true;
  
  while (queue.length > 0) {
    let size = queue.length, temp = [];
    while (size > 0) {
      size--;
      let offer = queue.shift();
      
      if (positive) {
        temp.push( offer.val );
      } else {
        temp.unshift( offer.val );
      }
      if (offer && offer.left) queue.push( offer.left );
      if (offer && offer.right) queue.push( offer.right );
    }
    
    ans.push( [...temp] );
    positive = positive ? false : true;
  }
  
  return ans;
};
```