`内联代码`
```
void huisu(vector<vector<int>>& ret,vector<int>& candidates,int nowsum,int target)
{
	static vector<int> temp;
	for (int i = candidates.size()-1; i >= 0; i--)
	{
		if (temp.size() != 0 && candidates[i] > *(temp.end() - 1))
			continue;
		nowsum += candidates[i];
		temp.push_back(candidates[i]);
		if (nowsum == target)
		{
			ret.push_back(temp);
			nowsum -= candidates[i];
			temp.pop_back();
		}
		else if (nowsum < target)
		{
			huisu(ret, candidates, nowsum, target);
			nowsum -= candidates[i];
			temp.pop_back();
		}
		else
		{
			nowsum -= candidates[i];
			temp.pop_back();
		}
	}
	return;
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	int sum = 0;
	vector<vector<int>> ret;
	huisu(ret, candidates, 0, target);
	return ret;
}
```
