### 解题思路
1. 把字符串想想成数值
2. 将str1和str2对应的数值, 不断进行分段, 之后将str1分段后的数放到str2里头, 看是否能整除, 如果能整除, 说明是最大公因子
3. 详见代码

### 代码

```cpp
class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1 == "" || str2 == "")
			return "";

		int nMaxSubStringSize = 0;
		// 把每个字符作为一个数值, 加起来, 求出str1和str2的各自的总体数值
		int n1 = 0, n2 = 0;
		for (int i = 0; i < str1.length() || i < str2.length(); i++)
		{
			if ((i > str1.length()) && (i > str2.length()))
				break;

			if (i < str1.length())
			{
				n1 += (int)str1[i];
			}
			if (i < str2.length())
			{
				n2 += (int)str2[i];
			}
		}

		// 再遍历一遍, 求两个数的最大公约数
		// 根据长度的最大公约数, 算每个字串的值, 讲道理, 它应该能够呗两个字符串的值整除才对
		// 如果能整除, 就记下来, 往后遍历, 如果不能整除, 就忽略, 继续遍历
		for (int i = 1; i < str1.length() || i < str2.length(); i++)
		{
			// 到这里了说明都能整除, 是length的公约数
			// 这时候可以去判断, 这时候转去判断n1和n2是否能整除这个数值, 如果可以, 那么说明这个是个字串
			if (n1 % i == 0 && n2 % (n1 / i) == 0)
			{
				nMaxSubStringSize = i;
				break;
			}
		}

		if (nMaxSubStringSize == 0)
		{
			return "";
		}
		else
		{
			str1[str1.length()/nMaxSubStringSize] = '\0';
			return str1;
		}
	}
};
```