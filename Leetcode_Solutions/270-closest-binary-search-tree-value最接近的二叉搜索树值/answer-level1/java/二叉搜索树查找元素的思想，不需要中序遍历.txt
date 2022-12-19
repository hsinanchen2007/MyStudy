### 解题思路
其实完全可以把target看成是在TreeNode中要查找的点，target如果大于root.val，那么最接近target的值，肯定在root.right的子树中，我们只要进入右子树去查找就行，反之就去root.left的子树中查找，每次都计算一下node.val和target的差的绝对值，遍历的同时，使用找最小值的思想，log(N)的时间复杂度就能找到最接近的值，空间复杂度是O(1)，还避免的递归中栈的消耗

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
    public int closestValue(TreeNode root, double target) {
        double minDiff = Double.MAX_VALUE;
        TreeNode closestNode = root;// 最接近的节点
        TreeNode node = root;
        while (node != null){
            double diff = Math.abs(node.val - target);// node.val和target差的绝对值
            if (diff < minDiff){// 比之前的最小值还小，记录下最小值和最接近的节点
                minDiff = diff;
                closestNode = node;
            }
            if (node.val > target){// target在node.left中
                node = node.left;
            }else if (node.val < target){// target在node.right中
                node = node.right;
            }else {// 这时候差是0，肯定不可能还有比0大的绝对值了，直接返回
                return node.val;
            }
        }
        return closestNode.val;
    }
}
```