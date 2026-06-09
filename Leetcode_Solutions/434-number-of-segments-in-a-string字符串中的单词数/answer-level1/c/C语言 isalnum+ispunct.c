### 解题思路
算法方面关注 i <= len里面的等号，这个很关键
题目里没说明白单词的组成元素
开始以为只有字母，后来发现标点也算，再后来发现数字也算...
![image.png](https://pic.leetcode-cn.com/26ec9e2f1e9f672117dd0b66be28f9ea7c1d0e7b7ae4a1ba9d606fe2b733c2bb-image.png)

### 代码

```c
int countSegments(char * s){
	int i;
	int cnt;
	int len;
	int wordLen = 0;
	len = strlen(s);
	for (i = 0, cnt = 0; i <= len; i++) {
		if (isalnum(s[i]) != 0 || ispunct(s[i]) != 0) {
			wordLen++;
			continue;
		}
		if (wordLen > 0) {
			cnt++;
			wordLen = 0;
		}
	}
	return cnt;
}
```