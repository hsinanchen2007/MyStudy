### 解题思路
此处撰写解题思路

### 代码

```c
int FindAllWord(int *sp, char *words)
{
	int i;
	int len = strlen(words);
	int *flag = (int *)malloc(26 * sizeof(int));
	memset(flag, 0, 26 * sizeof(int));

	char temp;
	for (i = 0; i < len; i++) {
		temp = words[i];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp - 'a';
			flag[temp]++;
			//printf("word %c temp %d flag %d \n", words[i], temp, flag[temp]);
		}
		if (temp >= 'A' && temp <= 'Z') {
			temp = temp - 'A';
			flag[temp]++;
			//printf("word %c temp %d flag %d \n", words[i], temp, flag[temp]);
		}
	}
	for (i = 0; i < 26; i++) {
		if (sp[i] != 0 && sp[i] <= flag[i]) {
			continue;
		} else if (sp[i] == 0) {
			continue;
		} else {
			return -1;
		}
	}
	return 0;
}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
	int i;
	int *sp = (int *)malloc(26 * sizeof(int));
	memset(sp, 0, 26 * sizeof(int));

	int temp;
	int len = strlen(licensePlate);
	for (i = 0; i < len; i++) {
		if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
			temp = licensePlate[i] - 'a';
			sp[temp]++;
			//printf("license %c temp %d sp %d \n", licensePlate[i], temp, sp[temp]);
		}
		if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') {
			temp = licensePlate[i] - 'A';
			sp[temp]++;
			//printf("license %c temp %d sp %d \n", licensePlate[i], temp, sp[temp]);
		}
	}

	char *ret = (char *)malloc(16 * sizeof(char));
	memset(ret, 0, 16 * sizeof(char));

	int shortest = 0xFFFF;
	int wCnt;
	for (i = 0; i < wordsSize; i++) {
		wCnt = FindAllWord(sp, words[i]);
		if (wCnt == -1) {
			continue;
		}
		len = strlen(words[i]);
		if (len < shortest) {
			shortest = len;
			memset(ret, 0, 16 * sizeof(char));
			memcpy(ret, words[i], len);
		}
	}
	return ret;
}
```