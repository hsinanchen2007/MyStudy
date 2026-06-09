![image.png](https://pic.leetcode-cn.com/9fcb9cea7d3d5817ce8f5da0428ce6cde5f3e284ef3e50a2ae8f17f2e009c859-image.png)

见代码，回溯最大深度是字典最大字符串长度
时间复杂度应该是 O(N*M) 空间应该是O(N+M),M是字典字符串不同长度的数量

bool wordBreak(string s, vector<string>& wordDict) {
        if (s.length() == 0)return false;
		unordered_set<string> words(wordDict.begin(), wordDict.end());
		set<int> myset;
		for (auto str : wordDict) {
			myset.emplace(str.length());
		}
		string tempStr;
		bool preIndexChanged = false;
		bool curIndexUpdated = false;
		int preIndex=0;
		int curIndex=0;
		
		while (curIndex != s.length())
		{
			curIndexUpdated = false;
			if (!preIndexChanged) {
				for (auto i = myset.rbegin(); i != myset.rend(); ++i) {
					if (preIndex+*i > s.size())continue;
					if (curIndex != 0 && preIndex + *i >= curIndex)continue;
					tempStr = s.substr(preIndex, *i);
					if (words.find(tempStr) != words.end()) {
						curIndex = preIndex + *i;
						curIndexUpdated = true;
						break;
					}
				}
				if (!curIndexUpdated)return false;				
			}
			preIndexChanged = false;
			for (auto i = myset.rbegin(); i != myset.rend(); ++i) {
				if (curIndex+*i > s.size())continue;
				tempStr = s.substr(curIndex, *i);
				if (words.find(tempStr) != words.end()) {
					preIndex = curIndex;
					curIndex = curIndex + *i;
					preIndexChanged = true;
					break;
				}
			}
		}
		return true;
	}


题目中的测试用例不全，以前提交一些错误的答案也会通过
