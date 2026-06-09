### 思路
待操作数字的生成，滞后于运算符的读取。优势在于其对减法的简化。

### 代码
```
class Solution {
public:
    int calculate(string s) {
        queue<char> calc;
        for(char c: s)
        {
            if(c != ' ')
            {
                calc.push(c);
            }
        }
        calc.push('#');

        long num = 0, sum = 0, prev = 0;
        char prevOp = '+';
        while(!calc.empty())
        {
            char c = calc.front();
            calc.pop();
            if(c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else { // + - * / 
                switch(prevOp)
                {
                    case '+':
                        sum += prev;
                        prev = num;
                        break;
                    case '-':
                        sum += prev;
                        prev = -num;
                        break;
                    case '*':
                        prev *= num;
                        break;
                    case '/':
                        prev /= num;
                        break;
                }
                prevOp = c;
                num = 0;
            }
        }

        return int(sum + prev);
    }

};
```
