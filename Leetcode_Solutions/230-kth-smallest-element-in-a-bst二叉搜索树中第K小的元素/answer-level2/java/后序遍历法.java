
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
    int count = 0;
    public int kthSmallest(TreeNode root, int k) {
        if(root == null || count >= k) return result;
        kthSmallest(root.left,k);
        count ++;
        result = (count == k)?root.val:result;
        kthSmallest(root.right,k);
        return result;
    }
}
```