### 解题思路
一个指针指向头，一个指向尾，头<=尾的时候相向迭代。

注意 1 输入的指针可能为空 2 输入指针指向的字符串可能为空 3 只比较字母、数字
### 代码

```c
bool isPalindrome(char * s) {
	//输入为空的时候
	if (s==0||*s == '\0')
		return true;
	//头指针和尾指针
	char* low = s;
	char* high = s;
	while (*high != '\0')
	{	
		//尾指针定位到末尾的过程中，把字母统一成小写
		if ('A' <= *high&&*high <= 'Z')
			*high += ('a' - 'A');
		++high;
	}
	//相向迭代如果二者都是 字母或者数字 比较
	while (low <= high) 
	{
		if (!(('a' <= *low&&*low <= 'z') || ('0' <= *low&&*low <= '9')))
		{
			++low;
			continue;
		}
		if (!(('a' <= *high&&*high <= 'z') || ('0' <= *high&&*high <= '9')))
		{
			--high;
			continue;
		}
		if (*low != *high)
			return false;
		++low; -- high;
	}
	return true;
}
```