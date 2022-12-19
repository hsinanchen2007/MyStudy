### 解题思路
串1在串2中找子排列（用例是重入的，注意代码的可重入性，入口清理全局变量）：
1. 窗口大小windowSize等于串1的长度（strlen(s1)）；
2. 窗口在串2中滑动：从第一个字符开始，判断窗口中元素与s1是否是（排列）相同的（封装成了函数）；
3. 窗口滑动到串2的结尾结束；
### 代码

```c
#define MAX_ALPHABET_LEN 26
int g_buf1[MAX_ALPHABET_LEN] = { 0 };
int g_buf2[MAX_ALPHABET_LEN] = { 0 };

bool checkEqual() {
	int i;
	for (i = 0; i < MAX_ALPHABET_LEN; i++) {
		if (g_buf1[i] != g_buf2[i]) {
			return false;
		}
	}
	return true;
}

bool checkInclusion(char * s1, char * s2){
	int i = 0, j = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int start = 0;
	int end = len1;

    for(i = 0; i < MAX_ALPHABET_LEN; i++) {
        g_buf1[i] = 0;
        g_buf2[i] = 0;
    }

	if (len1 > len2) {
		return false;
	}
	for (i = 0; i < len1; i++) {
		g_buf1[*(s1 + i) - 'a']++;
		g_buf2[*(s2 + i) - 'a']++;
	}
	if (checkEqual() == true) {
		return true;
	}
	start++;
	end++;
	while (end <= len2) {
		g_buf2[*(s2 + start - 1) - 'a']--;
		g_buf2[*(s2 + end - 1) - 'a']++;
		if (checkEqual() == true) {
			return true;
		}
		start++;
		end++;
	}
	return false;
}
```