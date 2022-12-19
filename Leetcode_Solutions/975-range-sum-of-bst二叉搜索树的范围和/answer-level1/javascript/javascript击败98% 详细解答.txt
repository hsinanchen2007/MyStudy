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
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {
  //  递归终止条件
  if(!root){
    return 0
  }
  if(root.val >= L && root.val <=R){
    return root.val + rangeSumBST(root.left, L, R) + rangeSumBST(root.right, L, R)
  }else if(root.val < L){
    return rangeSumBST(root.right, L, R)
  }else {
    return rangeSumBST(root.left, L, R)
  }
};
```
看清条件 二叉搜索树 特征：左孩子节点一定比父节点小， 右孩子节点一定比父节点大
二叉搜索树详细内容见维基百科
[维基百科 二叉搜索树](https://zh.wikipedia.org/wiki/%E4%BA%8C%E5%85%83%E6%90%9C%E5%B0%8B%E6%A8%B9)

主要用递归思想 先考虑终止条件 即left 或 right 为null

1.如果不为null，先判断该节点是否在 L 和 R 范围内
2.在则加入结果 并递归左孩子和右孩子
3.如果小于L 因为二叉搜索树的特征 符合的节点一定在右子树所以只需return 右子树的递归，大于 R 则 相反 
