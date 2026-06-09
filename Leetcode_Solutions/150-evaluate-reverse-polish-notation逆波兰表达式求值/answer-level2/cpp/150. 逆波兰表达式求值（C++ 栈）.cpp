# 150. 逆波兰表达式求值
**思路：**

- 逆波兰式：也就是后缀表达式（将运算符写在操作数之后）
- 计算逆波兰式需要用到一个栈（用于存入计算用到的数值）。
- 计算逆波兰式依据以下规则：
    1. 遍历用户输入的逆波兰式。
    2. 如果遍历到的元素是一个数值，那么把该元素入栈等待后续计算；
    3. 如果遍历到的元素是一个符号，那么出栈栈顶的两个数值元素用该符号进行计算。
    **（注意：由于栈的先进先出特性，先出栈的是第二个操作数，后出栈的是第一个操作数-在减法、除法运算时有不同）**
    4. 再把结果计算结果入栈，等待下一个计算。
- 当遍历完整个输入的逆波兰式后，当前栈顶数值就是总的计算结果。

**完整代码：**

```
class Solution {
public:
	bool calitem( int num1, int num2, string op, int &rst ){
		if( op == "+" )  rst = num1 + num2;
		if( op == "-" )  rst = num1 - num2;
		if( op == "*" )  rst = num1 * num2;
		if( op == "/" ){
			if( num2 == 0 )  return false;	//除数不为0
			rst = num1 / num2;
		}
		return true;
	}
	
    int evalRPN(vector<string>& tokens) {
		stack<int> m_stack;
		for( string item : tokens ){
			if( item == "+" || item == "-" || item == "*" || item == "/" ){
				int num2 = m_stack.top();	m_stack.pop();	//先出栈第二个操作数
				int num1 = m_stack.top();	m_stack.pop();	//再出栈第一个操作数
				int rst;
				if(calitem(num1,num2,item,rst))  m_stack.push(rst);
			}else{
				m_stack.push(atoi(item.c_str()));
			}
		}
		return m_stack.top();
    }
};
```
