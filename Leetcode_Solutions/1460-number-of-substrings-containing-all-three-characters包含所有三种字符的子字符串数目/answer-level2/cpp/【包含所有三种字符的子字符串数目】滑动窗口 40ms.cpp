### 思路
1. 使用滑动窗口
2. 当滑动窗口满足时，将窗口左右的字母个数乘起来，就是满足的子串数量
3. 然后再滑，再加

### 答题
```C++
class Solution {
public:
	bool getAll(vector<int>& vi)
	{
		for (auto n : vi)
		{
			if (n == 0) return false;
		}
		return true;
	}

	int numberOfSubstrings(string s) 
	{
		int ans = 0;
		int left = 0;
		vector<int> vi(3, 0);
		queue<int> que;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'a' || s[i] == 'b' || s[i] == 'c')
			{
				vi[s[i] - 'a']++;
				que.push(i);

				while (getAll(vi))
				{
					int a = que.front() - left + 1;
					int b = s.size() - i;
					ans += a * b;

					vi[s[que.front()] - 'a']--;
					que.pop();
					left = que.front();
				}
			}
		}

		return ans;
	}
};
```




### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

