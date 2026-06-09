### 解题思路
有点坑爹是，这道题没明确说他的数字都是从1到n

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
    public int kthLargest(TreeNode root, int k) {
        if(root.right == null){
            return root.val - k+1;
        }
        else{
            return kthLargest(root.right,k);
        }
    }
}
```