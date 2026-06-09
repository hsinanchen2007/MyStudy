和全排列的思路是很像的
递归结束的条件是cur.size() == nums.size(),这个时候肯定要return
但是只要cur.size()<nums.size()就可以作为一个解加入总的解
想想自己找子集的过程，不需要往回找，只需要往右边找就可以了
```
void backtrack(vector<int>nums, vector<int>cur, int left, vector<bool>visited)
{
	int s = nums.size();
	if (cur.size() <= s)
	{
		ans.push_back(cur);
		//return;
	}
	if (cur.size() == s)
		return;
	for (int i = left; i < s; i++)
	{
		int nu = nums[i];
		if (visited[i] == false)
		{
			cur.push_back(nu);
			visited[i] = true;
			backtrack(nums, cur, i + 1, visited);
			cur.pop_back();
			visited[i] = false;
		}
	}
}