和之前的组合总和相比增加了新的条件，即只能是k个数的和，而且只能从数字1-9里选，且没有重复数字
在回溯时加上判断条件，如果cur.size()>k就return
如果cur里的数的和>n了，也return 
在cur.size()==k && sum == n的情况下，才添加到输出答案里
在backtrack中，因为不要重复，所以每次从当前数向后找就可以，比如当前数是i=2，那么不需要考虑添加1的情况，因为在i=1的时候已经考虑添加2的情况了
所以backtrack()每次递归都是在现有基础上当前数向后移动一个
代码如下：
```
class Solution {
public:
	vector<vector<int>>ans;
	void backtrack(vector<int>cur, int k, int n, int left)
	{
		if (cur.size() > k)
			return;
		int sum = 0;
		for (int i = 0; i < cur.size(); i++)
		{
			sum += cur[i];
		}
		if (sum > n)
			return;
		if (cur.size() == k)
		{
			if(sum == n)
			ans.push_back(cur);

			return;
		}
		for (int i = left; i <= 9; i++)
		{
			cur.push_back(i);
			backtrack(cur, k, n, i + 1);
			cur.pop_back();
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		if (n <= 0 || n > 45)
			return ans;
		vector<int>cur;
		backtrack(cur, k, n, 1);
		return ans;
	}
};
```
