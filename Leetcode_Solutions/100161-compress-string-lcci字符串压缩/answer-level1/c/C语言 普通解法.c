### 解题思路
题目思路很简单，直接轮询一遍把相同的元素count值记录下 输出到返回的字符串里就行了
但是要注意2点：
1、C语言里面数字转字符串用snprintf
2、题目声明了字符串是在[0,50000]之间，但是输出字符串是很有可能比这个长度要高的，避免堆栈溢出或者计算时间长，中间可加一步判断，大于原有len的值就直接return S，不用到最后在返回。

### 代码

```c
#include <stdlib.h>

#define MAX_STR_LEN 50000

char* compressString(char* S) {
	if (S == NULL) {
		return S;
	}
	int len = strlen(S);
	if (len <= 0 || len > MAX_STR_LEN) {
		return S;
	}
	char* outS = (char*)malloc(sizeof(char) * (MAX_STR_LEN + 1));
	memset(outS, 0, sizeof(char) * (MAX_STR_LEN + 1));
	char countStr[6];
	int idx = 0;
	int count = 1;
	for (int i = 0; i < len; ++i) {
		if (i + 1 < len && S[i] == S[i + 1]) {
			count++;
		}
		else {
			outS[idx++] = S[i];
			snprintf(countStr, 6, "%d", count);
            strncpy(outS + idx, countStr, strlen(countStr) + 1);
            idx += strlen(countStr);
            if (idx >= len) {
		        return S;
	        }
			count = 1;
		}
	}
	if (idx >= len) {
		return S;
	}
	else {
		return outS;
	}
}
```