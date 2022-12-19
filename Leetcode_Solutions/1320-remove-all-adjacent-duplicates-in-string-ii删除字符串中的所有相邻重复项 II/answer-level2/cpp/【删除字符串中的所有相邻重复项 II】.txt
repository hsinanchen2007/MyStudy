## 解法1
### 思路
1. 顺序遍历，记录不重复的字符和个数。
   11. 将新出现的不重复的字符存入到`string sub`，并使用`vector<int> cnt`来保存重复的个数。（模拟stack）
   12. 如果是重复字符，更新`cnt`。如果到达k个，则出栈`sub`和`cnt`。
2. 通过`sub`和`cnt`生成结果。


### 答题
```C++
string removeDuplicates(string s, int k)
{
	string sub;
	vector<int> cnt;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (sub.empty() || s[i] != sub.back())
		{
			sub.push_back(s[i]);
			cnt.push_back(1);
			continue;
		}
		if (++cnt.back() == k)
		{
			sub.pop_back();
			cnt.pop_back();
		}
	}
	string ans;
	for (size_t i = 0; i < sub.size(); i++)
	{
		while (cnt[i]-- > 0)
		{
			ans += sub[i];
		}
	}
	return ans;
}
```

## 没什么本质区别的解法2
### 思路
1. 顺序遍历，删除相邻重复项为k个的字符。
   11. 顺序遍历时，使用`int cnt`记录当前字符重复了几次。
   12. 如果重复字符到达k个，则可以归0，表示已经删除。
   13. 如果当前字符与前面不同，则将`cnt`个前字符，存储到新字符串中。
   14. 重置`cnt`，用来记录新字符的重复数。
   15. 遍历到最后一个字符时，
      151. 如果与前面的字符重复，像13一样处理就可以了。
      152. 如果不重复，像13一样处理，再补上最后一个字符。
2. 将结果字符串递归，如果长度没有变化就可以返回了。


### 答题
```C++
string removeDuplicates(string s, int k) 
{
	string ans;
	int cnt = 1;
	for (size_t i = 1; i < s.size(); i++)
	{
		if (s[i] == s[i - 1])
		{
			cnt = (cnt + 1) % k;
		}

		if (s[i] != s[i - 1] || i == s.size() - 1)
		{
			while (cnt > 0)
			{
				cnt--;
				ans.push_back(s[i - 1]);
			} 
			cnt = 1;
			if (s[i] != s[i - 1] && i == s.size() - 1)
			{
				ans.push_back(s[i]);
			}
		}
	}

	return (ans.size() == s.size()) ? ans : removeDuplicates(ans, k);
}
```


### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)