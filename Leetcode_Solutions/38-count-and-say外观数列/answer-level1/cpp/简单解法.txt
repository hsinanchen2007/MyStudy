![微信图片_20200331170007.png](https://pic.leetcode-cn.com/bd059cf8e7ccccbe902ac8c03f5dc5d942b2d4b9f5926d18c1d451c2b16a5638-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200331170007.png)
```
class Solution {
public:
    string countAndSay(int n) 
    {
		if (n == 1)
		{
			return "1";
		}
		else
		{
			string *result = new string[n];
			result[0] = "1";
			result[1] = "11";
			if (n > 2)
			{
				for (size_t i = 2; i < n; i++)
				{
					int j = 1;
					while (j <= result[i - 1].size())
					{
						int sameNum = 1;
						while (result[i - 1][j] == result[i - 1][j - 1])
						{
							sameNum++;
							j++;
						}
						result[i].push_back(sameNum + '0');
						result[i].push_back(result[i - 1][j - 1]);
						if (result[i - 1][j] != result[i - 1][j - 1])
						{
							j++;
						}
					}
				}
			}
			string tmp = result[n - 1];
			delete[] result;
			return tmp;
        }
    }
};
```
