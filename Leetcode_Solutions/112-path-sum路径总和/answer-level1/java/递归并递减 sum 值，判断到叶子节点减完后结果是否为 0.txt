### 解题思路

将 sum 按照经过的节点减去对应节点的值直到叶子节点，如果在叶子节点将 sum 减完后结果不是 0，则返回 false。结果为 0 则返回 true。
如果节点只有一个子节点，则另一个子节点路径直接置为 false。避免将中间节点作为子节点来判断

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
        if(root == null) {
            return false;
        }

        return subPathSum(root,sum);
    }

    public boolean subPathSum(TreeNode node,int sum){
        if(node == null){
            return false;
        }
    
        int value = node.val;
        sum -= value;
        
        //判断当前为叶子节点
        if(node.left == null && node.right == null) {
            return sum == 0;
        }
        
        return subPathSum(node.left, sum) || subPathSum(node.right,sum);
    }
}
```