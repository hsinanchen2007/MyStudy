### 解题思路
分为3中情况：
1 t树本身就是s树
2 t树在s树的左子树上，也即t树和s树左子树上的树相等
3 t树在s树的右子树上，也即t树和s树右子树上的树相等
然后直接进行相应节点的比较，比较相应节点是否相等。

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
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s==null&&t==null) return true;
        if(s==null||t==null) return false;
        if(isEqual(s,t)){
            return true;
        }
        return isSubtree(s.left,t)||isSubtree(s.right,t);
    }
    public boolean isEqual(TreeNode s,TreeNode t){
        if(t==null&&s==null) return true;
        if(t==null||s==null) return false;
        if(s.val==t.val){
            return isEqual(s.left,t.left)&&isEqual(s.right,t.right);
        }
        return false;
    }
}
```