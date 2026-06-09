### 解题思路

进化版298(还是第一次双100...)

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
    private int maxLength;

    private int longestSequence(TreeNode node, int prev) {
        if (node == null) return 0;
        int curr = node.val;
        int plus = 0, length = 0, res = 0;
        int left = longestSequence(node.left, curr);
        int right = longestSequence(node.right, curr);
        if (prev - curr == -1) {
            plus = 1;
        } else if (prev - curr == 1) {
            plus = -1;
        }

        if (left == 0 && plus * right > 0) {
            res = plus + right;
        } else if (right == 0 && plus * left > 0) {
            res = plus + left;
        } else if (plus * right > 0 && plus * left < 0) {
            res = plus + right;
        } else if (plus * left > 0 && plus * right < 0) {
            res = plus + left;
        } else if (plus * left > 0 && plus * right > 0) {
            res = left > 0 ? plus + Math.max(left, right) : plus + Math.min(left, right);
        } else {
            res = plus;
        }

        if (left * right < 0) {
            length = left - right > 0 ? left - right : right - left;
        } else {
            length = res > 0 ? res : -res;
        }
        length += 1;
        maxLength = Math.max(length, maxLength);

        return res;
    }

    public int longestConsecutive(TreeNode root) {
        if (root == null) return 0;
        maxLength = 0;
        int fakeValue = root.val == Integer.MAX_VALUE - 1 ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        int length = longestSequence(root, fakeValue);
        return maxLength;
    }
}
```