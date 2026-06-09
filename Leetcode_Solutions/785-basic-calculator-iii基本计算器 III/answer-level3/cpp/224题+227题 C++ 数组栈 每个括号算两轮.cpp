224 基本计算器 + 227 基本计算器II 都做过组合一下即可 代码很长 要用int64防溢出

C++ 存放数组的栈

每个数组记录一个括号内的信息

每个括号算两遍 第一遍算乘除法并修改操作数 第二遍算加减法

```cpp
class Solution {
public:
    int calculate(string& s) {
	s = '(' + s + ')';
        stack<vector<char>> operates;
        stack<vector<int64_t>> operands;
        operates.push(vector<char>());
        operands.push(vector<int64_t>());
        int operate = 0;
        for (int ptr = 0; ptr < s.length(); ++ptr) {
            switch (s[ptr])
            {
            case '(':
                operates.top().push_back(operate);
                operates.push(vector<char>());
                operands.push(vector<int64_t>());
                operate = 0;
                break;
            case ')': {
                int64_t sum = 0;
                for (int i = 0; i < operands.top().size(); ++i) {
                    if (operates.top()[i] > 1) {
                        int base = i - 1;
                        while (i < operands.top().size() && operates.top()[i] > 1) {
                            if (operates.top()[i] == 2)
                                operands.top()[base] *= operands.top()[i];
                            else
                                operands.top()[base] /= operands.top()[i];
                            ++i;
                        }
                        --i;
                    }
                }
                for (int i = 0; i < operands.top().size(); ++i) {
                    if (operates.top()[i] == 0)
                        sum += operands.top()[i];
                    else if (operates.top()[i] == 1)
                        sum -= operands.top()[i];
                }
                operates.pop();
                operands.pop();
		operands.top().push_back(sum);
                break;
            }
            case '+':
                operate = 0;
                break;
            case '-':
                operate = 1;
                break;
            case '*':
                operate = 2;
                break;
            case '/':
                operate = 3;
                break;
            case ' ':
                break;
            default: {
                int64_t num = 0;
                while (s[ptr] >= '0' && s[ptr] <= '9') {
		    num *= 10;
		    num += s[ptr++] - '0';
		}
		--ptr;
		operates.top().push_back(operate);
		operands.top().push_back(num);
		break;
	    }
            }
        }
	return operands.top()[0];
    }
};
```