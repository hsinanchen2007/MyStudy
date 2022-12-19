### 解题思路
    这个题属于比较简单的括号匹配，要解这道题首先明白括号什么情况下匹配，什么情况下不匹配。下面是我老师课件上的讲解，很详细。
    1、括号不匹配四种情况
![SharedScreenshot.jpg](https://pic.leetcode-cn.com/a4235ae659d91e96106fe4baaae8df4371ff39dab1f96740ad59666ddc8293d9-SharedScreenshot.jpg)
    2、具体操作
![2.jpg](https://pic.leetcode-cn.com/a4cd8e4b5c5561cd3fa5322f539a1ed61e24f8f77bc296c5e26d44c8855d8b84-2.jpg)
![3.jpg](https://pic.leetcode-cn.com/118970c730bb3975e6a768a6442472f29b9e1bffca66fdf39ca4f398952c4add-3.jpg)
![4.jpg](https://pic.leetcode-cn.com/07b34d9fe1c8c29cf97c741253d32fc1038bf8e6942534d9e3d5390ea9752a70-4.jpg)
![5.jpg](https://pic.leetcode-cn.com/c3e1f79c9cc157f10e0af568c884c02c6141b909d3df24b899bb93121aef1a4e-5.jpg)




### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
    char* barcesStack = new char[s.size() + 1];  //建立一个栈
	barcesStack[0] = '#';  //栈底元素
	char* top = &barcesStack[0];
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case '(':
			top++;  //栈顶指针向上移动
			*top = s[i];  //入栈
			break;
		case '[':
			top++;  //栈顶指针向上移动
			*top = s[i];  //入栈
			break;
		case '{':
			top++;  //栈顶指针向上移动
			*top = s[i];  //入栈
			break;
		case ')':  //与栈顶元素进行匹配，如果可以匹配栈顶元素出栈，否则报错
			if (*top == '(')
			{
				top--;  //出栈，栈顶指针下移
				break;
			}
			else
				return false;
		case ']':  //与栈顶元素进行匹配，如果可以匹配栈顶元素出栈，否则报错
			if (*top == '[')
			{
				top--;
				break;
			}
			else
				return false;
		case '}':  //与栈顶元素进行匹配，如果可以匹配栈顶元素出栈，否则报错
			if (*top == '{')
			{
				top--;
				break;
			}
			else
				return false;
		default:
			//由于题目给定字符串只包含括号，没有其他字符，所以此处不处理
			break;
		}
	}
	if (*top == '#')  //栈为空匹配正确
		return true;
	else  //栈中还有剩余括号，匹配失败
		return false;
    }
};
```