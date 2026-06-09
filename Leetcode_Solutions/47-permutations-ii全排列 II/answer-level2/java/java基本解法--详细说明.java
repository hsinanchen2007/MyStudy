```
class Solution {
	private int n;
	private List ls;
	private boolean[] bool;
	private LinkedList path;

	public List<List<Integer>> permuteUnique(int[] nums) {
		Arrays.sort(nums);
		n = nums.length;
		ls = new ArrayList<LinkedList>();
		path = new LinkedList<Integer>();
		bool = new boolean[n];
		dfs(nums, 0);
		return ls;
	}

	private void dfs(int[] nums, int u) {
		if (u == n) {
			ls.add(path.clone());
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!bool[i]) {
				if (i >= 1 && nums[i] == nums[i - 1] && bool[i - 1] == false)	 // if bool[i-1] ==true 的话 选择i位置 即可以满足条件 1
																				 // 2 1 i-1的位置比i快选择 
																			   	//如果i-1 还没选 而 在选i的时候 就可以直接跳出 说明已经重复选择i位置了
					// 第n趟递归是要在第n个位置选择一个数放置
					// num[i-1]会比nums[i]早被考虑放到当前位置上
					// 若bool[i-1]=false说明这个数在上一个排列中已经在这个位置放置过了
					// 所以当前位置不应该再放置与nums[i-1]相等的nums[i] 
					continue;
				path.add(nums[i]);
				bool[i] = true;
				dfs(nums, u + 1);
				bool[i] = false;
				path.removeLast();
			}
		}
	}
}
```
