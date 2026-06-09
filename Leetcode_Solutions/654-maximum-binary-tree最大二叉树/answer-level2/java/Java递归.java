```
class Solution {
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return buildTree(nums);
    }

    private TreeNode buildTree(int nums[]) {
        if (nums.length == 0) return null;
        int val = findMax(nums);
        TreeNode root = new TreeNode(val);
        root.left = buildTree(getArrayLeftPart(nums, val));
        root.right = buildTree(getArrayRightPart(nums, val));
        return root;
    }

    private int[] getArrayLeftPart(int[] nums, int val) {
        int x[] = {};
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val) {
                x = Arrays.copyOf(nums, i );
            }
        }
        return x;
    }

    private int[] getArrayRightPart(int[] nums, int val) {
        int x[] = {};
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val) {
                x = Arrays.copyOfRange(nums, i + 1, nums.length);
            }
        }

        return x;
    }


    private int findMax(int nums[]) {
        if (nums.length == 0 || nums == null) {
            return -1;
        }
        int max = Integer.MIN_VALUE;
        for (Integer num : nums) {
            max = Math.max(max, num);
        }
        return max;
    }
}
```