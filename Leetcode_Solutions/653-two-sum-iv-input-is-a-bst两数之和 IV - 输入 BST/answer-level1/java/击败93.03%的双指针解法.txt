### 解题思路
阿里系Java程序员。专注Java，算法。公众号同名。
中序遍历二叉搜索树，用数组保存。对数组进行双指针搜索。

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

    List<Integer> list = new ArrayList<Integer>();

    public boolean findTarget(TreeNode root, int k) {

        helper(root);
        int left = 0;
        int length = list.size();
        if (length <= 1) {
            return false;
        }
        int right = length - 1;
        while (left < right) {
            int sum = list.get(left) + list.get(right);
            if (sum < k) {
                left++;
            } else if (sum > k) {
                right--;
            } else {
                return true;
            }
        }
        return false;
    }

    public void helper(TreeNode root) {
        if (root == null) {
            return;
        }
        helper(root.left);
        list.add(root.val);
        helper(root.right);
    }

}
```