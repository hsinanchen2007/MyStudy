动态规划解法 比较奇葩 关键是设计memory结构 抓住本题词数和词长都很小但rows cols很长的特点 见代码注释

时间复杂度为O(N) N与rows-cols同数量级

```cpp
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
	// 从第 i 个词开始 这一行能放下几遍句子
	vector<int> dp(sentence.size(), 0);
	// 从第 i 个词开始 放下dp[i]遍句子后 变为第几个词
	vector<int> next(sentence.size(), 0);

	for (int i = 0; i < sentence.size(); ++i) {
	    int count = 0;
	    int ptr = i;
	    int cur = cols;
	    while (cur >= (int)sentence[ptr].size()) {
		cur -= sentence[ptr].size() + 1;
		++ptr;
		if (ptr == sentence.size()) {
		    ++count;
		    ptr = 0;
		}
	    }
	    dp[i] = count;
	    next[i] = ptr;
	}

	int count = 0;
	int cur = 0;
	for (int i = 0; i < rows; ++i) {
	    count += dp[cur];
	    cur = next[cur];
	}
	return count;
    }
};
```