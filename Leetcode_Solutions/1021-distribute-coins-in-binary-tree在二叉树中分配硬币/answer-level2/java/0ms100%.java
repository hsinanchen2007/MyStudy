### 解题思路
每个根节点需要把两个叶子节点需要几个往上依次累加，如左节点为0，则返回-1，为1则返回0，为2则返回1，因为不管怎样，如果叶子几点要提供给别的节点或者从别的地方取，都要经过根节点，所以累加就可以

# 代码

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
    private int num;
    public int distributeCoins(TreeNode root) {
        num=0;
        helper(root);
        return num;
    }
    private int helper(TreeNode node){
        if (node==null)
            return 0;
        int rest=node.val;
        node.val=1;
        rest+=helper(node.left)+helper(node.right);
        num+=Math.abs(rest-1);
        return rest-1;
    }
}
```