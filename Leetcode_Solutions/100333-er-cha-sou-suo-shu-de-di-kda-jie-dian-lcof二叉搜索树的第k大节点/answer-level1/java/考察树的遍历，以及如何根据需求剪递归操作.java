### 解题思路
此处撰写解题思路

### 代码

```java
//全部排序，看位置k(这里没有全排序必要，因为已经排好序，取数就好)
//一边遍历，一边看到了k没有(二叉搜索树排好序了，每个节点放进来，先计算自己的右节点，再计算自己，再计算自己的左节点)
class Solution {
    private int output = 0, cnt = 0;
    public int kthLargest(TreeNode root, int k) {
        r_m_l(root, k);
        return output;
    }
    private void r_m_l(TreeNode root, int k) {
        if(root == null||output != 0) return;
        //这步骤还可以在K时就结束递归，直接剪掉不需要的操作
        r_m_l(root.right, k);
        if(++cnt == k) {
            output = root.val;
        }
        r_m_l(root.left, k);
    }
}
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

这道题目很好，考察对树的遍历，以及如何根据需求剪递归操作。
```