阿里系Java程序员。专注Java，算法。公众号同名。
### 解题思路
使用递归，将数组拆分成两个不同的子数组，一个是当前数组最大值的左边数组，一个是当前数组最大值的右边数组，并且将index作为分割点，将start和end两个index传入到下一次递归函数中，最终返回TreeNode。

![image.png](https://pic.leetcode-cn.com/6669a6b397e4e5bd8962bdc1638fea5d3b49589fb7730d82f9d05c2b67db756c-image.png)

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

    int[] nums;

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        this.nums = nums;
        return helper(0, nums.length);
    }

    public TreeNode helper(int start, int end) {
        if (start >= end) {
            return null;
        }
        int max = nums[start];
        int index = start;
        for (int i = start + 1; i < end; i++) {
            if (max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }
        TreeNode root = new TreeNode(max);
        root.left = helper(start, index);
        root.right = helper(index + 1, end);
        return root;
    }


}
```