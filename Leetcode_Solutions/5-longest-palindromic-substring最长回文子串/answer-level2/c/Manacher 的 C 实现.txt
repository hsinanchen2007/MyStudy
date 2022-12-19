Manacher算法
```c
char *longestPalindrome(char *s) {
	// 若字符串为空，则返回 ""
	int sLength = strlen(s);
	if (s == NULL || sLength == 0)
		return "";
	// 对传入字符串进行预处理，通过添加特殊符号，统一奇偶运算
	int tLength = sLength * 2 + 3;
	char *t = (char *)malloc(sizeof(char) * tLength);
	t[0] = '^';
	t[tLength - 1] = '$';
	t[1] = '#';
	for (int i = 0; i < sLength; i++) {
		t[(i + 1) * 2] = s[i];
		t[(i + 1) * 2 + 1] = '#';
	}
	// 创建int型数组，记录以每个字符为中心的回文串的长度，并进行初始化
	int *palindromeLength = (int *)malloc(sizeof(int) * tLength);
	palindromeLength[0] = palindromeLength[1] =0;
	palindromeLength[tLength - 1] = palindromeLength[tLength - 2] = 0;
	// 算法核心
	int center = 1, rightEdge = center - palindromeLength[1];
	for (int i = 2; i < tLength - 2; i++) {
		int mirrorOfi = 2 * center - i;
		if (i < rightEdge && palindromeLength[mirrorOfi] < rightEdge - i) {
			palindromeLength[i] = palindromeLength[mirrorOfi];
		} else{
			int tempLength = i < rightEdge ? rightEdge - i : 0;
			while (t[i + tempLength + 1] == t[i - tempLength - 1]) {
				tempLength++;
			}
			palindromeLength[i] = tempLength;
			center = i;
			rightEdge = center + tempLength;
		}
	}
	// 根据回文子串长度数组筛选出最长回文子串的中心。
	int maxPos = 0, maxCenter = 2, maxLen = 1; 
	for (int i = 3; i < tLength - 2; i++) {
		if (palindromeLength[i] > maxLen) {
			maxCenter = i;
			maxLen = palindromeLength[i];
		}
	}
	maxPos = (maxCenter - maxLen - 1) / 2; /*根据t串中的maxCenter和maxLen计算s串中的maxPos*/
	for (int i = 0; i < maxLen; i++) {
		t[i] = s[maxPos + i];
	}
	t[maxLen] = 0;
	free(palindromeLength);
	return t;
}
```