### 解题思路
	回文串的组成是中间奇数两边偶数，这点不难想到，但是这中间的奇数不是说取最长的一个奇数其他舍弃就行了，题目中的意思是
	奇数的字母可以去一变成偶数，所以只需要计算奇数字符个数就行了。
	如果都是偶数字符的情况，直接返回字符长度
	如果存在奇数字符的情况，每个奇数字符减1就是偶数字符，再最后补一个字符即组成中间的奇数字符了，这样回文长度就是总长度减去奇数字符长度*1再加最后的那个1

### 代码

```c
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int longestPalindrome(char * s) {
	if (s == NULL) {
		return 0;
	}
	int alphaA[26] = { 0 };
	memset(alphaA, 0, sizeof(int) * 26);
	int alphaB[26] = { 0 };
	memset(alphaB, 0, sizeof(int) * 26);

	int odd = 0;
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			alphaA[s[i] - 'a']++;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			alphaB[s[i] - 'A']++;
		}
		else {
			// do nothing
		}
	}

	for (int i = 0; i < 26; ++i) {
		if (alphaA[i] != 0) {
			if (alphaA[i] % 2 != 0) {
				odd += 1;
			}
		}
		if (alphaB[i] != 0) {
			if (alphaB[i] % 2 != 0) {
				odd += 1;
			}
		}
	}
	return odd == 0 ? strlen(s) : strlen(s) - odd + 1;
}
```