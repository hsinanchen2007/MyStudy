### 解题思路
结合栈和逆波兰表达式进行编写，数字和每次计算后的结果都存入栈中进行运算即可

### 代码

```cpp
/* 栈+逆波兰 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(int i = 0 ; i < tokens.size() ;++i){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){   
                //遇到四则运算时取出栈中的数字进行运算
                int res;
                int n2 = numbers.top();
                numbers.pop();
                int n1 = numbers.top();
                numbers.pop();
                
                if(tokens[i] == "+")
                   res = n1 + n2;
                else if(tokens[i] == "-")
                   res = n1 - n2;
                else if(tokens[i] == "/")
                   res = n1 / n2;
                else
                   res = n1 * n2;
                numbers.push(res);              //将结果再存至栈中 作为下一次运算的数
            }else{
                numbers.push(stoi(tokens[i]));  //先存入转为数字格式的数字
            } 
        }
        return numbers.top();
    }
};
```
![image.png](https://pic.leetcode-cn.com/3e29b5d3c7d73241e1ae24463553cc0362b3a6e38484915f657fb0dd7018ba48-image.png)
