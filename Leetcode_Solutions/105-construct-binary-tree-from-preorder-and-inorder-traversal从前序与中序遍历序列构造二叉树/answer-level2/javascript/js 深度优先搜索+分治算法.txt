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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(
  preorder: number[],
  inorder: number[]
): TreeNode | null {
  if (preorder.length === 0) {
    return null;
  }
  function recursive(
    pStart: number, // 子树在preorder的开始位
    iStart: number, // 子树在inorder的开始位
    iEnd: number // 子树在inorder的结束位
  ): TreeNode {
    const root: TreeNode = {
      val: preorder[pStart],
      left: null,
      right: null
    };
    const inRootIndex = inorder.indexOf(preorder[pStart], iStart);
    if (iStart < inRootIndex) { // 说明有左子树
      root.left = recursive(pStart + 1, iStart, inRootIndex - 1);
    }
    if (iEnd > inRootIndex) { // 说明有右子树
      const newPStart = pStart + (inRootIndex - iStart + 1);
      root.right = recursive(newPStart, inRootIndex + 1, iEnd);
    }
    return root;
  }
  return recursive(0, 0, inorder.length - 1);
};
```