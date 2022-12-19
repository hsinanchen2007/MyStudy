和107类似，遍历二叉树，找到叶子结点，用List记录它们的深度，对List进行排序，找到最小的值
```
    public int minDepth(TreeNode root) {
		if(root == null) return 0;
		List<Integer> list = new ArrayList<Integer>();
		List ret = helper(root, 0, list);
		Collections.sort(ret);
		return (int) ret.get(0);
    }
    public List helper(TreeNode root, int depth, List list) {
		if(root.left != null) helper(root.left, depth+1, list);
		if(root.right != null) helper(root.right, depth+1, list);
		if(root.left == null && root.right == null)
		{
			list.add(depth+1);
		}
		return list;
	}
```
性能一般：
执行用时 :7 ms, 在所有 Java 提交中击败了24.26%的用户
内存消耗 :39.2 MB, 在所有 Java 提交中击败了24.16%的用户

看到另一个答案里更简洁的版本，思想类似但是比我的简洁多了：
```
 public int minDepth(TreeNode root) {
        if (root == null) return 0;
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        return (left == 0 || right == 0) ? left + right + 1 : Math.min(left, right) + 1;
    }

作者：powcai
链接：https://leetcode-cn.com/problems/two-sum/solution/gen-jie-dian-bu-shi-xie-zi-jie-dian-by-powcai/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
