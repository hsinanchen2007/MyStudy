### 解题思路
//第一种情况：左子树一个，右字数一个
//第二种情况：都在左子树
//第三种情况：都在右子树
//第四种情况：有一个值等于root的值

### 结果
执行用时 :88 ms, 在所有 JavaScript 提交中击败了83.92%的用户
内存消耗 :43.7 MB, 在所有 JavaScript 提交中击败了42.79%的用户

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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
  var val = root.val
  var pVal = p.val
  var qVal = q.val
  if (pVal > qVal) {
    var tmp = qVal
    qVal = pVal
    pVal = tmp
  }

  //第一种情况：左子树一个，右字数一个
  if (pVal < val && qVal > val) {
    return root
  }
  //第二种情况：都在左子树
  if (pVal < val && qVal < val) {
    return lowestCommonAncestor(root.left, p, q)
  }

  //第三种情况：都在右子树
  if (pVal > val && qVal > val) {
    return lowestCommonAncestor(root.right, p, q)
  }
  //第四种情况：有一个值等于root的值
  if (pVal === val || qVal === val) {
    return root
  }

};
```