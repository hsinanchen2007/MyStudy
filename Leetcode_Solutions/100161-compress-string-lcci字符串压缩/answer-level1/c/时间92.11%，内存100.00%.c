### 解题思路
做这道题对我来是真的忐忑，做了两个小时，分享一下我遇到的大坑
1.首先int型转化为char型 需要整型+48然后强制类型转换 
2.然后运行不对，原因就是没有初始化定义的压缩数组，于是全部初始为'0'，要养成初始化数组的好习惯  
3.结果仍然不对，上编译器调试，于是发现字符串末尾需要用'\0'截断，不然会出现乱码  
4.然后个数小于十的通过了，依然不对，原因就是因为还有个数是多位数的，数字的长度不仅仅是小于10，想了好久该怎样把大于十的整型放入字符串，于是我用了itoa函数，没想到出现编译错误，上网上查了一下是因为itoa是window特有的，于是改为了sprintf函数 
5.我想这下总该对了，错误，原因就是压缩后的字符串可能比50000还长，这个是一开始没有想到的，于是改成了500000
最终通过。 虽然很艰辛，但是真的学到了很多东西，我想也肯定有很多跟我一样的刚开始在leetcode刷题，这些希望能帮到你们
### 代码

```c
char* compressString(char* S)
{
	int i, len;
	int cnt = 1;
	int j = -1;
    char dealS[500000];
	memset(dealS, '0', 500000);

	char ch = S[0];
	for (i = 0; S[i]; i++);  //测量长度 其实可以用strlen
	len = i;
	if (len == 1)
	return S;
	for (i = 1; i < len+1; i++)  //len+1是为了防止还没等压缩就因为到了末尾而跳出遍历了了
	{
		if (ch == S[i])
		{
			cnt++;
		}
		else
		{
			dealS[++j] = ch;
			if (cnt < 10) //判断计数器大于还是小于0
			{
				dealS[++j] = (char)(cnt + 48);
			}
			else
			{
				char buffer[25];
				sprintf(buffer, "%d", cnt);
				for (int k = 0; buffer[k]; k++)
				{
					dealS[++j] = buffer[k];
				}
			}

			ch = S[i];
			i--;
			cnt = 0;
		}
	}

	dealS[++j] = '\0';
	return strlen(dealS) < strlen(S) ? dealS : S;
}
```