### 解题思路
执行时间1280ms，哎~

先判断是不是返回0的情况，然后计算需要找的字符长度，后面判断用；
然后在原字符串依次向后，碰到想要同的字符就开始检测，看看会不会所有的一样；
最后返回，如果没有找到的话就返回-1。

### 代码

```c
int strStr(char * haystack, char * needle){
	if( needle[0] == 0)
		return 0;
	int ret = 0;
	int length = 0;
	while( *(needle + length) )	length++;	//获取needle的长度，后面判断用
	
	while( *haystack ) {
		//putchar(*haystack);
		if(*haystack == *needle)	{		//发现了相同的字符
			int i = 0;
			while( *(haystack+i) == *(needle+i) ){
				i++;
				if(i == length)
					return ret;
			}
		}
		ret++;
		haystack++;
	}
	return -1;
}
```