### 自底向上递归
首先要理解题意，需要求所有结点的坡度之和，而一个结点的坡度等于它的左子树所有节点之和与它的右子树所有节点之和的差的绝对值。
因此，如果求根结点的坡度，我们需要先得到根结点的左右子树所有节点之和；同理，求子结点的坡度时，也要先得到子结点的左右子树所有节点之和。像这样自顶向下，会使求子树所有节点之和时产生很多冗余计算，因为底部的树的结点之和会被多次计算。
所以考虑自底向上的递归。

为了不让子树结点之和被重复计算，我们应该向上返回当前树的所有节点之和。
也就是当一个结点得到了子结点向上返回的结点之和时，立即计算该节点的坡度，可存储在一个实例变量中，然后同样也向上返回当前结点作为根结点的树的所有节点之和。
如此这般在自底向上的过程中，不断返回子树的所有节点之和，然后计算并累加当前结点的坡度，再向上返回当前树的结点之和。直到根结点的坡度得到计算后，递归遍历结束，所有节点的坡度之和就出来了。

### 代码

```java
class Solution {
    private int tilt;
    public int findTilt(TreeNode root) {
        getSum(root);
        return tilt;
    }
    private int getSum(TreeNode root) {
        if(root == null)    return 0;
        int leftSum = getSum(root.left);
        int rightSum = getSum(root.right);
        tilt += Math.abs(leftSum - rightSum);
        return leftSum + rightSum + root.val;
    }
}
```