```
public TreeNode sortedArrayToBST(int[] nums) {
        if (nums.length == 0) return null;
        int mid = nums.length/2;
        TreeNode root = new TreeNode(nums[mid]);
        int[] left = subArray(nums, 0, new int[mid], mid);
        int[] right = subArray(nums, mid+1, new int[nums.length-mid-1], nums.length-mid-1);
        root.left = sortedArrayToBST(left);
        root.right = sortedArrayToBST(right);
        return root;
    }

    private int[] subArray(int[] src, int start, int[] tar, int length) {
        System.arraycopy(src, start, tar, 0, length);
        return tar;
    }
```
