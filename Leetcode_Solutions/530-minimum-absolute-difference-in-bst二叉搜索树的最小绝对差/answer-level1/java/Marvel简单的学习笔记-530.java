### 解题思路
利用**二叉树的中序遍历为升序**的特性，将问题转化为在升序排列的数中**寻找相邻两数的差的最小值**。
用一个变量记录上一个数，每次只要计算当前数和上一个数的差，然后和最小值比较，并在比较后更新上一个数即可。
中序遍历结束后便可得到二叉树的最小绝对差。

### 代码

```java
class Solution {
    private int pre;
    private int minDif;
    public int getMinimumDifference(TreeNode root) {
        pre = -1;
        minDif = Integer.MAX_VALUE;
        inOrder(root);
        return minDif;
    }
    private void inOrder(TreeNode root) {
        if(root == null)    return;
        inOrder(root.left);
        if(pre != -1)
            minDif = Math.min(minDif, root.val - pre);
        pre = root.val;
        inOrder(root.right);
    }
}
```