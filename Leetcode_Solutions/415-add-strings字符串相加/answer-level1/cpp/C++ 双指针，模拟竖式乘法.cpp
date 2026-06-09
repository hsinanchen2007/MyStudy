### 解题思路
参考答主[@jyd](/u/jyd/)的解法写的C++代码

### 代码

```cpp
class Solution {
public:
	string addStrings(string num1, string num2) {
		//if (num1.length()==1&& stoi(to_string(num1[0]))==0|| num2.length() == 1 && stoi(to_string(num2[0])) == 0)
		//{
		//	return "0";//如果num1某个字符
		//}
		int i = num1.length() - 1, j = num2.length() - 1;//i,j指针分布指向num1，num2尾部，模拟人工加法
		int carry = 0;//记入进位值
		string res = "";//记录结果
		while (i >= 0 || j >= 0)
		{
			int tmp = 0;//计算每一位相加的值
			int n1 = i < 0 ? 0 : num1[i]-'0';
			int n2 = j < 0 ? 0 : num2[j] - '0';
			tmp = n1 + n2 + carry;//计算每一对应位相加的和
			carry = tmp / 10;//保留进位数
			tmp %= 10;//保留余数
			res.append(to_string(tmp));
			i--, j--;//前移一位
		}
		if (carry == 1)//如果num1，num2的最高一位相加后进位了，最后还要加上进位
		{
			res.append(to_string(carry));
		}
		string s(res.rbegin(), res.rend());//结果逆序输出
		return s;
	}
};
```