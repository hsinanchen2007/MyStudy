### 解题思路
题不难，但是如何判断 当前窗内字符串覆盖字符串T 需要好好想一想，一开始通过匹配每种字符的个数和字符串的长度，来判断是否覆盖字符串T，总是超时。

### 代码

```c
char * minWindow(char * s, char * t) {
	// 记录最短子串的开始位置和长度
	int minLen = INT_MAX;
	int* left  = NULL;
    int* right = NULL;
    int start = 0;
	int i;
	int lenS = strlen(s);
	int lenT = strlen(t);
	int lenNeeds = 0; // 记录字符串T中字符的种类数
	int lenTmp = 0;
	int window[128];
	int mapT[128]; // 记录字符串T中不同字符的个数
    int* idxBuff = (int *)calloc(sizeof(int), lenS);
    int idxBuffLen = 0;

	memset(window, 0, sizeof(int) * 128);
	memset(mapT, 0, sizeof(int) * 128);

	for (i = 0; i < lenT; i++) {
		if (mapT[t[i]] == 0) {
			lenNeeds++;
		}
		mapT[t[i]]++;
	}

    for (i = 0; i < lenS; i++) {
        if (mapT[s[i]]) {
            idxBuff[idxBuffLen] = i;
            idxBuffLen++;
        }
    }

    left  = idxBuff;
    right = idxBuff;
    //printf("idxBuffLen:%d\n", idxBuffLen);
	for (i = 0; (i < idxBuffLen) && (s[*right] != '\0'); i++, right++) {
        //printf("left:%d, right%d\n", *left, *right);
		char c1 = s[*right];

        window[c1]++;
        if (window[c1] == mapT[c1]) { // 当同类字符的个数相等的时候，match++
            lenTmp++;
        }

        //printf("lenTmp:%d, lenNeeds:%d\n", lenTmp, lenNeeds);
		while ((lenTmp == lenNeeds) && (s[*left] != '\0')) {
            /* 窗口内的字符可以覆盖字符串T */
			if (*right - *left + 1 < minLen) {
				// 更新最小子串的位置和长度
				start = *left;
				minLen = *right - *left + 1;
			}

			char c2 = s[*left];
            window[c2]--;
            if (window[c2] < mapT[c2]){
                lenTmp--;
            }
			left++;
		}
	}

	if (minLen == INT_MAX) {
		return "";
	}
	else {
		s[start + minLen] = '\0';
		return s + start;
	}
}
```