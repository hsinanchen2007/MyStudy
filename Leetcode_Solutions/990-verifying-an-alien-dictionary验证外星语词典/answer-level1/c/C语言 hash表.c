### 解题思路
有点儿绕，关键要理清两个字符的比较规则
从左向右比较
1、如果word1当前字符小于word2当前字符，直接返回true
2、如果word1当前字符等于word2当前字符，继续比较
3、如果word1当前字符大于word2当前字符，直接返回false
如果经过上面的比较，发现word1短于word2，返回false
都不是上面的情况，返回true

![image.png](https://pic.leetcode-cn.com/59f36a820cfea04db1e5bfd0adb4630ebabfbe70247439695c4642538f6b6521-image.png)


### 代码

```c
#define MAP_CNT 26
#define INX(ch) ((ch) - 'a')
bool cmp(char *w1, char *w2, int hash[MAP_CNT]) {
	while (*w1 != '\0' && *w2 != '\0') {
		/* 关键在这行，如果当前小于，直接反true */
		if (hash[INX(*w1)] < hash[INX(*w2)]) { 
			return true;
		}
		if (hash[INX(*w1)] > hash[INX(*w2)]) {
			return false;
		}
		w1++;
		w2++;
	}
	if (*w1 != '\0') {
		return false;
	}
	return true;
}
bool isAlienSorted(char ** words, int wordsSize, char * order){
	int i;
	int hash[MAP_CNT] = { 0 };
	bool rlt = true;
	for (i = 0; i < MAP_CNT; i++) {
		hash[INX(order[i])] = i;
	}
	for (i = 0; i < wordsSize - 1; i++) {
		rlt = rlt && cmp(words[i], words[i+1], hash);
		if (rlt != true) {
			return false;
		}
	}
	
    return true;
}
```