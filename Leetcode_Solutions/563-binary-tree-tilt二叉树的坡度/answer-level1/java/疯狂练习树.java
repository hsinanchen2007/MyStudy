### 解题思路
此处撰写解题思路
为了保存每个左右子树之差的绝对值的和，需要的全局变量
首先是递归出口，如果节点为空则返回0
递归操作，按照逻辑习惯，应该是先求中间节点的左右节点差的绝对值，然后还要保存这些节点的值得和才能在根节点出算出来左右子节点的差的绝对值
返回条件，返回左右节点的值以及父节点值之和
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
    private int sum = 0;
    public int findTilt(TreeNode root) {
        find(root);
        return sum;
    }

    private int find(TreeNode root){
        if(root == null)
            return 0;
        int left = find(root.left);
        int right = find(root.right);
        sum += Math.abs(left-right);
        //为了返回节点的值
        return left + right + root.val;
    }
}
```