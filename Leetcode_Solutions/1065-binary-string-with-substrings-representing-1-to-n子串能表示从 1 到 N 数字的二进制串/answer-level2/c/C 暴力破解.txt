bool queryString(char* S, int N) {
	char *a = 0;
	for (int i = 1; i <= N; i++) {
		char str[36] = {0};
		char str2[36] = {0};
		for (int j = 0, k = i; k != 0; j++) {
			str[j] = (k % 2) + 48;
			k /= 2;
		}
		int m = 0;
		while (str[m] != 0) {
			str2[strlen(str)-m-1] = str[m];
			m++;
		}
		a = strstr(S, str2);
		printf("%s %s\n",str ,str2);
		if (a == 0) {
			return false;
		}
	}
	return true;
}

循环N次，i从1到N,每次把i变成二进制字符串保存到字符数组里，使用strstr函数判断字符数组是否是S字符串的子串，一旦不是结束函数，返回false
循环执行完成时返回true