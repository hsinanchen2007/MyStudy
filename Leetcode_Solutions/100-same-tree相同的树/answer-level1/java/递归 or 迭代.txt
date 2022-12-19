### 解题思路
有了前面一些树算法的基础，就很容易定位这道题的解法了。 递归是比较快和容易实现的方式，注意提前快速返回，最后递归调用左右子树的判断即可。
执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :33.9 MB, 在所有 java 提交中击败了87.51%的用户

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p==null && q==null) return true;
        if(p==null || q==null) return false;
        if(p.val != q.val) return false;
        return isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
    }
}
```