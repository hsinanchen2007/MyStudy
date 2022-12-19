## 队列 BFS

```js
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
  if (!root) return 0;
  let level = 0;
  let queen = [root];

  while(queen.length) {
    let currentQueenLength = queen.length;
    while(currentQueenLength --) {
      let node = queen.shift();
      node.left && queen.push(node.left);
      node.right && queen.push(node.right);
    }
    level++;
  }

  return level;
};
```


## 递归

```js
var maxDepthRecursive = function (root) {
  return root ? Math.max(maxDepthRecursive(root.left), maxDepthRecursive(root.right)) + 1 : 0;
}

```


