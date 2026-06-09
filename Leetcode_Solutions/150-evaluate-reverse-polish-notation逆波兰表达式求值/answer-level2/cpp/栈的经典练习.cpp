### 解题思路
原理不作解释，网上博客讲的好的比比皆是，做法就是遇到数字就入栈，遇到符号就将数字栈中的数字出栈两个，进行运算后将所得结果入栈，由于题目明确给出说明不会有除数为0和表达式无效的情况，这样我们无需进行错误判断。最后的结果必定是数字栈的栈顶元素且数字栈只有一个元素。

### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		for(int i=0;i<tokens.size();i++)
		{
// 这个库函数可以讲字符转数字，非数字返回0所以下面tokens[i]!=0进行特判处理
			int num=atoi(tokens[i].c_str());
			if(num==0&&tokens[i]!="0")
			{
				int num1=nums.top();
				nums.pop();
				int num2=nums.top();
				nums.pop();
				int res;
// 这里注意是num2在前，num1在后，我就犯了错误num1/num2和num2/num1是不一样的，num1-num2也和num2-num1不一样
				if(tokens[i]=="+")
					res=num2+num1;
				if(tokens[i]=="*")
					res=num2*num1;
				if(tokens[i]=="/")
					res=num2/num1;
				if(tokens[i]=="-")
					res=num2-num1;
				nums.push(res);
			}
			else
			{
				nums.push(num);
			}
		}
		return nums.top();
    }
};
```