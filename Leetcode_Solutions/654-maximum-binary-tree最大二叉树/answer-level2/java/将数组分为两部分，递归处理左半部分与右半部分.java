```
public TreeNode constructMaximumBinaryTree(int[] nums) {
        if (nums.length < 1) return null;//如果数组为空，直接返回null
        int maxIndex = findMax(nums);//找出数组中的最大数据的下标
        TreeNode root = new TreeNode(nums[maxIndex]);//创建根节点
        int[] left = Arrays.copyOfRange(nums, 0, maxIndex);//把最大数据左边的数据放到一个数组中
        int[] right = Arrays.copyOfRange(nums, ++maxIndex, nums.length);//把最大数据右边的数据放到另一个数组中
        root.left = constructMaximumBinaryTree(left);//递归，根节点的左节点
        root.right = constructMaximumBinaryTree(right);//递归，根节点的右节点
        return root;
    }

/**找出数组中的最大数据的下标*/
private int findMax(int[] arr) {
        int index = 0;
        for (int i = 0;i < arr.length;i++) {
            if (arr[i] > arr[index]) {
                index = i;
            }
        }
        return index;
    }
```
