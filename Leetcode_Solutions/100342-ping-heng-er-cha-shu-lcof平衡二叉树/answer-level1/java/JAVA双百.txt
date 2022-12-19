### 解题思路
判断一棵树是否为平衡二叉树，需要遍历每个节点，并且需要得到该节点是否为平衡二叉树、该节点的高度。
![批注 2020-03-27 154956.png](https://pic.leetcode-cn.com/1b2e3184917fc9acb79d7ba3d47f034b427d2ede980537ef2fbbc0cd60a4a9c8-%E6%89%B9%E6%B3%A8%202020-03-27%20154956.png)

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
    public static class returnData {
        boolean isAVL;
        int height;

        public returnData(boolean isAVL, int height) {
            this.isAVL = isAVL;
            this.height = height;
        }
    }
    protected static returnData Process(TreeNode node) {
        if (node == null)
            return new returnData(true, 0);

        returnData left = Process(node.left);
        left.height++;
        returnData right = Process(node.right);
        right.height++;

        if (left.isAVL && right.isAVL && Math.abs(left.height - right.height) < 2)
            return new returnData(true, Math.max(left.height, right.height));

        return new returnData(false, Math.max(left.height, right.height));
    }

    public static boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;

        returnData leftReturnData = Process(root.left);
        returnData rightReturnData = Process(root.right);

        return leftReturnData.isAVL && rightReturnData.isAVL && Math.abs(leftReturnData.height - rightReturnData.height) < 2;
    }
}
```