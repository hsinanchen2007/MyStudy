#### 二元一次方程组
题目实际就是求二元一次方程组的非负整数解，如果没有则返回`[]`。
 - `4 * total_jumbo + 2 * total_small = tomatoSlices`
 - `1 * total_jumbo + 1 * total_small = cheeseSlices`

用消元法求解得：
 - `total_jumbo = (tomatoSlices - 2 * cheeseSlices) / 2`
 - `total_small = cheeseSlices - total_jumbo`

这一题被划分到***中等***难度，是因为他们数学真的比较差么？谜之疑惑。
```
class Solution {
public:
	vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
		vector<int> total;
		if (tomatoSlices - 2 * cheeseSlices < 0 ||
			(tomatoSlices - 2 * cheeseSlices) % 2 != 0)
			return total;

		int nTotalJumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
		int nTotalSmall = cheeseSlices - nTotalJumbo;
		if (nTotalSmall < 0)
			return total;

		total.push_back(nTotalJumbo);
		total.push_back(nTotalSmall);
		return total;
	}
};
```