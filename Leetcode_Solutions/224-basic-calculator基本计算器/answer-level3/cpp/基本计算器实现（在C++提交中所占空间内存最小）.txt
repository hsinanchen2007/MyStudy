#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution 
{
public:
	int calculate(string s) 
	{
		stack<char> opr;
		stack<int> num;
		num.push(0);
		int i = 0;
		while (i < s.size())
		{
			if (s[i] == ' ')
				++i;
			else if (s[i] == '(' || s[i] == '+' || s[i] == '-' ) 
			{
				opr.push(s[i]);
				++i;
			}
			else if (s[i] == ')') 
			{
				int sum = 0;
				while (opr.top() != '(')
				{
					char op = opr.top();
					opr.pop();
					int n = num.top();
					num.pop();
					sum += op == '+' ? n : -n; // 此处sum= n或者-n
				}
				sum += num.top();
				num.pop();
				num.push(sum);
				opr.pop();  //这里弹出的是左括号'('
				if (!opr.empty())
				{
					if (opr.top() == '+' || opr.top() == '-')
					{
						char op = opr.top();
						opr.pop();
						int second = num.top();
						num.pop();
						int first = num.top();
						num.pop();
						num.push(op == '+' ? first + second : first - second);
					}
				}
				++i;
			}
			else 
			{
				string tmp = "";  //这里的一步骤，是为了计算多个数字在一起
				while (i < s.size() && s[i] >= '0' && s[i] <= '9') 
				{
					tmp.push_back(s[i]);
					++i;
				}
				num.push(stoi(tmp));  //每次有一个数字进来，都要判断opr栈顶是否有+或-
				if (!opr.empty() && (opr.top() == '+' || opr.top() == '-')) 
				{
					char op = opr.top();
					opr.pop();
					int second = num.top();
					num.pop();
					int first = num.top();
					num.pop();
					num.push(op == '+' ? first + second : first - second);
				}
			}
		}
		return num.top();
	}
};
int main()
{
	Solution s;
	int r=s.calculate("(7)-(0)+(4)");
	cout << r << endl;
	system("pause");
	return 0;
}