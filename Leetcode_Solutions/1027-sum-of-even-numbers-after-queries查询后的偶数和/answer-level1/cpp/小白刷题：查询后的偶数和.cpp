每一次变化，只需考虑变化元素的奇偶性，未变化元素不用管

话说两次提交时间还不一样，差了150ms……怎么和网速还有关系的？……

代码：
```
class Solution {
public:
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
		int times = queries.size();
		int len = A.size();
		vector<int> ans(times);
		int sum = 0;
		for (int i = 0; i < len; i++) {
			if (!(A[i] % 2))
				sum = sum + A[i];
		}
		for (int i = 0; i < times; i++) {
			int index = queries[i][1];
			int val = A[index] + queries[i][0];
			if (!(A[index] % 2))
				sum = sum - A[index];
			if (!(val % 2))
				sum = sum + val;
			A[index] = val;
			ans[i] = sum;
		}
		return ans;
	}
};
```
