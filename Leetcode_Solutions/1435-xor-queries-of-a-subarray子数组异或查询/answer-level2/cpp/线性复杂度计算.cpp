 - 使用数组计算并保存前`k`个数字的异或运算结果：`xorResults[k] = arr[0] xor arr[1] xor ... xor arr[k]`
 - 根据异或运算的性质，`a xor a = 0`，那么计算某个`query`的异或结果：`queryResults[k] = xorResults[R[k]] xor xorResults[L[k] - 1]`
```
class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> xorResults;
		xorResults.push_back(arr[0]);
		for (size_t i = 1; i < arr.size(); ++i)
			xorResults.push_back(xorResults.back() ^ arr[i]);

		vector<int> queryResults;
		for (size_t i = 0; i < queries.size(); ++i)
		{
			const vector<int>& query = queries[i];
			if (query[0] == 0)
				queryResults.push_back(xorResults[query[1]]);
			else
				queryResults.push_back(xorResults[query[1]] ^ xorResults[query[0] - 1]);
		}

		return queryResults;
	}
};
```
