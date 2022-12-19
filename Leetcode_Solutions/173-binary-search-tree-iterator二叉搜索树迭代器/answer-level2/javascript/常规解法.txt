### 解题思路
- 先遍历
- 在排序

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
 */


var BSTIterator = function(root) {
  this.root = root;
  this.result = this.init();
};

BSTIterator.prototype.init = function() {
  let res = [];

  if (!this.root) {
    return res;
  }

  let stack = [this.root];

  while(stack.length !== 0){
    let node = stack.pop();
    res.push(node.val);

    if(node.right){
      stack.push(node.right);
    }
    if(node.left){
      stack.push(node.left);
    }
  }

  res = res.sort((x, y) => x - y);

  return res;
};

/**
 * @return Array next smallest number
 * @return {number}
 */
BSTIterator.prototype.next = function() {
  if (this.result) {
    return this.result.shift();
  }
};

/**
 * @return whether we have a next smallest number
 * @return {boolean}
 */
BSTIterator.prototype.hasNext = function() {
  if (this.result.length) {
    return true;
  } else {
    return false;
  }
};
```