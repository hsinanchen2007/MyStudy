![jieti.png](https://pic.leetcode-cn.com/e69344910399b972b3a465b8d3b75cb8e76f365a91b9630567bb918c5ea7287e-jieti.png)
思路：利用桶排序中桶的思想统计s中各个字母出现的次数，然后确定最长回文字符串长度
```
//ASCII：A-65 a-97
	int res = 0;
	int countChars[52] = {0};
	for (int i = 0; i < s.size(); ++i)
	{
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			++countChars[s[i] % 65];
		}
		else
		{
			++countChars[s[i] % 97 + 26];
		}
	}
	//如果字母出现的次数为偶数，则一定是回文串的组成部分
	//如果字母出现的次数是大于1的奇数，则取次数减一
	//加上一个只出现一次的字母 
	int flag = 1;
	for (int i = 0; i < 52; ++i)
	{
		if (countChars[i] == 0) continue;
		if (countChars[i] % 2 == 0)
		{
			res += countChars[i];
		}
		else
		{
			//统计第一次出现次数大于1的字母，因为aaa=aba，直接加，相当于直接把出现一次的那个字母一次性算上了
			if (flag == 1)
			{
				res += countChars[i];
				flag = 0;
			}
			else
			{
				//之后出现的所有奇数次字母次数减一直接加上去
				res += countChars[i] - 1;
			}
		}
	}
	return res;
```
