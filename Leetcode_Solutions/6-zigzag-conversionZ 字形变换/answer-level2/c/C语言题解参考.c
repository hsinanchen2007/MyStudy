```
void addString(char ary[], int len, char c) {
	int i;
	for (i = 0; i < len; i++) {
		if (ary[i] == '\0') {
			ary[i] = c;
			break;
		}	
	}
}

char * convert(char * s, int numRows){
	int len = strlen(s);
	if (len < numRows || numRows == 1)
		return s;
	char results[numRows][len];
	int i, k = 0;
	for (i = 0; i < numRows; i++) 
		memset(results[i], '\0', len * sizeof(char));
	int goingDown = 1;
	
	for (i = 0; i < len; i++) {
		if (k == 0) goingDown = 1;
		else if (k == numRows - 1) goingDown = -1;
		addString(results[k], len, s[i]);
		k += goingDown;
	}
	
	int j = 0;
	char* ret = (char*)malloc((len + 1) * sizeof(char));
	for (i = 0; i < numRows; i++) {
		for (k = 0; k < len; k++) {
			if (results[i][k] == '\0')
				break;
			ret[j++] = results[i][k];
		}
	}
	ret[j] = '\0';
	return ret;
}
```
（参考精选题解写出的C语言解法）
思路：将每一行作为独立的字符串最后拼接起来；
      构建字符串时候，无需考虑中间的空格；
      通过加一减一来构建字符串。

