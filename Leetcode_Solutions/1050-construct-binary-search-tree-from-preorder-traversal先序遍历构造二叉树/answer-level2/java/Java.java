**我的[leetcode解题集](https://github.com/JuiceZhou/Leetcode)，求小星星呀(๑•̀ㅂ•́)و✧**

构建树的关键就是找到每次递归的根节点和左右子节点的关系，因为是要构建BST，根据BST**所有左子树值<根节点<所有右子树值**的性质：

 * 根节点：每个数组的首元素
 * 左子树：小于根节点的所有元素
 * 右子树：大于根节点的所有元素


```
public TreeNode bstFromPreorder(int[] preorder) {
    if (preorder.length == 0) return null;
    return helper(preorder, 0, preorder.length - 1);
}

private TreeNode helper(int[] preorder, int lo, int hi) {
    if (lo > hi) return null;
    //获取根节点
    if (lo == hi) return new TreeNode(preorder[lo]);
    TreeNode root = new TreeNode(preorder[lo]);
    //找到大于根节点的第一个值索引
    int index = hi + 1;
    for (int i = lo + 1; i <= hi; i++) {
        if (preorder[lo] < preorder[i]) {
            index = i;
            break;
        }
    }
    root.left = helper(preorder, lo + 1, index - 1);
    root.right = helper(preorder, index, hi);
    return root;
}

```