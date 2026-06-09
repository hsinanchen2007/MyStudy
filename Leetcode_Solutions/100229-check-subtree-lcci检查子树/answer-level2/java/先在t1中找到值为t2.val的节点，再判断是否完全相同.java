# 很相似的题目
[面试题26. 树的子结构](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/solution/guan-fang-ce-shi-yong-li-you-dian-wen-ti-by-gfu/)

# 代码
```java
class Solution {
    private TreeNode global_B;
    private int target;

    public boolean checkSubTree(TreeNode A, TreeNode B) {
        if (A == null || B == null) return false;
        //target设为B节点的的val
        target = B.val;
        global_B = B;
        return helper(A);
    }

    //寻找值为target的节点, 若找到，isEqual()判断是否完全相同
    private boolean helper(TreeNode root) {
        if (root != null) {
            if (root.val == target)
                if (isEqual(root, global_B))
                    return true;

            return helper(root.left) || helper(root.right);
        }
        return false;
    }

    //判断以b为根节点的树 是否与 以a为根节点的树 完全相同
    private boolean isEqual(TreeNode a, TreeNode b) {
        if (a == null && b == null) return true;
        if (a == null) return false;
        if (b == null) return false;
        //比较a和b的val
        //递归判断 以b.left为根节点的树 是否与 以a.left为根节点的树 完全相同
        //递归判断 以b.right为根节点的树 是否与 以a.right为根节点的树 完全相同
        return b.val == a.val && isEqual(a.left, b.left) && isEqual(a.right, b.right);
    }
}
```
