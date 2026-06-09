### 思路
1. 快使用滑动窗口
2. 对 `t` 的字符统计，存在 `unordered_map<char, int> _map` 中
3. 右边进入窗口的字符，如果是 `t` 的字符，就计数 ++
4. 左边离开窗口的字符，就计数 --
5. 在初始化的时候，把 `t` 的字符个数统计出来，用 -
6. 这样的好处是，在判断是否满足条件时，只需要判断各个字母计数 > 0 ，最多 26 次判断
7. 如果不统计，每次判断去遍历子串字符，会受长度量级增长的影响，超时

### 答题
```C++
string minWindow(string s, string t) 
{
	if (s.size() < t.size()) return "";
	if (t.size() == 1 && s.find(t[0]) != string::npos) return t;

	queue<size_t> _window;
	unordered_map<char, int> _map;
	string ans;
	size_t ans_len = UINT_MAX;
	bool bMapFlag = false;

	for (auto c : t)
	{
		_map[c]--;
	}

	auto f_check_map = [&_map, &bMapFlag]()
	{
		if (bMapFlag) return true;
		for (auto m : _map)
		{
			if (m.second < 0) return false;
		}
		bMapFlag = true;
		return true;
	};

	for (size_t i = 0; i < s.size(); i++)
	{
		if (_map.count(s[i]) == 0) continue;
		_window.push(i);
		_map[s[i]]++;
		while (_map[s[_window.front()]] > 0)
		{
			auto j = _window.front();
			_window.pop();
			_map[s[j]]--;
		}
		if (f_check_map())
		{
			auto k = (_window.size() > 1) ? _window.back() - _window.front() + 1 : UINT_MAX;
			if (k < ans_len)
			{
				ans = s.substr(_window.front(), k);
				ans_len = k;
			}
		}
	}
	return ans;
}
```




### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

