### 解题思路
1、若字符在栈中已存在，则不进行操作，若不存在则入栈
1、若栈顶的字符在后续有相同字符，且新字符的字典序更高，则栈顶字符出栈。
bcabc
1、b入栈
2、c入栈
3、a入栈，由于后续仍存在c/b，c/b出栈
4、b入栈
5、c出栈

### 代码

```c
#define WORD_NUM 26



char* removeDuplicateLetters(char* s) {
	int temp;
	int wordCnt[WORD_NUM] = { 0 };
	int stackFlag[WORD_NUM] = { 0 };
    int stack[WORD_NUM] = { 0 };
    int stackIndex = 0;
	char* ret = (char*)malloc(sizeof(char) * (WORD_NUM + 1));
	memset(ret, 0, (WORD_NUM + 1));

	// 1. 记录个字母出现的次数
	for (int i = 0; i < strlen(s); i++) {
		temp = s[i] - 'a';
		wordCnt[temp]++;
	}

	// 2. 遍历字符串
	for (int i = 0; i < strlen(s); i++) {
		temp = s[i] - 'a';
		// 字符在栈中不存在直接入栈
		if (stackFlag[temp] == 0) {
			// 若栈顶小于新字符且栈顶后续仍存在则出栈
            while (stackIndex > 0 && temp < stack[stackIndex - 1] && wordCnt[stack[stackIndex - 1]] > 0){
                stackIndex--;
                stackFlag[stack[stackIndex]] = 0;
            }
            stack[stackIndex++] = temp;
            stackFlag[temp] = 1;
		}
        wordCnt[temp]--;
	}
    
	for (int i = 0; i < stackIndex; i++) {
		ret[i] = stack[i] + 'a';
	}
	ret[stackIndex] = '\0';

	return ret;
}
```