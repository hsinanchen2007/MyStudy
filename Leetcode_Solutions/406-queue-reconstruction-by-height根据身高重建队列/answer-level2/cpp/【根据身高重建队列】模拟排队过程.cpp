### 分析
1. 虽然看起来需要顾虑这个那个，但排序的主要依据还是身高
2. `k` 作为附加数据，只是引入一些排序的规则
3. 如果 `k = 0` 那么就是普通的排序
4. 而且就算有 `k != 0` 的数据，也不影响 `k = 0` 的数据之间的顺序
5. 以此为突破口，可以想到如果 `k = 1` 的数据在有一个身高大于等于的数据已经确定之后，他也可以转化为 `k = 0`

### 思路
1. 对原数据排序
2. 使用一个计数数组，等于对应的 `k` 的值
3. 从前往后遍历，对每个遍历到的记录值 -1 
4. 如果操作之后是 -1 ，说明之前已经为 0 ，可以将它加入答案数组
5. 加入之后，保证这个身高的人都要 -1 ，然后就可以退出循环了
6. 把所有人加入之后，完成排序

### 答题
```C++
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	sort(people.begin(), people.end());
	vector<int> cnt(people.size(), 0);
	for (int i = 0; i < people.size(); i++)
	{
		cnt[i] = people[i][1];
	}

	vector<vector<int>> ans;
	size_t sz = 0;
	while (sz++ <= people.size())
	{
		int lastNum = -1;
		for (int i = 0; i < people.size(); i++)
		{
			if (lastNum != -1 && lastNum != people[i][0]) break;
			if (cnt[i] == -1) continue;
			cnt[i]--;
			if (cnt[i] != -1) continue;
			ans.push_back(people[i]);
			lastNum = people[i][0];
		}
	}

	return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

