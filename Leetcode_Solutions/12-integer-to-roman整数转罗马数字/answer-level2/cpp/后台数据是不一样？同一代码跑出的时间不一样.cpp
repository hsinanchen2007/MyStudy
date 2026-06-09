### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
       	string Roman;
	int i ;
	int a, b, c, d;
	a = num / 1000;
	b = num % 1000 / 100;
	c = num % 100 / 10;
	d = num % 10;
	for (i = 0; i < a;i++)                     //处理千位罗马数字
		Roman.push_back('M');
	if (b == 9)								//处理百位罗马数字
		Roman.append("CM");
	else if (b >= 5) {                  
		Roman.push_back('D');
		b = b - 5;
		for (i = 0; i < b; i++)
			Roman.push_back('C');
	}
	else if(b == 4)
		Roman.append("CD");
	else
	{
		for (i = 0; i < b; i++)
			Roman.push_back('C');
	}
	if (c == 9)						//处理十位罗马数字
		Roman.append("XC");
	else if (c >= 5) {                  
		Roman.push_back('L');
		c = c - 5;
		for (i = 0; i < c; i++)
			Roman.push_back('X');
	}
	else if (c == 4)
		Roman.append("XL");
	else
		for (i = 0; i < c; i++)
			Roman.push_back('X');
	if (d == 9)						//处理个位罗马数字
		Roman.append("IX");
	else if (d >= 5) {                  
		Roman.push_back('V');
		d = d - 5;
		for (i = 0; i < d; i++)
			Roman.push_back('I');
	}
	else if (d == 4)
		Roman.append("IV");
	else
		for (i = 0; i < d; i++)
			Roman.push_back('I');
	return Roman; 
    }
};
```