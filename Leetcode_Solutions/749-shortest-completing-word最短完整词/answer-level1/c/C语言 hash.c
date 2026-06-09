### 解题思路
只有一点要注意，word包含的单个字母的个数可以大于或等于字典里这个字母的个数
![image.png](https://pic.leetcode-cn.com/2784af728452a09ee9875971a8e27b0a8acb0c806e3a43a397bed0357cb68f89-image.png)

### 代码

```c
#define MAX_HASH 26
void getHash(char *licensePlate, int *hash, int size)
{
	char cur;
	while(*licensePlate != '\0') {
		if ((*licensePlate >= 'a' && *licensePlate <= 'z') ||
		    (*licensePlate >= 'A' && *licensePlate <= 'Z')) {
			cur = tolower(*licensePlate);
			hash[cur - 'a']++;
		}
		licensePlate++;
	}
	return;
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
	int i, j;
	int flag;
	int len;
	int minLen = INT_MAX;
	char *word = NULL;
	int hash[MAX_HASH] = { 0 };
	int curHash[MAX_HASH] = { 0 };
	getHash(licensePlate, &hash[0], MAX_HASH);
	for (i = 0; i < wordsSize; i++) {
		memset(curHash, 0x00, sizeof(curHash));
		getHash(words[i], &curHash[0], MAX_HASH);
		flag = 0;
		for (j = 0; j < MAX_HASH; j++) {
			/* 这个curHash[j] < hash[j]要注意，不能写成curHash[j] != hash[j] */
			if (hash[j] != 0 && curHash[j] < hash[j]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			len = strlen(words[i]);
			if (len < minLen) {
				minLen = len;
				word = words[i];
			}
		}
	}
	return word;
}
```