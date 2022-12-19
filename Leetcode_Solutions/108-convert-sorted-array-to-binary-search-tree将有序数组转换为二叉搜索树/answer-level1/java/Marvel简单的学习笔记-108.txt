### 解题思路
以原数组的中间元素作为二叉树的根结点。接下来处理左右子树。
运用分治的思想，递归地将数组分成左半边和右半边，左半边的中间元素作为左子树的根结点，右半边的中间元素作为右子树的根结点。
如此这般，直至左右子数组为空，返回null，即左右子树为null。
处理完左右子树的结点将自身返回。

时间复杂度：$O(n)$。
空间复杂度：$O(n)$。递归需要的栈空间为$O(logn)$。

### 代码

```java
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        TreeNode root = null;
        return divide(nums, 0, nums.length-1);
    }
    private TreeNode divide(int[] n, int lo, int hi) {
        if(hi < lo) return null;
        int mid = lo + (hi - lo) / 2;
        TreeNode root = new TreeNode(n[mid]);
        root.left = divide(n, lo, mid-1);
        root.right = divide(n, mid+1, hi);
        return root;
    }
}
```