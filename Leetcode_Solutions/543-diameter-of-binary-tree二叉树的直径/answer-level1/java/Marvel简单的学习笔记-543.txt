### DFS，0ms
首先要理解清楚题意。一棵二叉树的直径是任意两个结点之间路径长度的最大值，而路径长度是指结点之间边的数目，即顶点的数目减一。
要想得到路径长度的最大值，直觉判断显然要经过某棵（子）树的根结点，从这棵树的左叶子到根结点再到右叶子，问题在于这个根结点在哪。

可以通过求树的高度找到根结点，如果一棵树的左子树高度加右子树高度是所有树中的最大值，那么这棵树的根结点就是答案。

为了避免求子树高度时的冗余计算量，使用自底向上的递归，每当求出当前树的左右子树高度后，计算直径，再计算当前树的高度然后向上返回。

递归的过程结束后，二叉树的直径就得到了。

### 代码

```java
class Solution {
    private int diam;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null)    return 0;
        getHeight(root);
        return diam;
    }
    private int getHeight(TreeNode root) {
        if(root == null)    return 0;
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        int temp = leftHeight + rightHeight;
        diam = Math.max(diam, temp);
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
```