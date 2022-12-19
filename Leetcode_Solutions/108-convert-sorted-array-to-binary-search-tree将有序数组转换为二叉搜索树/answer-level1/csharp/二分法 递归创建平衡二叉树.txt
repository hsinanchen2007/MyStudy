这题主要的思路就是采用二分法 和 递归的方法，来将有序数组创建为平衡二叉树，将数组一分为二，中间点为根节点，然后左侧和右侧分别为该根节点的左子树和右子树，然后对左侧、右侧数组采用相同的方法，一直递归下去创建各自的子树。
```
public TreeNode SortedArrayToBST(int[] nums)
    {
        return buildChildTree(0, nums.Length - 1, nums);
    }
    public TreeNode buildChildTree(int left, int right, int[] nums)
    {
        if (left > right)
        {
            return null;
        }
        int middle = (left + right) / 2;
        TreeNode root = new TreeNode(nums[middle]);
        root.left = buildChildTree(left, middle - 1, nums);
        root.right = buildChildTree(middle + 1, right, nums);
        return root;
    }
```
