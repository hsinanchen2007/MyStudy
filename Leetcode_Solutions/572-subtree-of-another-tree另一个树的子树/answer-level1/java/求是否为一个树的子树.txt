### 解题思路1.s是否与t相等。
            2.s的左子树是否与t相等。
            3.s的右子树是否与t相等。
在比较的前提下一定要判断s是否为空，如果为空则为false,然后进行下一个路径判断。

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }(
 */
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        
        return s!=null&&(isEqual(s,t)||isSubtree(s.left,t)||isSubtree(s.right,t));
    }
    public boolean isEqual(TreeNode s,TreeNode t){
        if(s==null&&t==null) return true;
        if(s==null||t==null) return false;
      
        return s.val==t.val&&isEqual(s.left,t.left)&&isEqual(s.right,t.right);
        
    }
}
```