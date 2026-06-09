### 解题思路
0123456
0 1 2 3
利用中心拓展，看作在某一点左右延伸，共有N(size)+N-1(字符之间)即2N+1个对称测试点
进行循环比较

### 代码

```cpp
class Solution {
public:
	string longestPalindrome(string s) {
		string maxwnd;
		if (s.size() == 0)
			return maxwnd;
		//中心拓展找对称
		int pos = 0,ifch=0;
		while (pos < 2 * s.size())
		{
			//左右比较
			int left , right;
			int count;
			if (pos % 2 == 0)
			{
				//此处为字符
				left = pos / 2 - 1; right = pos / 2 + 1;
				count = 1;
				if (count > maxwnd.size())
					maxwnd = string(s, pos/2, 1);
			}
			else
			{
				//此处为间隔
				left = pos / 2; right = pos / 2 + 1;
				count = 0;
			}
			while (left >= 0 && right < s.size())
			{
				if (s[left] != s[right])
					break;
				//get echo string;
				count+=2;
				if (count > maxwnd.size())
					maxwnd = string(s, left, right - left + 1);
				left--; right++;//拓展搜索 
			}


			pos++;
		}

		return maxwnd;

	}
};

/*
时间复杂度太高
//利用滑动窗口解决：字串的通用尝试办法 
//窗口内不断添加
class Solution {
public:
	string longestPalindrome(string s) {
		string maxwnd;
		if (s.size() == 0)
			return maxwnd;
		int left = 0, right = 0;
		while (left < s.size())
		{
			//更新wnd
			string wnd;
			right = left;
			while (right < s.size())
			{
				wnd.push_back(s[right]);
				right++;
				
				bool ifecho = true;
				for (int i = 0; i < wnd.size() / 2; i++)
					if (wnd[i] != wnd[wnd.size() - i-1])
					{
						ifecho = false;
						break;
					}
				if (!ifecho)
					continue;

				if (wnd.size() > maxwnd.size())
					maxwnd = wnd;
			}
			left++;
		}
		return maxwnd;
	}
};*/


```