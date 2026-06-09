### 解题思路


### 递归

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
    if (!root || root.length < 1) return [];
    let ans = [];
    helper (ans, root, 0);
    return ans;
};
function helper (ans, root, layer) {
    if (!root) return ;
    if (!ans[layer]) ans[layer] = [];
    ans[layer].push(root.val);
    helper(ans, root.left, layer + 1);
    helper(ans, root.right, layer + 1);
}
```

### 迭代

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
  if (!root || root.length < 1) return [];
  let ans = [];
  bfs(ans, root)
  return ans;
};

function bfs (ans, root) {
  let queue = [[root, 0]];
  while (queue.length) {
      let [current, layer] = queue.shift();
      ans[layer] ? ans[layer].push(current.val) : ans[layer] = [current.val];
      if (current.left) queue.push([current.left, layer + 1]);
      if (current.right) queue.push([current.right, layer + 1]);
  }
}
```