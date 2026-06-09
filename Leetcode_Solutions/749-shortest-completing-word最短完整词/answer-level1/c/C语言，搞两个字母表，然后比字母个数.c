搞两个字母表，一个放license的，一个放words。
统计每个字母出现的个数，然后比较两个字母表，取最短的单词。
```
typedef struct {
	char* string;
	int len;
}Result;

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize) {
	int status = 0;
	int length = 0;
	int array[26] = { 0 };
	int arrayTmp[26] = { 0 };
	Result result[1] = { 0 };
	result[0].len = 99999;

	for (int i = 0; i < strlen(licensePlate); i++) {
		if ('a' <= licensePlate[i] && licensePlate[i] <= 'z') {
			array[licensePlate[i] - 'a'] += 1;
		}
		if ('A' <= licensePlate[i] && licensePlate[i] <= 'Z') {
			array[licensePlate[i] + 32 - 'a'] += 1;
		}
	}

	for (int k = 0; k < wordsSize; k++) {
		for (int l = 0; l < 26; l++) {
			arrayTmp[l] = 0;
		}
		length = 0;
		status = 0;
		
		for (int m = 0; m < strlen(words[k]); m++) {
			arrayTmp[*(words[k] + m) - 'a'] += 1;
		}

		for (int n = 0; n < 26; n++) {
			if (array[n] == 0) {
				continue;
			}
			length++;
			if (arrayTmp[n] >= array[n]) {
				status++;
			}
		}

		if (status >= length) {
			if (result[0].len > strlen(words[k])) {
				result[0].string = words[k];
				result[0].len = strlen(words[k]);
			}
		}
	}
	return result[0].string;
}
```
