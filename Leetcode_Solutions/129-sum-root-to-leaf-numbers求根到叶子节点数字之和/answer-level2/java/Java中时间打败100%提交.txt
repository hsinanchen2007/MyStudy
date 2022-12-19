### 解题思路
此处撰写解题思路
我很棒哦，嘿嘿！
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
    public int sumNumbers(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int res = 0;
        int sum = root.val;
        res += sumNumbers(root, res, sum);
        return res;
    }

    private int sumNumbers(TreeNode root, int res, int sum) {
        if (root.left == null && root.right == null) {
            res += sum;
            return res;
        }
        if (root.left != null) {
            sum = sum * 10 +  root.left.val;
            res = sumNumbers(root.left, res, sum);
            sum = (sum - root.left.val)/10;
        }
        if (root.right != null) {
            sum = sum * 10 +  root.right.val;
            res = sumNumbers(root.right, res, sum);
            sum = (sum - root.right.val)/10;
        }
        return res;
    }
}
```