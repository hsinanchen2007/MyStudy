### 解题思路
把结果合并到了t1
+ 如果当前位置两个树的结点都为null则返回null
+ 如何当前结点处t1 t2其中一个为null则把不为null的结点给t1
+ 如果当前结点处t1 t2都不为null则相加两结点的值个t1
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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        return merge(t1, t2);
    }
    private TreeNode merge(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) {
            return null;
        }
        if (t1 == null) {
            t1 = t2;
            t1.left = merge(null, t2.left);
            t1.right = merge(null, t2.right);
        } else if (t2 == null) {
            t1.left = merge(t1.left, null);
            t1.right = merge(t1.right, null);    
        } else {
            t1.val += t2.val;
            t1.left = merge(t1.left, t2.left);
            t1.right = merge(t1.right, t2.right);
        }

        return t1;
        
    }
}
```