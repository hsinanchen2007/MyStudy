### 解题思路
看到题目之后并没有什么好的解题思路，但是看到数据范围给得挺小的，于是就有了暴力求解的想法，不过仍然没有下手，直到看到题目下面的三个提示，解题思路才逐渐成型。
1. 提示1：回溯。每次选择一个位置，选择一个长度，铺下一块正方形砖。
2. 提示2：下一块正方形砖块铺放的位置，以及可行的宽度。扫描矩形区域，从上往下，从左往右，选择扫描到的第一个没有铺砖的位置。这一点是可以优化的，我并没有再继续尝试，直接暴力扫描的。
3. 提示3：砖块数量最多`max(n,m)`。这个待证明，我不太擅长这个，有知道的指导一下就更好了，多谢。

### 代码
我写了两份递归的解法，它们的不同点在于，第一个解法是按照从大到小的边长进行组合求解，而第二个解法是按照从小到大。提交之后发现，解法一（从大到小，48ms）的时间效率要明显优于解法二（从小到大，1708ms）。
```cpp []
class Solution {
public:
	int tilingRectangle(int n, int m) {
		vector<vector<bool>> rectangle(n, vector<bool>(m, false));

		// 题目提示3；待证明
		int minNum = max(n, m);
		tilingRect(rectangle, 0, minNum);
		return minNum;
	}

	// 题目提示1：递归/回溯
	void tilingRect(
		vector<vector<bool>>& rectangle,
		int squaresNum,
		int& minNum)
	{
		if (squaresNum >= minNum)
			return;

		pair<int, int> nextSpot = findNextSpot(rectangle);
		if (nextSpot.first < 0) {
			minNum = min(minNum, squaresNum);
			return;
		}

		// 计算正方形砖块最大边长
		int maxLen = calcMaxLen(rectangle, nextSpot);
		// 铺一块最大的砖
		coverSquare(rectangle, nextSpot, maxLen);
		for (int len = maxLen; len > 0; --len) {
			// 铺下一块砖
			tilingRect(rectangle, squaresNum + 1, minNum);
			// 减小边长，重新铺这块砖
			uncoverSquare(rectangle, nextSpot, len);
		}
	}

	// 题目提示2
	pair<int, int> findNextSpot(const vector<vector<bool>>& rectangle) {
		for (size_t i = 0; i < rectangle.size(); ++i) {
			for (size_t j = 0; j < rectangle[i].size(); ++j) {
				if (!rectangle[i][j])
					return make_pair(int(i), int(j));
			}
		}
		return make_pair(-1, -1);
	}

	int calcMaxLen(
		const vector<vector<bool>>& rectangle,
		const pair<int, int>& spot)
	{
		int len = 1;
		while (size_t(spot.first + len - 1) < rectangle.size()
			&& size_t(spot.second + len - 1) < rectangle[spot.first].size()
			&& !rectangle[spot.first][spot.second + len - 1])
			++len;
		return len - 1;
	}

	// 铺砖：铺一块最大的砖
	void coverSquare(
		vector<vector<bool>>& rectangle,
		const pair<int, int>& spot,
		const int len)
	{
		for (int i = spot.first; i < spot.first + len; ++i) {
			for (int j = spot.second; j < spot.second + len; ++j) {
				rectangle[i][j] = true;
			}
		}
	}

	// 减小边长：去掉最外围的
	void uncoverSquare(
		vector<vector<bool>>& rectangle,
		const pair<int, int>& spot,
		const int len)
	{
		for (int i = 0; i < len; ++i) {
			rectangle[spot.first + len - 1][spot.second + i] = false;
			rectangle[spot.first + i][spot.second + len - 1] = false;
		}
	}
};
```
```cpp []
class Solution {
public:
	int tilingRectangle(int n, int m) {
		vector<vector<bool>> rectangle(n, vector<bool>(m, false));

		// 题目提示3；待证明
		int minNum = max(n, m);
		tileRect(rectangle, 0, minNum);
		return minNum;
	}

	// 题目提示1：递归/回溯
	void tileRect(
		vector<vector<bool>>& rectangle,
		int squaresNum,
		int& minNum)
	{
		if (squaresNum >= minNum)
			return;

		pair<int, int> nextSpot = findNextSpot(rectangle);
		if (nextSpot.first < 0) {
			minNum = min(minNum, squaresNum);
			return;
		}

		int len = 1;
		for (
			;
			size_t(nextSpot.first + len - 1) < rectangle.size() &&
			size_t(nextSpot.second + len - 1) < rectangle[nextSpot.first].size() &&
			!rectangle[nextSpot.first][nextSpot.second + len - 1];
			++len)
		{
			coverSquare(rectangle, nextSpot, len);
			tileRect(rectangle, squaresNum + 1, minNum);
		}

		// 回溯前还原状态
		uncoverSquare(rectangle, nextSpot, len - 1);
	}

	// 题目提示2
	pair<int, int> findNextSpot(const vector<vector<bool>>& rectangle) {
		for (size_t i = 0; i < rectangle.size(); ++i) {
			for (size_t j = 0; j < rectangle[i].size(); ++j) {
				if (!rectangle[i][j])
					return make_pair(int(i), int(j));
			}
		}
		return make_pair(-1, -1);
	}

	// 铺砖：铺x+len-1这一列和y+len-1这一行
	void coverSquare(
		vector<vector<bool>>& rect,
		const pair<int, int>& spot,
		const int len)
	{
		for (int i = 0; i < len; ++i) {
			rect[spot.first + len - 1][spot.second + i] = true;
			rect[spot.first + i][spot.second + len - 1] = true;
		}
	}

	// 回溯前还原
	void uncoverSquare(
		vector<vector<bool>>& rect,
		const pair<int, int>& spot,
		const int len)
	{
		for (int i = spot.first; i < spot.first + len; ++i) {
			for (int j = spot.second; j < spot.second + len; ++j) {
				rect[i][j] = false;
			}
		}
	}
};

```