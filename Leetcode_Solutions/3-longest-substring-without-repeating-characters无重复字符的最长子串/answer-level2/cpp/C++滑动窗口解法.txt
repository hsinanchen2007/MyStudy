写了一个C++的解法，已经通过了。。。关键点在这几个地方。。。
1. 用字符位图当做map用，可以加快速度。。。
2. 滑动窗口的主要处理难度在于出现重复字符的end位置与start位置的关系。
3. 现在看起来一共有三种关系。
3.1 重复字符位置 < start  这种情况出现在“abba”的测试中在判断最后一个a的时候会出现。
a     b     b     a
          start  dup
此时只需要简单的更新map里a的位置。 

3.2 重复字符位置 = start  这种就是"abcabcbb"出现的a,b,c对应前面的start
遇到这种情况 start 向前移动一个位置，然后更新map里重复字符的位置
 

3.3 重复字符位置 > start  情况"abba"里 第二个b是大于start位置的
此时，start可以快速移动到dup + 1的位置，然后更新map索引。

代码如下：

```
int lengthOfLongestSubstring(string s)
 {
	int charmap[128];
	size_t maxLen = 0;
	int start = 0;
	int end = 0;
	int len = 0;
	memset(charmap, -1, 128 * sizeof(int));
	
	for (end = 0; end < s.size(); ++end)
	{
		// 无重复，加入map
		if (charmap[s[end]] == -1)
		{
			charmap[s[end]] = end;
		}
		else
		{
			// 首先计算出来此时串的长度
			len = end - start;

			maxLen = maxLen > len ? maxLen : len;

				// 出现重复的字符在start的前面
			// 比如“abba”这种模式，此时
			// a虽然重复，但是start在第一个b这里
			// 只需要简单的把重复索引更新到end上
			if (charmap[s[end]] < start)
			{
				charmap[s[end]] = end;
				continue;
			}
			else if (charmap[s[end]] == start )
			{
				// 这种情况如"abcabcbb"
				// 重复字符就是start的位置
				// start简单更新到下一个字符
				start = start + 1;
			}
			else
			{
				// 这种情况例如"abba"中
				// 第二个b的情况，重复字符并不是start的位置
				// 此时start更新到上一个重复字符 + 1的位置
				start = charmap[s[end]] + 1;
			}

			// 只要遇到重复，就要更新map到重复字符的索引
			charmap[s[end]] = end;
		}
	}

	len = end - start;
	maxLen = maxLen > len ? maxLen : len;
	return maxLen;
}

```

