### 解题思路
1搜索二叉树的中序遍历为从小到大可以得到第k个最小数，而中序遍历的顺序为：左、根、右。
2那么反其道而行之，如果先遍历右、根、左则可以从大到小的遍历结果，通过这个结果可以得到
第k个最大值。

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
    private int count;
    private int res;
    public int kthLargest(TreeNode root, int k) {
       count=k;
       helper(root);
       return res;
}
    public  void  helper(TreeNode root){
    if(root==null||count==0) return;
    helper(root.right);
    count--;
    if(count==0){
        res=root.val;
    }
    helper(root.left);
}
}
```