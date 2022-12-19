### 解题思路
执行用时 : 0 ms , 在所有 C 提交中击败了 100.00% 的用户 内存消耗 : 7.1 MB , 在所有 C 提交中击败了 85.21% 的用户

### 代码

```c
int strStr(char * haystack, char * needle){

    int num = 0;
	char *dst = haystack;
	char *src = needle;
	
	if(*needle == '\0')
		return 0;
	while(*dst != '\0')
	{
		if(*src != *dst && src == needle){
			dst++;
			num++;
		}
		else if(*src != *dst && src != needle){
			num++;
			dst = haystack + num;
			src = needle;
		}
		else if(*src == *dst){
			src++;
			dst++;
		}
		if(*src == '\0')
			return num;
	}
	return -1;
}
```