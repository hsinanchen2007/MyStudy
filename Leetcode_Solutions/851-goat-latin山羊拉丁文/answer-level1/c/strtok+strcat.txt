### 解题思路
strtok+strcat，元音判断用个小技巧，减少圈复杂度

### 代码

```c

#define GetIndex(s) (((s) >= 'a') ? ((s) - 'a') : ((s) - 'A'))

char * toGoatLatin(char * S) {
	char *p=NULL;
	char *result=NULL;
	char *maa = "maa";
	int wordNum = 0;
	int index = 0;
	int i,wordLen;

	if (S == NULL) {
		return NULL;
	}

	result = (char*)malloc(2000);
    memset(result, 0, 2000);
	p = strtok(S," ");

	while (p) {
		wordNum++;
		wordLen = strlen(p);

		if ((1 << GetIndex(p[0])) & 0x104111) {
			memcpy(&result[index], p, wordLen);
			strcat(&result[index], maa);		
		} else {
			memcpy(&result[index], p+1, wordLen-1);
			result[index + wordLen - 1] = p[0];
			strcat(&result[index], maa);
		}

		index += (wordLen + 3); //3=maa

		for (i = 0; i < wordNum-1; i++) {
			result[index++] = 'a';
		}

		result[index++] = ' ';
		p = strtok(NULL," ");
	}

	result[index-1] = 0;

	return result;
}
```