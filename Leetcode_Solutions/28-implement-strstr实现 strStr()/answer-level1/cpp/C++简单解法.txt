```cpp
 int strStr(string haystack, string needle) {
	int m = haystack.size();
	int n = needle.size();
	if (n == 0)
		return 0;
	int i = 0;
	int j = 0;
	while (i <= m-n) {
        //每次从needle的起始位置进行匹配
		j = 0;
		while (j < n && haystack[i + j] == needle[j])
			j++;
        //若needle全部匹配都匹配则返回haystack的当前位置
		if (j >= n)
			return i;
		i++;
	}
	return -1;
}
```
