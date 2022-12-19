# 思路
先在A中找到值为B.val的节点(记为B_node)，再判断以B为根节点的树 是否是 以B_node为根节点的树 的子树。

# 代码
```java
class Solution {
    private TreeNode global_B;
    private int target;

    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if (A == null || B == null) return false;
        //target设为B节点的的val
        target = B.val;
        global_B = B;
        return helper(A);
    }

    //寻找值为target的节点, 若找到，调用isSub()
    private boolean helper(TreeNode root) {
        if (root != null) {
            if (root.val == target)
                if (isSub(root, global_B))
                    return true;

            return helper(root.left) || helper(root.right);
        }
        return false;
    }

    //判断以b为根节点的树 是否是 以a为根节点的树 的子树
    //满足子树的条件为：
    //1. 若a和b都不为空，则a和b的val必须相等；
    //2. 若a为空，b也 必须 为空；
    //3. 若a不为空，b 可以 为空，也可以不为空(当b不为空时，即等价于条件1.)
    private boolean isSub(TreeNode a, TreeNode b) {
        //若当前的a 和 b都不为null
        if (b != null && a != null) {
            //比较a和b的val，若不相等，直接返回false
            if (b.val != a.val)
                return false;
            //递归判断 以b.left为根节点的树 是否是 以a.left为根节点的树 的子树
            //递归判断 以b.right为根节点的树 是否是 以a.right为根节点的树 的子树
            return isSub(a.left, b.left) && isSub(a.right, b.right);
        }
        /*等价于
        //若b不为空，而a为空，则说明不满足 子树 条件
        if(b != null && a == null)
            return false;
        return true;
         */
        return b == null || a != null;
    }
}
```
