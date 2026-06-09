### 解题思路

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
    int res = 0;
    int count = 0;
    public int kthLargest(TreeNode root, int k) {
        if(root == null || count >= k) return res;
        //进行后序遍历
        kthLargest(root.right,k);
        count ++;
        res = count==k?root.val:res;
        kthLargest(root.left,k);
        return res;
    }
}
```