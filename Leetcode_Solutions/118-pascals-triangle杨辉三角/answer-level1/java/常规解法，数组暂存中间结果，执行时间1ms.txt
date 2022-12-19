![1577081370(1).png](https://pic.leetcode-cn.com/6a4fe455ef54a2a9bf573508381f286449dfb447dbfcea6f6b7d19f6cd3cf861-1577081370\(1\).png)



```
public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> result = new ArrayList<>();
		if (numRows > 0) {
			int[][] nums = new int[numRows][numRows];
			for (int i = 0; i < numRows; i++) {
				Arrays.fill(nums[i], 1);
			}
			for (int i = 0; i < numRows; i++) {
				List<Integer> subList = new ArrayList<>();
				for (int j = 0; j <= i; j++) {
					if (j > 0 && j > 0 && i != j) {
						nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
					}
					subList.add(nums[i][j]);
				}
				result.add(subList);
			}
		}
		return result;
	}
```

