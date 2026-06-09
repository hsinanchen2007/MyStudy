### 解题思路
根，左，右遍历

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
    int result = 0;
    public int sumNumbers(TreeNode root) {
        travel(root, 0);
        return result;
    }

    void travel(TreeNode root, int sum) {
        if (root == null) {
            return;
        }
        sum = sum * 10 + root.val;
        // leaf
        if (root.left == null && root.right == null) {
            result += sum;
        }
        travel(root.left,  sum);
        travel(root.right, sum);    
    }  
}
```