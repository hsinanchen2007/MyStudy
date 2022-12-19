### 解题思路
1、深度优先遍历，减去沿途遇到的结点值
2、如果达到叶子结点时，sum刚好等于0，则这条路径就是答案，返回真

tips:深度优先遍历的结果判断在递归到叶子结点时执行
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
        if(root == null){
            return false;
        }
        //将遇到的节点值减去
        sum -= root.val;
        //遍历到叶子节点时 如果sum被减为0 说明为真
        if(root.left == null && root.right == null){
            return sum == 0;
        }
        return hasPathSum(root.left,sum)||hasPathSum(root.right,sum);
    }
}
```