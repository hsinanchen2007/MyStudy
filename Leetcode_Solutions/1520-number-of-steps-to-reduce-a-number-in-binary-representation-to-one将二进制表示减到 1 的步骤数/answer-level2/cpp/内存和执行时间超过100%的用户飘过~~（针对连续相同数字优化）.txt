内存和执行时间超过100%的用户飘过~~
主要思想跟大家差不多，有个细节需要注意，当连续为0或者1时，循环中加if判断会影响效率。时间复杂度看起来是O(n2),其实是O(n)。
代码如下
```
class Solution {
public:
	int numSteps(string s) {
		int strLen = s.length();
		if (strLen <= 1)
		{
			return 0;
		}
		int nCnt = 0;
		int i = strLen-1;
		while(true)
		{
			int j = i;
			if (s[i] == '1')
			{
				while (j >= 0 && s[j] == '1')	//连续为1的
				{
					s[j] = '0';
					--j;
				}
				nCnt += i-j + 1;	//奇数+1，偶数下标忘左移i-j位
				if (j < 0)
				{
					break;
				}
				s[j] = '1';
			}
			else
			{
				while (j >= 0 && s[j] == '0')	//连续为0的
				{
					--j;
				}
				nCnt += i-j;
			}
			if (j == 0)
			{
				break;
			}
			i = j;
		}
		return nCnt;
	}
};
```

