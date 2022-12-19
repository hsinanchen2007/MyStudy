### 解题思路
1. 首先，先将特殊情况筛选：当字符串为空串或字符串串长为1时直接返回该字符串；
2. 设置四个指针maxleft，maxright，curleft，curright分别表示最长回文子串的左右指针和当前回文子串的左右指针。
3. 从第二个字符开始遍历（第一个字符左边没有字符），初始化curleft = curright = i（i为字符串遍历指针）。
	- 第一步需要找到所有与当前字符相同的元素，并把curleft和curright移动到这些元素的两侧，因为i位置不一定为当前回文子串的中心，但这些相同元素可以共同构成回文子串的中心，即我们需要找到例如'caaaab'这种情况，在这种情况下将curleft，curright移动到0，4的位置，然后继续比较。**当然这种情况可能不存在，这时i就为回文字符串的中心位置**。
	- 然后，我们从curleft，curright所在的位置开始比较，若两个位置所在的元素相等，则两个指针都向两侧移动一个位置。
	- 在找到了当前最长的回文字符后，便比较当前回文字符与此时的最大回文字符那个长，让当前的比较大，则将curleft，curright赋值给maxleft，maxright。

4.最后创建一个动态数组将maxleft与maxright之间的字符存储下来并返回。 
### 代码

```c
char* longestPalindrome(char* s) {
	if (!(*s) || strlen(s) == 1)//字符串为空或字符串的长度为1直接返回原串
		return s;
	int maxleft, maxright,curleft,curright, i;
	char* out;
	maxleft = maxright = curleft = curright = 0;
	for (i = 1; s[i]; i++)
	{
		curleft = curright = i;
		while (curleft - 1 >= 0 && s[curleft - 1] == s[curleft])
		{
			curleft--;
		}
		while (s[curright + 1] && s[curright + 1] == s[curright])
		{
			curright++;
		}
		curleft--;
		curright++;
		while (curleft >= 0 && s[curright] && s[curleft] == s[curright])
		{
			curleft--;
			curright++;
		}
		curleft++;
		curright--;
		if ((curright - curleft) > (maxright - maxleft))
		{
			maxleft = curleft;
			maxright = curright;
		}
	}
	out = (char*)malloc(sizeof(char) * (maxright - maxleft + 2));
	for (i = maxleft; i <= maxright; i++)
		out[i - maxleft] = s[i];
	out[maxright - maxleft + 1] = '\0';
	return out;
}
```