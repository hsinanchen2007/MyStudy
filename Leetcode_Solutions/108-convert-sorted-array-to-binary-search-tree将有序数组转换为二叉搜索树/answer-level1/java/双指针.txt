### 双指针
![屏幕快照 2020-01-20 22.00.29.png](https://pic.leetcode-cn.com/76c746eb1fe74eb44dd7d1ea3b8a6f88c1023f6c473d7032f8375cb77165142d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-20%2022.00.29.png)


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
    public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) {
            return null;
        }
        return bst(nums , 0, nums.length);
    }

    // 双指针切分数组
    private TreeNode bst(int[] nums,int left, int right) {
        // 递归返回条件
        if (left == right) {
            return null;
        }
        // 拿到中间点 构建节点
        int center = (right + left) / 2;
        TreeNode root = new TreeNode(nums[center]);
        root.left = bst(nums, left, center);
        root.right = bst(nums, center + 1, right);
        return root;
    }
}
```