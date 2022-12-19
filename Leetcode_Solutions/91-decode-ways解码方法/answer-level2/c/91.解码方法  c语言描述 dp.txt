### 解题思路
思路很简单：dp实现译码
用sum数组记录解码的可能情况数
如果当前字符s[i]可以与s[i-1]可以组成译码，则情况数sum[i]=sum[i-1]+[i-2]
如果s[i]与s[i-1]无法组成译码，则情况数不变 sum[i]=sum[i-1]

用了很多if else来讨论
代码有点丑 大家见谅hhhhhh

![微信图片_20200204220242.png](https://pic.leetcode-cn.com/77452beb5db70d458c4274010c72dd128ab59ac17db3eda10f90ca2dd20c5abc-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200204220242.png)


### 代码

```c
int numDecodings(char* s) {
	if (strlen(s) <= 1)
	{
		if (s[0] == '0')
			return 0;
		else return strlen(s);
	}
	else
	{
		int len = strlen(s);
		int sum[5000] = { 0 };
		
		if (s[0] == '0')//0和1列出来单独讨论
			return 0;
		else sum[0] = 1;

		if (s[1] == '0')
			if (s[0] <= '2' && s[0] > '0')
				sum[1] = sum[0];
			else return 0;
		else if ('0' < s[0] && s[0] < '2')
			sum[1] = sum[0] + 1;
		else if (s[1] <= '6' && s[0] == '2')
			sum[1] = sum[0] + 1;
		else sum[1] = sum[0];

		for (int i = 2; i < len; i++)
		{
			if (s[i] == '0')
				if (s[i - 1] <= '2' && s[i - 1] > '0')
					sum[i] = sum[i - 2];
				else return 0;
			else if ('0'<s[i-1] &&s[i-1]<'2')
				sum[i] = sum[i-1] + sum[i-2];
			else if (s[i] <= '6'&& s[i - 1] == '2')
				sum[i] = sum[i - 1] + sum[i - 2];
			else sum[i] = sum[i-1];
		}
		return sum[len-1];
	}

}
```