___# 字符串中的数值保存在一个数组，"-"的数量保存在另一个数组，再以先序遍历创建节点___
```
private int index = 1, // 前进索引
			numLen, // nums 的长度
			lLen; // depths 的长度

	/**
	 * DFS 使用先序遍历的方式 创建节点
	 * 
	 * @param S
	 * @return
	 */
	public TreeNode recoverFromPreorder(String S) {
		int len = S.length();
		// 存放 节点数值val 的数组
		int[] nums = new int[len], depths = new int[len];
		int index = 0, // 解析 S 时，nums 中 的前进索引，同时也是 nums 的真实数据大小
				cndex = 0; // 解析 S 时，sbs 中的 前进索引， 同时也时 depths 的真实数据大小
		// 将 S 的 "-" 的连续数量 解析到 depths ， 数值 解析到 nums 数组
		for (int i = 0; i < len; i++) {
			if (S.charAt(i) != '-') {
				while (i < len && S.charAt(i) != '-')
					nums[index] = nums[index] == 0 ? (S.charAt(i++) - 48) : nums[index] * 10 + (S.charAt(i++) - 48);
				i--;
				index++;
			} else {
				while (S.charAt(i) == '-' && i++ < len)
					depths[cndex]++;
				i--;
				cndex++;
			}
		}
		this.numLen = index;
		this.lLen = cndex;
		return dfs(new TreeNode(nums[0]), 1, depths, nums);
	}

	/**
	 * 
	 * @param root  TreeNode 节点
	 * @param depth 深度
	 * @param sbs   存放 "-" 的数组
	 * @param nums  存放 节点值的 数组
	 * @return
	 */
	private TreeNode dfs(TreeNode root, int depth, int[] depths, int[] nums) {
		if (index == numLen) // 临界点 返回
			return root;
		// 检查深度，若不相等说明 下一个节点不是该节点的子节点，该节点已没有子节点，下一个节点应是父节点（或父的父...）的子节点
		if (depths[index - 1] == depth) {
			// 先序遍历 向左
			root.left = dfs(new TreeNode(nums[index++]), depth + 1, depths, nums);
			// 临界点，返回
			if (index - 1 == lLen)
				return root;
			// 向右
			// 每次都要进行 深度检查，有可能该节点没有右子节点
			if (depths[index - 1] == depth)
				root.right = dfs(new TreeNode(nums[index++]), depth + 1, depths, nums);
		}
		return root;
	}
```