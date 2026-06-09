**算法时间与空间复杂度:**
>时间复杂度：O(n)
>空间复杂度:O(1)

**实现步骤:**
先研究字符串"hello world"，如果我们要把前3个字符旋转，即变为"lo worldhel"
我们可以通过如下步骤实现:
>1.以n为界限（该案例为3）,把主串分成2个子串:
>"hel"和"lo world"
>2.将2个子串逆序:
>主串变为"leh"+"dlrow ol" = "lehdlrow ol"
>3.间主串整体逆序
>"lo worldhel"
>4.函数调用返回

将上述例子推而广之，可得算法.一下展示C语言题解，欢迎评论区补充其他语言。
```c
//将串s中前len个字符串逆序
void reverseStr(char* str, int len)
{
	if (!str || len == 1 || len == 0)
		return;

	//整体字符逆序
	char* head = str;
	char* tail = str + len - 1;
	while (head < tail)
	{
		*head = *head - *tail;
		*tail = *head + *tail;
		*head = *tail - *head;
		++head, --tail;
	}
}

char* reverseLeftWords(char* s, int n) {
	int len = strlen(s);
	if (!s || len == 0 || len == 1 || n >= len)
		return 0;
	reverseStr(s, n);
	reverseStr(s + n, len - n);
	reverseStr(s, len);

	return s;
}


```
