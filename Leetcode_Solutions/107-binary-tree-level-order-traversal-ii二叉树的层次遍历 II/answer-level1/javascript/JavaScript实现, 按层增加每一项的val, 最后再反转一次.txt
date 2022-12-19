```
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
var levelOrderBottom = function(root) {
    
  function helper(list, index, node) {
    if (!node) return list;
    const res = list[index] || [];
    res.push(node.val);
    list[index] = res;

    helper(list, index + 1, node.left);
    helper(list, index + 1, node.right);
  }

  const result = [];

  helper(result, 0, root);

  return result.reverse();
};

```