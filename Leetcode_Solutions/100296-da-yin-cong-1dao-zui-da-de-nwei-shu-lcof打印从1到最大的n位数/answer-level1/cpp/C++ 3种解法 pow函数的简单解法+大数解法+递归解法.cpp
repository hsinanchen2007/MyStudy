### 解题思路
1、针对本题的常规思路，利用pow函数，秒解
2、假设可能出现大数（本题不可能），转换为大数问题求解
本题自己对于大数解法，分别练习了使用char和string两种方式分别进行求解
-	通过使用char数组进行求解
- 	通过使用string进行求解

3、递归求解
### 代码

#### 针对本题的简单解法
```cpp
class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> res;
		if (n == 0) return res;
		//打印到数组中
		for (int i=1,max=pow(10,n);i<max;i++)
		{
			res.push_back(i);
		}
		return res;
	}
}; 
```
#### 大数解法 char版

```cpp
class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//创建一个能容纳最大值的字符数组,由于有一位要存储'\0'，因此要开大一格
		char* number = new char[n + 1];
		//初始全部设置为0
		memset(number, '0', n);
		number[n] = '\0';//第n位设为'\0'
		while (!Increment(number))
		{
			PrintNumber(number);
		}
		delete[]number;//注意要释放内存
		return res;
	}
	bool Increment(char* number) {//形参传递char*指针
		bool isOverflow = false;//检测是否越界
		int nTakeOver = 0;//存储进位
		int nLength = strlen(number);//长度为n,不是n+1
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//如果是第一位，进位
			{
				nSum++;
			}
			if (nSum >= 10)
				//有进位
			{
				if (i == 0)
					//如果是最高位有进位，说明超过了给定得到最大值，越界
				{
					isOverflow = true;
				}
				else//非最高位有进位
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//对第i位进行设置
				}
			}
			else//没有进位
				//设置第i位数字
				//并直接跳出循环
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void PrintNumber(char* number)
	//形参传递char*指针，此处改变形参number指向的位置，不会使原始的number指针所指位置改变
	{
		string s = "";
		bool isBegin0 = true;
		while (*number != '\0')
		{
			if (isBegin0 && *number != '0') isBegin0 = false;
			//碰到'0'，则不输出
			if (!isBegin0)
			{
				s += *number;
			}
			number++;
		}
		int num = stoi(s);//转为整数
		res.push_back(num);
	}
};

```

#### 大数解法string版
```cpp
class Solution {
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		//创建一个能容纳最大值的字符数组
		string number(n, '0');
		//初始全部设置为0
		while (!Increment(number))
		{
			saveNumber(number);
		}
		return res;
	}
	bool Increment(string& number) {
		//注意要使用引用传递，否则无法修改number
		bool isOverflow = false;//检测是否越界
		int nTakeOver = 0;//存储进位
		int nLength = number.size();
		for (int i = nLength - 1; i >= 0; i--)
		{
			int nSum = number[i] - '0' + nTakeOver;
			if (i == nLength - 1)
				//如果是第一位，进位
			{
				nSum++;
			}
			if (nSum >= 10)//有进位
			{
				if (i == 0)
					//如果是最高位有进位，说明超过了给定得到最大值，越界
				{
					isOverflow = true;
				}
				else
				{
					nTakeOver = 1;
					number[i] = nSum - 10 + '0';//对第i位进行设置
				}
			}
			else//没有进位
				//设置第i位数字
				//并直接跳出循环
			{
				number[i] = nSum + '0';
				break;
			}
		}
		return isOverflow;
	}
	void saveNumber(string number)
		//由于此处输出，不需要修改number，因此不需要加引用
	{
		string s = "";
		bool isBegin0 = true;
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0)
			{
				s += *it;
			}
			it++;
		}
		int num = stoi(s);
		res.push_back(num);
	}
};
```

#### 递归解法
```cpp
class Solution
{
public:
	vector<int> res;
	vector<int> printNumbers(int n) {
		if (n <= 0) return res;
		string number(n, '0');
		for (int i = 0; i <= 9; i++)
		//从高位到低位进行全排列
		{
			number[0] = i + '0';//首字符赋初值
			permutationNumbers(number, n, 1);//设置下一位
		}
		return res;
	}
	//对数字全排列
	void permutationNumbers(string& number, int length, int index) {
		if (index == length) {//递归边界
			saveNumber(number);//存储结果
			return;
		}
		else
		{
			for (int i = 0; i <= 9; i++)
			{
				number[index] = '0' + i;//设置第index位的字符
				permutationNumbers(number, length, index + 1);
			}
		}
	}
	//存储结果
	//只能存储前导非0的排列
	void saveNumber(string number) {
		bool isBegin0 = true;
		string tempStr = "";
		string::iterator it = number.begin();
		while (it != number.end())
		{
			if (isBegin0 && *it != '0') isBegin0 = false;
			if (!isBegin0) {
				tempStr += *it;
			}
			it++;
		}
		//从高位到低位全排列，要注意首字符为0时，tempStr为空，不能执行stoi
		if (tempStr != "") {
			int tempNum = stoi(tempStr);
			res.push_back(tempNum);
		}
	}
};
```