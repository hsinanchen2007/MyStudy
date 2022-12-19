### 解题思路
执行结果：
通过
显示详情
执行用时 :1 ms, 在所有 Java 提交中击败了86.69%的用户
内存消耗 :
39.1 MB, 在所有 Java 提交中击败了12.51%的用户

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
   public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public boolean validate(TreeNode node, long min, long max) {
        if (node == null) {
            return true;
        }
        if (node.val <= min) return false;
        if (node.val >= max) {
            return false;
        }
        if(!validate(node.left, min, node.val)) return false;
        if(!validate(node.right, node.val, max)) return false;
        return  true; 
    }

    
}
```