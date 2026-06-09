### 解题思路
思路很简单，回溯+暴力查找每一个结果是否出现，使用map防止超时（测试发现count函数会超时）
![QQ图片20191205153647.png](https://pic.leetcode-cn.com/664e32a5fa47abc3d272e2573fb264dc708ff1d481ba147869daf99dd82f36b8-QQ%E5%9B%BE%E7%89%8720191205153647.png)
注释都有写，直接上代码，有没有大神可以给我一些优化时间复杂度的建议呢。
### 代码

```cpp
class Solution {
public:
	void backTrace(string s, map<string, int>& temp, string ss, vector<int>& vis, int len, int& ans)
	{
		/*回溯查找长度分别为len = 1,2,3...，tiles.length()的情况*/
		if (ss.length() == len)		//若已到len的长度
		{
			if (temp[ss] != 1)	//查找是否出现过该字符串，若未出现，ans++，并用map标记结果
			{
				ans++;
				temp[ss] = 1;
			}
			return;
		}

		for (int i = 0; i < s.length(); i++)	//遍历每个字符
		{
			if (!vis[i] && ss.length() < len)	//若未被遍历过，且临时字符串ss的长度还小于len
			{
				vis[i] = 1;		//标记
				ss += s[i];		//字符加入到ss字符串
				backTrace(s, temp, ss, vis, len, ans);	//进行回溯
				ss.pop_back();	//回到上一层
				vis[i] = 0;
			}
		}
	}

	int numTilePossibilities(string tiles) {
		vector<int> vis(tiles.length(), 0);		//访问数组
		map<string, int> temp;		//map标记结果
		string s = "";
		int ans = 0;
		for (int i = 1; i <= tiles.length(); i++)	//对所有的len进行遍历
		{
			backTrace(tiles, temp, s, vis, i, ans);
		}
		return ans;
	}
};
```