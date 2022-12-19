### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/bf06e242556800849b3875bc75b8b702059e433eb2c688a68808ca5321798dce-image.png)

### 代码

```c
int cmp(char* str1, char* str2){
	if (*str1 == '\0' || *str2 == '\0')
		return 1;
	while(*str1 != '\0' && *str2 != '\0' && *str1++ == *str2++);    //进行字符串比对
	return (*str2 == '\0' && *(--str2) == *(--str1)) ? 0 : 1;    //如果str2 == '\0' 说明遍历到了最后一个字符之前都是相等的，但不确定最后一个字符是否相等，所以还需比对最后一个字符。	
}

int strStr(char * haystack, char * needle){

	int len1 = strlen(haystack), len2 = strlen(needle);
	
	if(!len2)
		return 0;
	
	if(len1 < len2)
		return -1;

	for(int index = 0; *(haystack + len2 - 1) != '\0'; index++, haystack++)
		if (*haystack == *needle)    //判断第一个字符是否相等，相等就进一步进行判定
			if(0 == cmp(haystack, needle))
				return index;

	return -1;

}
```