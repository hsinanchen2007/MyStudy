### 二分查找
这一题很好地满足了二分的要求。1. 有序；2. 求中间解。

直接暴力AC了，都懒得二分。。。
```
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> vecAns;
		for (int x = 1; x <= 1000; ++x) {
			for (int y = 1; y <= 1000; ++y) {
				int fxy = customfunction.f(x, y);
				if (fxy == z) {
					vector<int> ans;
					ans.push_back(x);
					ans.push_back(y);
					vecAns.push_back(ans);
				}

				if (fxy >= z) {
					break;
				}
			}
		}

		return vecAns;
	}
};
```