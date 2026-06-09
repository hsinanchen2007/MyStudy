![image.png](https://pic.leetcode-cn.com/772a3d0a6316cf593b1765c1d6d7bf18c43efb98b773ee294216afaa90d3777c-image.png)

1. 找出最短字符串，并分配一个数组存储返回结果，长度为最小字符串的长度。
2. 从第一个字符串的第一个字符开始遍历，与剩余字符串的字符对比，如果有不同的，则查找结束，如果相同，则保存入返回结果。

```
char * longestCommonPrefix(char ** strs, int strsSize){
	if (strsSize == 0) return "";
	if (strsSize == 1) return strs[0];
	
	int minSize = strlen(strs[0]);
	int i;
	int tmpLen;
	for (i = 1; i < strsSize; i++) {
		tmpLen = strlen(strs[0]);
		if (tmpLen < minSize) {
			minSize = tmpLen;
		}
	}
	if (minSize == 0) return "";
	char *res = malloc(minSize + 1);
	memset(res, 0, minSize + 1);
	int br = 0;
	for (i = 0; i < minSize; i++) {
		int j;
		for (j = 1; j < strsSize; j++) {
			if (strs[0][i] != strs[j][i]) {
				br = 1;
				break;
			}
		}
		if (br) {
			break;
		}
		res[i] = strs[0][i];
	}
	return res;
}
```

