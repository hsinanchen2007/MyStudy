### 最大滑动窗口
滑动窗口问题，求窗口最大的大小，使得窗口内不会出现重复字符。
扫描字符串，用一个map来建立字符和其最后出现位置的映射，用一个pos记录重复字符最后出现的位置，即滑动窗口的左边界位置。
1. 如果当前字符没有在前面出现过(map中找不到)，滑动窗口的大小可直接增加1，右边界向右滑动一位；
2. 如果当前字符出现过，且该字符在前面的位置要比pos记录的位置要大，则更新pos；
3. 遍历过程中维护nMaxLen = max(nMaxLen, i - pos);

```
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int nMaxLen = 0;
		int nMaxLastCharPos = -1;				// 记录字符重复的最大位置
		std::map<char, int> mapCharPos;			// 记录字符最后出现的位置
		for (int i = 0; i < s.size(); ++i) {
			std::map<char, int>::iterator itFind = mapCharPos.find(s[i]);
			// 更新字符重复的最大位置
			if (itFind != mapCharPos.end())
				nMaxLastCharPos = std::max(nMaxLastCharPos, itFind->second);

			nMaxLen = std::max(nMaxLen, i - nMaxLastCharPos);

			// 移除旧的字符位置
			if (itFind != mapCharPos.end())
				mapCharPos.erase(itFind);
			// 添加新的字符位置
			mapCharPos.insert(std::make_pair(s[i], i));
		}

		return nMaxLen;
	}
};

```
我果真不适合写题解，写文章啊！
文末推荐leetcode官方题解:[Longest Substring Without Repeating Characters - leetcode官方题解](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetcod/)