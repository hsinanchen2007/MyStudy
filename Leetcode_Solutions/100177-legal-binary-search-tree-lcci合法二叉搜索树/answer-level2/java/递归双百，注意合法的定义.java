![合法二叉搜索树.png](https://pic.leetcode-cn.com/fda166ab34bce9de13099dd9878a5044e2355acda017f4cb8855350b71d810a4-%E5%90%88%E6%B3%95%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.png)

### 解题思路
每个节点还是要访问多次。一开始想返回数组表示各个字数的最大值最小值范围，用的`Integer.MAX_VALUE`和`Integer.MIN_VALUE`表示无穷，结果遇到测试样例中的整型边界测试就放弃了。
提示1说：如果允许重复元素，它们必须位于特定的一边（通常是左边）。但实际测试时不允许重复。

### 代码

```java
class Solution {
    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        TreeNode maxLeft = root.left, minRight = root.right;
        // 找寻左子树中的最右（数值最大）节点
        while (maxLeft != null && maxLeft.right != null)
            maxLeft = maxLeft.right;
        // 找寻右子树中的最左（数值最小）节点
        while (minRight != null && minRight.left != null)
            minRight = minRight.left;
        // 当前层是否合法
        boolean ret = (maxLeft == null || maxLeft.val < root.val) && (minRight == null || root.val < minRight.val);
        // 进入左子树和右子树并判断是否合法
        return  ret && isValidBST(root.left) && isValidBST(root.right);
    }
}
```