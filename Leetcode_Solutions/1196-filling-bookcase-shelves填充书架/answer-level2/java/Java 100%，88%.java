![微信图片_20200319223139.png](https://pic.leetcode-cn.com/c2c84ed1edb3db77fbc5a9054186ffbf1316ad915772788c6f3969f61868b05f-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200319223139.png)
采用递归+备忘录
```
class Solution {
	// 最小值问题初始化为无穷大
	private int INF = Integer.MAX_VALUE;
	// 缓存数组
	private int[] memo;
	
	public int minHeightShelves(int[][] books, int shelf_width) {
		int book_num = books.length;
		memo = new int[book_num+1];
		Arrays.fill(memo, INF);
		return dp(books, book_num, shelf_width);
	}

	private int dp(int[][] books, int book_num, int shelf_width) {
		// base case
		if (book_num == 0)
			return 0;
		if (memo[book_num]!=INF) return memo[book_num];

		int cur_width = 0, cur_height = 0;
		
		for (int j = 1; j <= book_num; j++) {
			cur_width += books[book_num - j][0];
			// 限制条件，宽度不得超过限制，否则跳出循环
			if (cur_width > shelf_width)
				break;
			cur_height = Math.max(cur_height, books[book_num - j][1]);
			// 考虑去除掉前j本书的子问题
			int subproblem = dp(books, book_num - j, shelf_width);
			// dp(i) = max{dp(0~i-1)+cur_height}
			memo[book_num] = Math.min(memo[book_num], 
					subproblem + cur_height);
		}
		return memo[book_num];
	}
}
```
