### 解题思路
此处撰写解题思路
因为需要每一层的深度，题目所给为boolean函数，不能在递归时返回树的深度进行计算，因此，需要额外的函数
一： 递归出口，当节点为空，表示遍历到叶节点的子节点因此标记为0
二：递归操作，先着找到左右叶子节点，从下往上递归
三：如果相差大于1，则不是平衡树，因此返回标记值-1
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
    public boolean isBalanced(TreeNode root) {
        return find(root) != -1;
    }

    public int find(TreeNode root){
        if(root == null)
            return 0;
        int left = find(root.left);
        int right = find(root.right);
        if(left >= 0 && right >= 0 && Math.abs(left-right) <= 1){
            return Math.max(left,right) + 1;
        }
        return -1;
    }
}
```