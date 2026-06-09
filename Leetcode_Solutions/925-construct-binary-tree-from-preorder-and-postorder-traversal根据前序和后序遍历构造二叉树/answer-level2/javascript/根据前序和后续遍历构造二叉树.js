### 解题思路
跟热门评论一致的思路

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
 * @param {number[]} pre
 * @param {number[]} post
 * @return {TreeNode}
 */
function TreeNode (val) {
  this.val = val
  this.left = null
  this.right = null
}
var constructFromPrePost = function(pre, post) {
      const node = new TreeNode(pre[0])
  let task = []
  pre.shift()
  post.pop()
  if (pre.length === 0) {
    return node
  }
  const a = pre[0]
  const index = post.findIndex(i => i === a)
  const length = index + 1
  task.push([pre.slice(0, length), post.slice(0, length), node, 'left'])
  task.push([pre.slice(length), post.slice(length), node, 'right'])
  while (task.length > 0) {
    const newTask = []
    for (let i = 0; i < task.length; i++) {
      let pre = task[i][0]
      let post = task[i][1]
      let parentNode = task[i][2]
      let treeDirection = task[i][3]
      if (pre.length === 0) {
        continue
      }
      let val = pre.shift()
      post.pop()
      let node = new TreeNode(val)
      parentNode[treeDirection] = node
      const a = pre[0]
      if (pre.length > 1) {
        const index = post.findIndex(i => i === a)
        const length = index + 1
        newTask.push([pre.slice(0, length), post.slice(0, length), node, 'left'])
        newTask.push([pre.slice(length), post.slice(length), node, 'right'])
      } else if (pre.length === 1) {
        newTask.push([pre, post, node, 'left'])
      }
    }
    task = newTask
  }
  return node
};
```