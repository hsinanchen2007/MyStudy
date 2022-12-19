### 思路
> 真的是个蠢方法，if-else写的头都疼了

1. 用一个vector来把大楼按照高度`Hi`存储。
   * 这样在vector增加的时候，就该记录**上升点**（高度升高时的，上面的点）。
   * 在vector减少的时候，就该记录**下降点**（高度下降时，下面的点）。

2. vector增加
   * 如果比vector最高记录还高，就增加一个记录。
   * 否则就从vector中找到合适的位置（二分查找），如果没有这个高度，就增加一个记录。
   * 如果已经有相同的高度，需要判断`Ri`是否有必要延长。

3. vector减少
   * 如果新读入的数据`Li`已经比vector中最高记录的`Ri`还大了，则应该减少记录。
   * 减少的时候要循环把所有已经失效的记录全部清掉。
   * 所有数据跑完，还需要清掉剩余vector。

4. 记录上升点
   * 新增加的在vector空的时候。
   * 新增加的比vector最高的还高的时候（注意`Li`一样的情况要特殊处理）。

5. 记录下降点
   * `x`要在vector减少时记录。
   * `y`要在vector减少后记录，如果vector空了，则为0。




### 答题
```C++
vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
	const size_t Li = 0;
	const size_t Ri = 1;
	const size_t Hi = 2;
	const size_t x = 0;
	const size_t y = 1;

	vector<vector<int>> ans;
	vector<vector<int>> vec;

	auto f_lower_bound = [&](const vector<int> &b)
	{
		int start = 0;
		int last = vec.size();
		while (start < last)
		{
			int mid = start + (last - start) / 2;
			if (vec[mid][Hi] < b[Hi])
			{
				start = mid + 1;
			}
			else
			{
				last = mid;
			}
		}
		return last;
	};

	auto f_insert = [&](const vector<int> &b)
	{
		if (vec.empty() || b[Hi] > vec.back()[Hi])
		{
			vec.push_back(b);
			return;
		}

		auto it = vec.begin() + f_lower_bound(b);

		if (b[Ri] <= (*it)[Ri]) return;
		if (b[Hi] == (*it)[Hi])
		{
			(*it) = b;
		}
		else
		{
			vec.insert(it, b);
		}
	};

	auto f_pop_back = [&]()
	{
		int _x = vec.back()[Ri];
		while (!vec.empty() && vec.back()[Ri] <= _x)
		{
			vec.pop_back();
		}
		int _y = vec.empty() ? 0 : vec.back()[Hi];
		ans.push_back({ _x, _y });
	};

	for (auto &b : buildings)
	{
		while (!vec.empty() && b[Li] > vec.back()[Ri])
		{
			f_pop_back();
		}

		if (vec.empty())
		{
			ans.push_back({ b[Li], b[Hi] });
		}
		else if (b[Hi] > vec.back()[Hi])
		{
			if (b[Li] == ans.back()[x])
			{
				ans.back()[y] = b[Hi];
			}
			else
			{
				ans.push_back({ b[Li], b[Hi] });
			}
		}

		f_insert(b);
	}

	while (!vec.empty())
	{
		f_pop_back();
	}

	return ans;
}
```



### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)