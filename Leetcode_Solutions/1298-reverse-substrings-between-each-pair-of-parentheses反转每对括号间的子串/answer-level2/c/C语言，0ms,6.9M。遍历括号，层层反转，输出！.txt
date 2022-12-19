C语言，0ms.先遍历一次，计算左右括号的个数和索引位置。然后从最里层括号进行反转，左括号要和第一个位置大于它的右括号对应，最后剔除括号
```
char * reverseParentheses(char * s) {
	if (s == NULL) {
		return NULL;
	}
	int len = strlen(s);
	int left[2000] = { 0 };
	int right[2000] = { 0 };
	int len1 = 0;
	int len2 = 0;
	//记录左右括号的个数和对应索引位置
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			left[len1] = i;
			len1++;
		}
		if (s[i] == ')') {
			right[len2] = i;
			len2++;
		}
	}
	//从内层括号开始反转字符串
	int offset = 0;
	for (int i = 0; i <len1; i++) {
		int x = left[len1 - i - 1];
		while (right[offset] < left[len1 - i - 1]) {   //寻找当前左括号右边的第一个右括号
			offset++;
		}
		int y = right[offset];
		right[offset] = -1; //使用过的剔除
		offset = 0;
		for (int j = 1; j <= (y - x) / 2; j++) {
			char tmp = s[x + j];
			s[x + j] = s[y - j];
			s[y - j] = tmp;
		}
	}
	//去除字符串中的括号
	char *sNew = (char*)malloc(sizeof(char)*(len - len1 - len2 + 1));
	if (*sNew == NULL) {
		return NULL;
	}
	int j = 0;
	for (int i = 0; i < len; i++) {
		if ((s[i] >= 'a') && (s[i] <= 'z')) {
			sNew[j] = s[i];
			j++;
		}
	}
	sNew[len - len1 * 2] = '\0';
	strcpy(s, sNew);
	free(sNew);
	sNew = NULL;
	return s;
}
```