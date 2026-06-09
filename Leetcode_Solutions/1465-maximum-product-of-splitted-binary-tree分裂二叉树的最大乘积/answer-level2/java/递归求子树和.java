### 解题思路
此处撰写解题思路
本题相当于：S = X + Y，S为确定值，在多组(Xn,Yn), 中找到一组（x，y），使得x*y 最大；
而x和y最接近时，x*y 最大，那么目标就是找到最接近的那一对(x、y);
如果 x和y 最接近，那么x或者y，一定也是离 S/2 最近的；
所以就要找到一个子树和，和 S/2 差值最小。

第一步：先计算树的总和，从而得出 S/2;
第二步：计算各节点的子树和，找到距离S/2最近的那一个。

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
    // 二叉树所有节点总和
    private static double allSum = 0;
    // 二叉树总和的一半
    private static double halfSum = 0;
    // 距离halfSum最近的那个子树和
    private static double dstSubSum = 0;
    // 最近子树和与halfSum的距离，offsetValue = | dstSubSum - halfSum |
    private static double offsetValue = 0;

    public static double GetSum(TreeNode node) {
        if (node == null) {
            return 0;
        }
        
        return node.val + GetSum(node.left) + GetSum(node.right);
    }

    public static double GetSubSum(TreeNode node) {
        if (node == null) {
            return 0;
        }
        double curSum = node.val + GetSubSum(node.left) + GetSubSum(node.right);
        double offset = 0;
        if (curSum < halfSum) {
            offset = halfSum - curSum;
        } else {
            offset = curSum - halfSum;
        }

        // 遍历二叉树，找到那个最小差值
        if (offset < offsetValue) {
            offsetValue = offset;
            dstSubSum = curSum;
        }

        return curSum;
    }
    public int maxProduct(TreeNode root) {
                allSum = GetSum(root);
        halfSum = allSum / 2;
        offsetValue = halfSum;

        // 重新遍历找到最小偏移
        GetSubSum(root);
        int value = (int) ((dstSubSum * (allSum - dstSubSum)) % (1e9 + 7));
        return value;
    }
}
```