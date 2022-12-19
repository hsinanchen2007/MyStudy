先贴代码
```
def lengthOfLongestSubstring(s):
	if(len(s) == 0):
		return 0
	i = 0
	j = maxLen = 1
	while(j != len(s)):		
		if s[j] in s[i:j]:
			i += s[i:j].index(s[j]) + 1
		j += 1
		maxLen = max(maxLen, len(s[i:j]))
	return maxLen
```
解释：
s[i:j]记录最长无重复子串，增加j并判断s[j]是否出现在s[i:j]中，如果出现，将i跳到s[i:j]中的s[j]的下标处。
