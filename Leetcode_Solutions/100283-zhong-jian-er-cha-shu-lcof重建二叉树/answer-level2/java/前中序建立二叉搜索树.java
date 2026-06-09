### 解题思路
此处撰写解题思路
前序遍历是中左右，中序遍历是左中右，前中后的顺序主要是看“中”遍历的顺序；前序遍历第一个节点即为根节点，然后在中序遍历找到这个节点，则此节点将中序分为了左右两个子树，此过程可以递归。为了记录下此时节点的值因此，需要额外的函数进行递归操作。
递归出口： 遍历前序数组的pre参数如果等于数组长度，则应该返回null，还需要一个参数记录在中序数组中的位置
递归操作： 创建根节点，pre++，指向左子树，TreeNode root = new TreeNode(preorder[pre++]);root.left = build(preorder,inorder,root.val);此时需要指向右子树，需要一个操作退出左子树，因此判断如果此时的值和中序数组第一个元素相等，则中序计数+1，然后回退，从左节点回退到根节点如果还是相同则中序计数+1，回退，此时就直接进入右子树的建立root.right = build(preorder,inorder,stop);
if (inorder[in] == stop) {
        in++;
        return null;
}

如果左子树很深，则会一直创建根节点的左子树，直到叶节点然后就会开始逐步从中序数组中判断，回退创建右节点



### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0 || inorder.length == 0 || preorder.length != inorder.length) 
            return null;
        return build(preorder,inorder, Integer.MAX_VALUE);
    }

    int pre = 0, in = 0; 
    private TreeNode build(int[] preorder, int[] inorder, int stop) {
        if (pre == preorder.length) 
            return null;
        if (inorder[in] == stop) {
            in++;
            return null;
        }
        TreeNode root = new TreeNode(preorder[pre++]);
        root.left = build(preorder,inorder,root.val);
        root.right = build(preorder,inorder,stop);
        return root;
    }
}
```