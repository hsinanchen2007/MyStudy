```
class Solution {
public:
    string longestPalindrome(string s) {
	static string data;
	int index(0), maxlen(0),templen(0);
    	const int length=s.size();
	int j;
	for (int i = 0; i < length; i++)
	{
		templen = 0;
		for (j = 1; j < i+1 && i + j < length; ++j)
		{
			if (s[i - j] == s[i + j])
				templen++;
			else
				break;
		}
		if (maxlen < 2 * templen + 1)
		{
			maxlen = 2 * templen + 1;
			index = i - templen;
		}
	}
    for (int i = 0; i < length; i++)
	{
		templen = 0;
		for (j = 0; j <= i && i + j + 1 < length; j++)
		{
			if (s[i - j] == s[i + j+1])
				templen++;
			else
				break;
		}
		if (maxlen < 2 * templen)
		{
			maxlen = 2 * templen;
			index = i - templen+1;
		}
	}
	data.assign(s, index, maxlen);
	return data;
    }
};
```
对于每个字符向两个方向扩展比较，寻找对于每个字符串的最长回文子串；并一直更新最长的字串信息。奇数和偶数字串分开考虑，哪个大取哪个。
事实上，只需使用恒定的空间，我们就可以在 O(n^2)O(n 
2
 ) 的时间内解决这个问题。

我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有 2n - 12n−1 个这样的中心。

你可能会问，为什么会是 2n - 12n−1 个，而不是 nn 个中心？原因在于所含字母数为偶数的回文的中心可以处于两字母之间（例如 \textrm{“abba”}“abba” 的中心在两个 \textrm{‘b’}‘b’ 之间）。



