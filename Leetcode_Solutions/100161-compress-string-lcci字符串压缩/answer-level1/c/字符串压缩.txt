### 解题思路
1. 字符串下标j-1 与 j比较，相同cnt+1;
2. 不相同将记录j-1，并且输出计数；
3. 用sprintf实现数字转字符串
注意：当字符串长度为1时，直接返回，否则会出现访问越界。
### 代码

```c
char* compressString(char* S){
	int len = strlen(S);
	char* res = (char*)malloc(sizeof(char) * len * 2);
	int res_len = 0;
	int count = 1, j = 1;
	char str[25] = {0};
    if (len == 1) { //异常场景1
        return S;
    }
	for(int i = 0; i < len; i++) {
		if(S[j - 1] == S[j]) {
			count++;
		} else {
			res[res_len++] = S[j-1];
			sprintf(str, "%d", count);
			count = 1;
			strcpy(res + res_len, str);
			res_len += strlen(str);
			memset(str, 0, 25);
		}
		j++;		
	}
	if(res_len < len) {
		return res;
	} else {
        free(res);
        res = NULL;
		return S;
	}
}
```