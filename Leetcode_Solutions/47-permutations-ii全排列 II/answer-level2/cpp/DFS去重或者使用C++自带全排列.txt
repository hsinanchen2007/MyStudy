可以使用next_permutation，前提是先从小到大排序，该函数输出的就是无重复的全排列，运行时间24ms，击败98.87%。
```
vector<vector<int>> permuteUnique(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>>result;
	result.push_back(nums);
	while (next_permutation(nums.begin(), nums.end()))
	{
		result.push_back(nums);
	}
	return result;
}
```

另外一个思路就是DFS去重，可以先去重也可以后去重，但是后去重不仅麻烦耗时，而且在进行DFS的时候也会进行一些不必要的递归，因此我选择先去重，考虑重复的定义，其实就是同一位选进去了多个相同的数，换句话说就是若要不重复，同一位对同样的数只能使用一个，因此我们可以在每次DFS之前，也就是为本位置选数之前，判断是否已经使用过相同的数了，若没有则正常DFS，若有则跳过本次循环，这样不仅去掉了重复，而且减少了递归次数，运行时间36ms，击败96.77%。
```
void dfs(vector<int>& nums, map<int, int>& selected, int index, vector<int>& oneresult, vector<vector<int>>&result)
{
	map<int, bool> flag;								//记录本位置已经选择过的值
	if (index == nums.size())							//排列完一次
	{
		result.push_back(oneresult);					//本次结果加入最终结果
		return;
	}
	for (int i = 0; i < nums.size(); i++)				//对所有数据进行遍历
	{
		if (selected[i] != 0 || flag[nums[i]])			//若已经选择过则跳过
			continue;
		//这里使用人工方式进行回溯完全是因为函数参数使用的是引用，
		//使用引用的方式是为了减少递归中参数复制导致时间的浪费。
		selected[i] = 1;								//添加选中标识
		oneresult.push_back(nums[i]);					//本元素加入本次结果中
		flag[nums[i]] = true;
		dfs(nums, selected, index + 1, oneresult, result);	//下一次遍历
		selected[i] = 0;								//清除选中标识
		oneresult.pop_back();							//本元素出本次结果
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	map<int, int> selected;
	vector<int> oneresult;
	dfs(nums, selected, 0, oneresult, result);
	return result;
}
```

