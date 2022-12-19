### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/e7e829e6ea950b2adadec68d5f2aa6ec2ab3f9e8e5259692507d677768be48cb-image.png)
暴力法遍历字符串
### 代码

```cpp
class Solution {
public:
	void Trim(string& str)
	{
		string blanks("\f\v\r\t\n ");
		str.erase(0, str.find_first_not_of(blanks));
		str.erase(str.find_last_not_of(blanks) + 1);
	}
	long long found(string& s)
	{
		bool end = false;
		long long num = 0,num2 (0);
		bool up=true;
		int a = 0;int cnt = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (end == false)
			{
				
				switch (s[i])
				{
				case  '+':
					if (a!=0)
					{
						end = true;
					}
					a++;
					break;
				case '-':
					if (a==0)
					{
						up = false;
					}
					if (a != 0)
					{ 
						
						end = true;
					}
					a++;
					break;
				case  '0':;
				case '1':;
				case  '2':;
				case '3':;
				case  '4':;
				case  '5':;
				case '6':;
				case '7':;
				case  '8':;
				case '9'://cout << (int)s.at(i) << endl;
					a++;
					if(num<922337203685477580)
					{
						num = num * 10+((int)s.at(i)-48);
						cnt = 0;
					}
					
						//std::cout << num << endl;
					//[&]() {
					//	num = num * 10 + (int)(s.at(i));
					//	std::cout << num << endl;
					//	
					//};
					break;
				default:
					//cout << "字符不是数字了" << endl;
					end=true;
					break;
				}
			}


		}
		if(up==false)
		{
			num = 0 - num;
		}
		if (num > INT_MAX)
		{
			num = INT_MAX;
		}
		if (num < INT_MIN)
		{
			num = INT_MIN;
		}
		return num;
	}
	int myAtoi(string str) {
		Trim(str);
		
		if (str.empty())
		{
			return 0;
		}
		//cout << str<<endl;
		string s = (str.substr(1, str.length() - 1));
		switch (str[0])
		{
			case  '+': 
			case '-':
			case  '0':
			case '1':
			case  '2':
			case '3':
			case  '4':
			case  '5':
			case '6':
			case '7':
			case  '8':
			case '9':return found(str);break;
			default:
				return 0;
				break;
		}
		return 0;
	}
	
};
```