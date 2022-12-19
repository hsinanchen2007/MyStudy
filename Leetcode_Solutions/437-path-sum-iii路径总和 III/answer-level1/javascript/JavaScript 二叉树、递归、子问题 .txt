### 解题思路
递归遍历，找出每个节点到叶子节点的过程中，找到的满足条件的路径，相加即可。

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
 * @param {number} sum
 * @return {number}
 */
var pathSum = function(root, sum) {
    if(root == null) return 0;
    let res = 0
    res = res + findPath(root, sum)
    res = res + pathSum(root.left,sum)
    res = res + pathSum(root.right, sum)
    return res;
};


function findPath(node, sum) {
    if(node == null) return 0;
    let res = 0
    if(sum- node.val == 0) res ++;
    res = res + findPath(node.left,sum-node.val)
    res = res + findPath(node.right,sum -node.val)
    return res
}

```