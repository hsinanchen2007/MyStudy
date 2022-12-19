### 解题思路
典型的动态规划中的记忆化搜索问题，DP为从n到0个数，记住，这里不能使用贪心算法，因为并不一定取最大的平方数就可以获得最小数量的平方数之和。

### 代码

```cpp
class Solution {
public:
	void GetSquareNumsUnderN(vector<int>& squareNums, int n) {
		int i = 1;
		while(i*i <= n) {
			squareNums.push_back(i*i);
			i++;
		}
	}
	int DPNumSquares(vector<int>& squareNums, int n, vector<int>& DpSquareVec)
	{
		if (n <= 0) {
			return 0;
		}
		if (DpSquareVec[n] != 0) {
			return DpSquareVec[n];
		}
		int minNum = n;
		for (int i = 0; i < squareNums.size() && squareNums[i] <= n; i++) {
			minNum = min(minNum, DPNumSquares(squareNums, n - squareNums[i], DpSquareVec) + 1);
		}
		DpSquareVec[n] = minNum;
		return DpSquareVec[n];
	}
    int numSquares(int n) {
        vector<int> squareNums;
		GetSquareNumsUnderN(squareNums, n);
		vector<int> DpSquareVec(n + 1, 0);
		return DPNumSquares(squareNums, n, DpSquareVec);
    }
};
```