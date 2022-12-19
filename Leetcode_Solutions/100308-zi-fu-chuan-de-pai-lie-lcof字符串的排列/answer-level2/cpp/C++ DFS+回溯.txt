### 解题思路
第一步求所有可能出现在第一个位置的字符，即把第一个字符和后面的所有字符交换。
第二步固定第一个字符，求后面所有字符的排列。
这时候仍然把后面的所有字符分成两部分：后面字符的第一个字符，以及这个字符之后的所有字符。然后把第一个字符逐一和它后面的字符交换。
举例如下
以字符串"abc"为例
![image.png](https://pic.leetcode-cn.com/b306e3bfce106522f0ef9683d424fd78444c1ee2e0689d27f23b188cd74e6f36-image.png)


### 代码

```cpp
class Solution {
public:

	vector<string> res;
	set<string> tempRes;
	vector<string> permutation(string s) {
		if (s.size() == 0) return res;//字符串排列
		solvePermutation(s, &s[0]);
		for (set<string>::iterator it=tempRes.begin();it!=tempRes.end();it++)
		{
			res.push_back(*it);
		}
		return res;
	}
	void solvePermutation(string& s, char* sBegin)
	{
		//sBegin所指字符为空'\0'，将当前字符串s存储起来
		if (*sBegin == '\0') tempRes.insert(s);
		else
		{
			//将字符串s中的字符从sBegin位置开始依次和当前字符串的首字符交换位置
			for (char* sCh = sBegin; *sCh != '\0'; sCh++)
			{
				//交换位置
				char temp = *sBegin;
				*sBegin = *sCh;
				*sCh = temp;
				//交换完后继续全排列
				solvePermutation(s, sBegin + 1);
				//回溯
				temp = *sBegin;
				*sBegin = *sCh;
				*sCh = temp;
			}
		}
	}
};
```