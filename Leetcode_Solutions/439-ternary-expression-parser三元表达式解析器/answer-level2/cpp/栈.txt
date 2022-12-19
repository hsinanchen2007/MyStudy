### 解题思路
一般这种语法分析器的操作都是使用栈来操作，解析之后再入栈，最后只剩下栈里面的一个元素。同时注意leecode上面合法数据校验有些是没有必要的。

**C++小细节** string可以使用vector各种操作，push_back() / pop_back() / back() 等操作。
string 和 char之间转换：  string str (1, char);   char a = str.c_str();
string 和 int 之间转换：  string str = to_string(int a);  int a = stoi(str);
### 代码

```cpp
class Solution {
public:
    string parseTernary(string expression) {
        stack<char> deCodeStack;
		char deCodeChar[3];
		while(!expression.empty()) {
			if (expression.back() == '?') {
				for (int i = 0; i < 3; i++) {
					deCodeChar[i] = deCodeStack.top();
					deCodeStack.pop();
				}
				expression.pop_back();
				if (expression.back() == 'T') {
					deCodeStack.push(deCodeChar[0]);
				} else {
					deCodeStack.push(deCodeChar[2]);
				}
				expression.pop_back();
			} else {
				deCodeStack.push(expression.back());				
				expression.pop_back();
			}
		}
		string results(1, deCodeStack.top());
		return results;	
    }
};
```