```
public static TreeNode sortedArrayToBST(int[] nums) {
        if(nums==null || nums.length==0) return null;
        int mid = nums.length/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = sortedArrayToBST(Arrays.copyOfRange(nums,0,mid));
        root.right = sortedArrayToBST(Arrays.copyOfRange(nums,mid+1,nums.length));
        return root;
    }
```
既然是升序数组，那么就每次找最中间的值作为树的根。
比如：
第一层根是数组中间的那个数，因为数组左边的都比此根小，数组右边的都比此根大。那么这个根的左子树就等于原数组左边子数组中间的那个数，同理右子树就等于原数组右边子数组中间那个数。
接下来几层的方法一样，所以可以用递归实现。