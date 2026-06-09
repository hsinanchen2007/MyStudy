### 解题思路
设置双指针`i`和`j`,从后往前赋值
注意：本题中`length`是字符串的长度，因此算好最后一个字符的起始位置，也就是`j`的位置

### 代码

```c
char* replaceSpaces(char* S, int length){
	int cntOfSpace = 0;
	for (int i = 0; i < length; i++)
	{
		if (S[i] == ' ')cntOfSpace++;
	}
	//printf("%d", cntOfSpace);
	int j = length + 2 * cntOfSpace;
	S[j] = '\0';
	for (int i = length; i > 0;)
	{
		if (S[--i] == ' ')
		{
			S[--j] = '0';
			S[--j] = '2';
			S[--j] = '%';
		}
		else
		{
			S[--j] = S[i];
		}
	}
	return S;  
}
```
![无标题.png](https://pic.leetcode-cn.com/7932765e0630eb5b8a14fb0c036abdeb257ecbe6d5dcc95e3c0b96ad059b76ab-%E6%97%A0%E6%A0%87%E9%A2%98.png)

