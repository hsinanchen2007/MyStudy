### 解题思路

看最高位数，分为以下几类：9,8-5,4,3-1，然后给其分配相应的代号，
在num基础上减去相应的数直到为0。

### 代码

```cpp
class Solution {
public:
	string intToRoman(int num) {
		string res;
		if (num > 3999 || num < 1)
			return res;
		vector<string> str9{ "IX","XC","CM" },
			str4{ "IV" ,"XL","CD" },
			str5{ "V","L","D" },
			str1{ "I","X","C" };
		while (num)
		{
			while (num >= 1000)
			{
				num -= 1000;
				res.push_back('M');
			}
			int p;
			if (num >= 100)
				p = 2;
			else if (num >= 10)
				p = 1;
			else
				p = 0;

			int pp = pow(10, p);
			while (num>=pp)
			{
				if (num >= 9*pp)
				{
					num -= 9 * pp;
					res.append(str9[p]);
					break;
				}
				if (num >= 4 * pp && num < 5 * pp)
				{
					num -= 4 * pp;
					res.append(str4[p]);
					break;
				}
				if (num >= 5 * pp)
				{
					res.append(str5[p]);
					num -= 5*pp;
					continue;
				}
				num -= pp;
				res.append(str1[p]);
				
			}
		}

		return res;
	}
};

```