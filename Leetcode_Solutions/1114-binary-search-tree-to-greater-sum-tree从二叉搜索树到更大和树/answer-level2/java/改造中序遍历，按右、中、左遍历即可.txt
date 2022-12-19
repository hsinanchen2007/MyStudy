首先，大家都知道，对于二叉搜索树的中序遍历是一个递增有序的序列。
题目要求每个结点的值更新为原树中大于等于原值的和。对于二叉搜索树，大于当前值的结点就是在当前结点右边的点。所以只需要从右往左遍历，同时用一个变量累计走过的结点值的和。
比如题目示例中的二叉搜索，中序遍历是0,1,2,3,4,5,6,7,8。
那么从右往左看：
1. 0,1,2,3,4,5,6,7,8  count = 8
2. 0,1,2,3,4,5,6,15,8  count = 15(8 + 7)
3. 0,1,2,3,4,5,21,15,8  count = 21(8 + 7 + 6)
4. ...

代码如下

```java
class Solution {
    private int count = 0;
    public TreeNode bstToGst(TreeNode root) {
        if (root == null)
            return null;
        bstToGst(root.right);
        count += root.val;
        root.val = count;
        bstToGst(root.left);
        return root;
    }
}
```
