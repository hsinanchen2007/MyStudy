***特点：cpp 实现逻辑清晰代码简单***
解题思路：
算法原理
栈先入后出特点恰好与本题括号排序特点一致，即若遇到左括号入栈，遇到右括号时将对应栈顶左括号出栈，则遍历完所有括号后 stack 仍然为空；
建立栈 stack，遍历字符串 s 并按照算法流程一一判断。

如果 s.at(当前元素) 是左括号，则入栈 push；
否则，先检查是否为空，为空说明没有元素和左括号比较，直接false;
再穷举左边和右边各种符号不匹配的情况。
穷举后注意：注意不是return true;而是上面所有匹配成功，出栈入栈对应对应，最后为空

作者：ac虾米
来源：https://leetcode-cn.com/circle/article/50bDJt/
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
Code：
class Solution
{
	public:
			bool isValid(const string &S)
{
		stack<char>m_stack; //建立一个栈

	if (S.empty())
	{
			return true;
	}         
	//判断传入字符串的每个字符
	
	for (int i=0;i<S.size();i++)
{

	if (S.at(i)=='('||S.at(i)=='{'||S.at(i)=='[')
	{                                              //若是左括号全部入栈
		m_stack.push(S.at(i));
	}
	
	else
	{
		if (m_stack.empty())
		{
			return false;                        //右括号先检查S是否还有元素，在逐一假设判断
		}

		char topChar = m_stack.top();
		m_stack.pop();

		if (S.at(i)==')'&&(topChar!='('))
		{
			return false;
		}
		if (S.at(i) == '}' && (topChar != '{'))
		{
			return false;
		}
		if (S.at(i) == ']' && (topChar != '['))
		{
			return false;
		}

	}
}
return m_stack.empty();                           //注意不是return true;而是上面所有匹配成功，出栈入栈对应对应，最后为空
    
}
};
		
作者：云深じ不知处
链接：https://leetcode-cn.com/circle/article/50bDJt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。