
![检查两个树.png](https://pic.leetcode-cn.com/1a4739282fedff03895e7749098c5e1f78be029c8a108cb10c52c714b60a0c12-%E6%A3%80%E6%9F%A5%E4%B8%A4%E4%B8%AA%E6%A0%91.png)

一直对树有一种恐惧，没想到还能做出来 ^。^

和官方题解差不多,第二三个if条件可以合并，递归条件就是当前两个树的节点值一样就去比较左子树和右子树。

```java []
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {

        if (p == null && q == null) {
            return true;
        }

        if (p == null && q != null) {
            return false;
        }

        if (p != null && q == null) {
            return false;
        }
     
        if (p.val == q.val) {
            return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
        }
        return false;
    }
}
```
