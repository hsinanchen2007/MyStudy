## 第一版，递归，深度优先搜索，额外增加参数用来标记当前节点的层级
> 72ms,34.9M。
```javascript []
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
var levelOrder = function(root, floor = 0, arr = []) {
  if (!root) return arr;

  levelOrder(root.left, floor + 1, arr);

  if (arr[floor]) arr[floor].push(root.val);
  else arr[floor] = [root.val];

  levelOrder(root.right, floor + 1, arr);
  return arr;
};
```
#### 做 [98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/solution/mark-by-chitanda-eru-3) 时从《*学习JavaScript数据结构与算法（第3版）*》（想要学习数据结构与算法基础的JS程序GG或MM通过这本书上手非常合适！）学到的二叉树深度优先遍历操作方法简直太好用了，而且递归遍历代码简洁明了非常优雅，感觉应对这样较简单的题都可以直接无脑写代码了。中序、先序、后序用在这道题都没问题。
```javascript []
<!-- 中序遍历 -->
function traverseTree(root, cb) {
  if (root) {
    traverse(root.left);
    cb(root);
    traverse(root.right);
  }
}
```
```javascript []
<!-- 先序遍历 -->
function traverseTree(root, cb) {
  if (root) {
    cb(root);
    traverse(root.left);
    traverse(root.right);
  }
}
```
```javascript []
<!-- 后序遍历 -->
function traverseTree(root, cb) {
  if (root) {
    traverse(root.left);
    traverse(root.right);
    cb(root);
  }
}
```
## 第二版，迭代，广度优先搜索
> 80ms,34.9M。
```javascript []
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
var levelOrder = function(root, floor = 0, arr = []) {
  if(!root) return [];
  const result = [];
  const queue = [root];
  while(queue.length) {
    const level = queue.length; // 当前层的节点数
    const currLevel = []; // 当前层的节点值数组
    for(let i = 0; i < level; i++) { // 每次遍历当前一层节点，并将下一层节点入队
      const curr = queue.shift(); // 当前访问的节点出队
      curr.left && queue.push(curr.left); // 出队节点的子女入队
      curr.right && queue.push(curr.right); // 出队节点的子女入队
      currLevel.push(curr.val);
    }
    result.push(currLevel); // 向结果中添加当前层的节点值
  }
  return result;
};
```