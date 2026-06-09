### 解题思路
此处撰写解题思路

### 代码

```c
#define C_MAX 26

int UpdateIflag(char *text, int start, int end, int *flag)
{
	if (start >= strlen(text) || end >= strlen(text)) {
		return -1;
	}
	int i;
	for (i = start; i <= end; i++) {
		flag[text[i] - 'a']++;
	}
	return 0;
}

int HowManyChar(int *flag, char *oneChar)
{
	int cnt = 0;
	int cnt1 = 0;
	int i;
	for (i = 0; i < C_MAX; i++) {
		if (flag[i] > 0) {
			cnt++;
		}
		if (flag[i] == 1) {
			cnt1++;
		}
		if (flag[i] >= 2) {
			*oneChar = i + 'a';
		}
		if (cnt > 2) {
			break;
		}
	}
	if (cnt1 != 1) {
		*oneChar = 0;
	}
	return cnt;
}

int maxRepOpt1(char * text) {
	int i;
	int j;
	int len = strlen(text);
	if (len < 2) {
		return len;
	}
	printf("text len %d \n", len);

	int *aflag = (int *)malloc(C_MAX * sizeof(int));
	memset(aflag, 0, C_MAX * sizeof(int));
	for (i = 0; i < len; i++) {
		aflag[text[i] - 'a']++;
	}

	int *iflag = (int *)malloc(C_MAX * sizeof(int));
	memset(iflag, 0, C_MAX * sizeof(int));
	printf("alloc flag \n");

	int start = 0;
	int end = 1;
	int ans = 1;
	int ret;
	char temp;
	for (i = 0; i < len - 1; i++) {
		j = i + 1;
		if (text[i] == text[j] || aflag[text[i] - 'a'] >= 2 || aflag[text[j] - 'a'] >= 2) {
				ans = 2;
				break;
		}
	}
	if (ans == 1) {
		return ans;
	}
	printf("first i %d j %d ans %d \n", i, j, ans);

	iflag[text[0] - 'a']++;
	aflag[text[0] - 'a']--;
	iflag[text[1] - 'a']++;
	aflag[text[1] - 'a']--;
	for (i = 0; i < len; i++) {
		j = i + ans;
		while (1) {
			printf("loop i %d j %d \n", i, j);
			if (j >= len) {
				break;
			}
			iflag[text[j] - 'a']++;
			aflag[text[j] - 'a']--;
			ret = HowManyChar(iflag, &temp);
			if (ret == 1) {
				ans = j - i + 1;
				j++;
			} else if (ret == 2) {
				if (temp != 0 && aflag[temp - 'a'] >= 1) {
					ans = j - i + 1;
					j++;
				} else {
					break;
				}
			} else {
				break;
			}
		}
		iflag[text[i] - 'a']--;
		aflag[text[i] - 'a']++;
	}
	return ans;
}
```