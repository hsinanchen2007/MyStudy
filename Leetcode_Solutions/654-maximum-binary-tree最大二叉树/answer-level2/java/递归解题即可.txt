```
import java.util.Arrays;
class Solution {
   public TreeNode constructMaximumBinaryTree(int[] nums) {
            if (nums == null) {
                return null;
            }
            if (nums.length == 1) {
                return new TreeNode(nums[0]);
            }
            int MaxVal = 0;
            int index = 0;
            int left[] = null;
            int right[] = null;
            for (int i = 0; i < nums.length; i++) {
                if (MaxVal < nums[i]) {
                    MaxVal = nums[i];
                    index = i;
                }
            }
            TreeNode t = new TreeNode(MaxVal);
            if (index != 0) 
                left = Arrays.copyOfRange(nums, 0, index);
            if (index != nums.length - 1)
                right = Arrays.copyOfRange(nums, index + 1, nums.length);
            t.left = constructMaximumBinaryTree(left);
            t.right = constructMaximumBinaryTree(right);
            return t;
        }
}
```

直接递归解题，找出数组最大值以及最大值的索引，然后根据这个分割数组。之后再递归调用得到最大子数组放到左右子树中即可。