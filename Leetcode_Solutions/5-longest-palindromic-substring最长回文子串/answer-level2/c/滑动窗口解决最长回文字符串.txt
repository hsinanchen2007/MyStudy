### 解题思路
依旧滑动窗口，分为中间单个字母和中间两个字母的情况
以字母为窗口中心，向两侧展开。

### 代码

```c
char * longestPalindrome(char * s) {
	char *p, *q, *t;
	p = s;
	q = p;
	int len;
	int max_len = 0;
	int now_len = 0;
	char *pmax=NULL, *qmax=NULL;
	len = strlen(s);
	char *buf = (char*)malloc((len+1) * sizeof(char));
	memset(buf, 0, (len+1)*sizeof(char));
	char *ret;
	ret = buf;
	if (len == 0||len ==1)    return s;
	else if (len == 2) {
		if (*s == *(s + 1))   return s;
		else {
            *buf=*s;
            return buf;
        }
	}
	//中间是单个字母的情况
	for (t = (s + 1); t < (s + len - 1); t++) {
		for (p = (t - 1), q = (t + 1); p >= s&&q <= (s + len); p--, q++) {
			if (*p != *q)  break;
		}
		now_len = q - p;
		if (now_len > max_len) {
			max_len = now_len;
			pmax = p+1;
			qmax = q-1;
		}
	}
	//中间是2个字母的情况
	for (t = s; t < s + len; t++) {
		for (p = t, q = (t + 1); p >= s && q <= (s + len); p--, q++) {
			if (*p != *q)  break;
		}
		now_len = q - p;
		if (now_len > max_len) {
			max_len = now_len;
			pmax = p + 1;
			qmax = q - 1;
		}
	}

	for (t = pmax; t <=qmax; t++) {
		*ret = *t;
		ret++;
	}
	return buf;
}
```