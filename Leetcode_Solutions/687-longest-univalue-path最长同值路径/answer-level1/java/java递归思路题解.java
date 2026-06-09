![image.png](https://pic.leetcode-cn.com/cdec54de364db9c7a73ab3cb658d89ed41cd9cb4f658a88ae97fb5dd040e5119-image.png)
static List<Integer> list = new ArrayList<Integer>(); 
	public static int longestUnivaluePath(TreeNode root) {
		if (root == null) {
			return 0;
		}
		list = new ArrayList<Integer>();
		helper(root);
		int[] arr = list.stream().mapToInt(Integer::intValue).toArray();
		Arrays.sort(arr);
		return arr[arr.length - 1] - 1;
	}
	
	public static void helper(TreeNode root) {
		if (root == null) {
			return;
		}
		list.add(getMaxLength(root, root.val));
		helper(root.left);
		helper(root.right);
	}
	

	public static int getLength(TreeNode root, int k) {
		if (root == null || root.val != k) {
			return 0;
		}
		if (root.left == null && root.right != null) {
			return 1 + getMaxLength(root.right, k);
		}else {
			return 1 + getMaxLength(root.left, k) + getMaxLength(root.right, k);
		}
	}
	
	public static int getMaxLength(TreeNode root, int k) {
		if (root == null || root.val != k) {
			return 0;
		}
		return 1 + Math.max(getMaxLength(root.left, k), getMaxLength(root.right, k));
	}