### 解题思路
中序遍历，并保存序列

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
        
    String s1 = trace(p);
        String s2 = trace(q);
        return s1.equals(s2);
    }

    public static String trace(TreeNode root){
        if(root == null)
            return "#";
        StringBuilder sb = new StringBuilder();
        sb.append(root.val);
        sb.append(trace(root.left));
        sb.append(trace(root.right));
        return sb.toString();
    }
}
```