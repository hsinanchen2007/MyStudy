### 解题思路
要考虑到只有一个字符的情况，所以我单独计算了字符的个数。
判断大写方式的对错其实只与前两个字符有关，所以就设置两个标志first和second来表示第一个和第二个字符的大小写情况。
然后根据四种不同情况遍历第三个直至最后一个元素，看是否符合大写规则。
注意在返回类型为bool的函数中，所有情况都要返回一个值。

写几个我在编写函数时犯的智障错误吧（笑）
四种情况在遍历的时候我把起始字符写成了word[0]
我只给我写到的几种情况给了返回值，最后那个else是后加的，要不就显示编译错误。（学习了学习了）

### 代码

```c
bool detectCapitalUse(char * word){
int len = 0;
	for (len; word[len] != '\0'; len++)
		;
	//len是字符的个数
	if (len == 1)
		return 1;
	int first, second;
	if (word[0] <= 'Z' && word[0] >= 'A')
		first = 1;
	else
		first = 0;
	if (word[1] <= 'Z' && word[1] >= 'A')
		second = 1;
	else
		second = 0;

	if (first == 1 && second == 1)
	{
		for (int i = 2; i < len; i++)
		{
			if (word[i] <= 'Z' && word[i] >= 'A')
				;
			else
				return 0;
		}
		return 1;
	}

	else if (first == 1 && second == 0)
	{
		for (int i = 2; i < len; i++)
		{
			if (word[i] <= 'Z' && word[i] >= 'A')
				return 0;
			else
				;
		}
		return 1;
	}

	else if (first == 0 && second == 0)
	{
		for (int i = 2; i < len; i++)
		{
			if (word[i] <= 'Z' && word[i] >= 'A')
				return 0;
			else
				;
		}
		return 1;
	}
	else if (first == 0 && second == 1)
		return 0;
	else
		return 0;
}
```