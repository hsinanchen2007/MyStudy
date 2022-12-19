### 执行时间
![图片.png](https://pic.leetcode-cn.com/17c0b7883db66cb4313622480abaf5f0e0f5475abfd35a257d3830f6440b90cd-%E5%9B%BE%E7%89%87.png)

看个乐~~


### 思路
1. 动态规划
2. 前面先算是否可以全部拆分
3. 跟 [139.单词拆分](https://leetcode-cn.com/problems/word-break/solution/139-by-ikaruga/) 一样
4. 实际上我也是直接把那个代码原封不动加进来了
	> 如果不先验证能否拆分，直接求字符串，某用例给我把内存爆到 10 个 g
5. 如果可以拆分，接下来组合字符串
6. 定义 `vector<vector<string>> dp(s.size() + 1, vector<string>())` 
    * 假设从开始到第 i - 1 个字符是与字典匹配的一个词，那么第 i 个字符是一个新词的开头字母
    * 把这个词**添加**到 `dp[i]` 中
    * 从第 i 个字符如果再匹配到一个词，把 `dp[i]` 中的每个词加个空格再加上新词，**添加**到后面的 `dp[j]` 中 
    * `dp[i]` 表示第 i 个字符前，所有的拆分情况
7. 所以，答案应该为 `dp.back()`

### 模拟
```
Input: s = "catsanddog", wordDict = ["cat", "cats", "and", "sand", "dog"]
Output: ["cats and dog", "cat sand dog"]
```

<![图片.png](https://pic.leetcode-cn.com/2e2043edde8ea50c0391aba9567f128d90d3cbbcb45ec7de445c6b6928b010df-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/7bb83b00a0b63879a2f425fbf97914c1449a9cc8d21e4c4315da152ddd6156cd-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/733e61997e169bd0eebc4244d734164282e1c5e2cb8d40dee81a80167c582986-%E5%9B%BE%E7%89%87.png),![图片.png](https://pic.leetcode-cn.com/751dee6d5eaddf08f8c62b07644f8d13e25e8439e8a851f706a21e265566d507-%E5%9B%BE%E7%89%87.png)>




### 答题
```C++
class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		if (!wordBreak_139(s, wordDict)) return {};

		size_t validEnd = 0;
		vector<vector<string>> dp(s.size() + 1, vector<string>());

		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return {};
			if (i != 0 && dp[i].empty()) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) != 0) continue;
				validEnd = max(validEnd, newEnd);
				if (i == 0)
				{
					dp[newEnd].push_back(word);
					continue;
				}
				for (auto& d : dp[i])
				{
					dp[newEnd].push_back(d + " " + word);
				}
			}
		}

		return dp.back();
	}

	bool wordBreak_139(string& s, vector<string>& wordDict)
	{
		size_t validEnd = 0;
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == validEnd + 1) return false;
			if (!dp[i]) continue;
			for (auto& word : wordDict)
			{
				size_t newEnd = i + word.size();
				if (newEnd > s.size()) continue;
				if (memcmp(&s[i], &word[0], word.size()) == 0)
				{
					dp[newEnd] = true;
					validEnd = max(validEnd, newEnd);
				}
			}
		}
		return dp.back();
	}
};
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

