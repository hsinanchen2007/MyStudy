### 解题思路
从左往右查找

### 代码
![图片.png](https://pic.leetcode-cn.com/e596cef0903c0743007464029f47976999996768907eb2cb33aa914cb18fafd0-%E5%9B%BE%E7%89%87.png)

```c
char * longestCommonPrefix(char ** strs, int strsSize){
	int i, j;
	int len = 0x7fffffff;
	for (j = 0; j < strsSize; j++){
		len = min(strlen(strs[j]), len);
	}
    if(strsSize == 0){
        return "";
    }
	char *str = (char *)malloc((len+1)*sizeof(char));
    memset(str, 0, len+1);
	for (i = 0;i < len; i++){
		char tmp = strs[0][i];
		for (j = 0; j < strsSize; j++){
			if (tmp != strs[j][i]){
				return str;
			}
		}
		str[i] = tmp;
	}
    return str;
}

int min(int a, int b) {
	return a<b ? a : b;
}
```