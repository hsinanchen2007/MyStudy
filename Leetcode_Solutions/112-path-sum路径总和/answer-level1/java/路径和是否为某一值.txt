### 解题思路  要思考返回值是什么，是遍历到叶节点时，总和sum是否减小到零了。


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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root==null) return false;
        sum-=root.val;
        if(root.left==null&&root.right==null)
            return sum==0;
        return hasPathSum(root.left,sum)||hasPathSum(root.right,sum);

    }
}
```