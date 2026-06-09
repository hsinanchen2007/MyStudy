### 解题思路
C语言普通做法，首先先求两个字符串长度的最大公约数，公共子串的长度必定是这个最大公约数长度。
然后就好办了，任选一个字符串求出strncpy出公共子串，然后将两个母串迭代比较公共子串，如果出现不匹配则返回失败

### 代码

```c
#include <stdlib.h>
#include <stdbool.h>

#define min(x,y) (x>y?(y):(x))

bool checkIsValid(char *str1, char *str2, int gcdLen) {
	char *outStr = (char*)malloc(sizeof(char) * (gcdLen + 1));
	strncpy(outStr, str1, gcdLen);
    outStr[gcdLen] = '\0';
	for (int i = 0; i < strlen(str1); i = i + gcdLen) {
		if (0 != strncmp(str1 + i, outStr, gcdLen)) {
            free(outStr);
			return false;
		}
	}
    for (int i = 0; i < strlen(str2); i = i + gcdLen) {
		if (0 != strncmp(str2 + i, outStr, gcdLen)) {
            free(outStr);
			return false;
		}
	}
    free(outStr);
	return true;
}

char * gcdOfStrings(char * str1, char * str2) {
	if (str1 == NULL || str2 == NULL || strlen(str1) == 0 || strlen(str2) == 0) {
		return "";
	}
	int minLen = min(strlen(str1), strlen(str2));
	int gcdLen = 0;
	for (int i = minLen; i >= 2; --i) {
		if (strlen(str1) % i == 0 && strlen(str2) % i == 0) {
			gcdLen = i;
			break;
		}
	}
    if (gcdLen == 0){
        return "";
    }
    
	if (true == checkIsValid(str1, str2, gcdLen)) {
		char *outStr = (char*)malloc(sizeof(char) * (gcdLen + 1));
		strncpy(outStr, str1, gcdLen);
        outStr[gcdLen] = '\0';
		return outStr;
	}else{
        return "";
    }
}
```