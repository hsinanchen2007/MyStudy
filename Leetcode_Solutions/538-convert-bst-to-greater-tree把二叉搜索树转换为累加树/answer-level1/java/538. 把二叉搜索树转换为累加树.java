/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/23
 *
 * 解题思路: 使用BST 的特性 右子树的数值大于 根节点 大于 左子树 因此，进行进行中序遍历的过程中 先便利右子树 再遍历左子树，对结果进行累加赋值
 */
```
public class leetcode538 {

    int sum = 0; // 当前较大值的和
    public TreeNode convertBST(TreeNode root) {
        InOrder(root);
        return root;
    }

    public void InOrder(TreeNode root){

        if(root == null) return;

        InOrder(root.right);
        root.val = sum + root.val;
        sum = root.val;
        InOrder(root.left);

    }

    public static void main(String[] args) {

    }
}

```