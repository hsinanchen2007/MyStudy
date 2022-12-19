```js
interface TreeNode {
  val: any;
  left: TreeNode | null;
  right: TreeNode | null;
}
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p: TreeNode, q: TreeNode): boolean {
  function rescure(t1: TreeNode | null, t2: TreeNode | null): boolean {
    if (t1 === null && t2 === null) {
      return true;
    }
    if (t1 === null || t2 === null) {
      return false;
    }
    if (t1.val !== t2.val) {
      return false;
    }
    return rescure(t1.left, t2.left) && rescure(t1.right, t2.right);
  }
  return rescure(p, q);
};

```