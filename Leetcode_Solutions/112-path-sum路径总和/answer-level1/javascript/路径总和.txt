1、DFS递归
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
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function(root, sum) {
    if(root === null) return false;
    sum-=root.val;
    if(root.left === null && root.right === null) {
        return sum === 0;
    }
    return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
};
```
时间复杂度：我们访问每个节点一次，时间复杂度为O(N) ，其中 N 是节点个数。
空间复杂度：最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 N 次（树的高度），因此栈的空间开销是O(N) 。但在最好情况下，树是完全平衡的，高度只有log(N)，因此在这种情况下空间复杂度只有O(log(N))。

2、BFS、需要用另一个队列来保存每条路径的结果

```javascript
var hasPathSum = function(root, sum) {
    if(root === null) return false;
    let q1 = [];
    let q2 = [];
    q1.push(root);
    q2.push(root.val);
    while(q1.length) {
        let node = q1.shift();
        let temp = q2.shift();
        if(node.left === null && node.right === null && temp === sum) return true;
        if(node.left) {
            q1.push(node.left);
            q2.push(temp+node.left.val);
        }
        if(node.right) {
            q1.push(node.right);
            q2.push(temp+node.right.val);
        }
    }
    return false;
};
```
时间复杂度：和递归方法相同是O(N)。
空间复杂度：当树不平衡的最坏情况下是O(N) 。在最好情况（树是平衡的）下是O(logN)。