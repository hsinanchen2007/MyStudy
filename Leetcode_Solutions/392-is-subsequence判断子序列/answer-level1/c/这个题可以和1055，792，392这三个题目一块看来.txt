### 解题思路
此处撰写解题思路
1.首先版本判断s中出现的字符是否在t中是否存在，如果不存在，直接返回false。利用哈希算法，散列后对比。
2.利用一个游标。先找到s第0个字符是t第start个的开始，顶住这个数值。i跳过一个，接下来，如果s[i] ==t[end] 就是代表已经找到了s[i],就可以+1了。
  再找s中的下一个，不管s[i]是否找到，end都要往前走+1，因为如果相等，s和t都要向前推进一步；如果不相等，i不动，t也要向前一步，来匹配新值。
  如果最终i大小等于s的长度，就等于s再t的子集中全找到了。

这个解完，再看792，调用下就行了（不过会超时）
改造后就是762
### 代码

```c

#define SIZE_MAX_MARK 26
/* 392. 判断子序列 */
bool isSubsequence(char* s, char* t) {
	int sourceList[SIZE_MAX_MARK] = { 0 };
	int targetList[SIZE_MAX_MARK] = { 0 };
	if (s == NULL || t == NULL) {
		return false;
	}
	int targetLen = strlen(t);
	int sourceLen = strlen(s);
	char* sourceTmp = s;
	char* targetTmp = t;

	if (sourceLen == 0) {
		return true;
	}
	while (*sourceTmp != '\0') {
		sourceList[*sourceTmp - 'a']++;
		sourceTmp++;
	}
	while (*targetTmp != '\0') {
		targetList[*targetTmp - 'a']++;
		targetTmp++;
	}

	for (int i = 0; i < SIZE_MAX_MARK; i++) {
		if (sourceList[i] != 0 && targetList[i] == 0) {
			return false;
		}
	}

	int start = 0;
	int end = 0;
	int i = 0;

	
	while (t[start] != s[0]) {
		start++;
	}
	end = start + 1;

	i++;
	while (i < sourceLen && end < targetLen) {
		if (t[end] == s[i]) {
			i++;
		}
		end++;
	}

	if (i == sourceLen) {
		return true;
	}

	return false;
}
```
