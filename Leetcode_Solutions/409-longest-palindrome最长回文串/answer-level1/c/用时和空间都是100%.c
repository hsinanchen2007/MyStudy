### 解题思路
前几天做了那个单词的题，用的哈希表，这个还是用哈希表，用定义一个hash数组来存储小写和大写字母，然后遍历hash数组，遇到偶数直接计入回文串长度，遇到奇数再存入一个tem数组记录，最后比较tem数组中最大长度的奇数串
计入回文串长度，还有一个最重要的就是，**其余的长度的奇数串不能都舍去，需要减一计入回文串长度。**
### 代码

```c
int longestPalindrome(char* s)
{
	int hash[52] = { 0 };
	int tem[1000] = { 0 };  //用来记录奇数最大数值
	int cnt = 0;
	int i, j = -1;

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			hash[s[i] - 97]++;
		}
		else
		{
			hash[s[i] - 39]++;
		}
	}

	for (i = 0; i < 52; i++)
	{
		if (hash[i] % 2 == 0)
		{
			cnt += hash[i];
		}
		else if (hash[i] % 2 != 0) // 记录非偶数
		{
			tem[++j] = hash[i];
		}
	}

	int max;
	int symbol; //记录最长计数串的下标
	max = tem[0];  //最长的奇数串
	symbol = 0;
	for (i = 1; i < j+1; i++)
	{
		if (tem[i] > max)
		{
			max = tem[i];
			symbol = i;
		}
	}

	//printf("%d", symbol);
	for (i = 0; i < j + 1; i++)
	{
		if (i != symbol)
		{
			cnt = cnt + tem[i] - 1;
		}
	}
	return cnt + max;
}
```