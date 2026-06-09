直接根据题意进行模拟即可。
1. 将字符串`num`转成整数，值得注意的是，这里的数值最大为`10^12`，需要使用`long long`进行存放；
2. 将数值转成十六进制的字符串；
3. 检查十六进制字符串内是否有2到9，如果有则输出ERROR。

做这道题过程中让人不爽的一点就是，没有从C++中找到直接的函数，能将数值转换成十六进制的字符串，即使使用`stringstream`也拐了一个弯。
```
class Solution {
public:
	string toHexspeak(string num) {
		string strHex;
		long long llNum = std::strtoll(num.c_str(), 0, 10);
		while (llNum > 0)
		{
			size_t nMod = llNum % 16;
			if (nMod > 1 && nMod < 10)
				break;
			else if (nMod == 0)
				strHex.push_back('O');
			else if (nMod == 1)
				strHex.push_back('I');
			else
				strHex.push_back(char('A' + nMod - 10));

			llNum /= 16;
		}

		if (llNum > 0)
			strHex = string("ERROR");
		else
			std::reverse(strHex.begin(), strHex.end());

		return strHex;
	}
};
```