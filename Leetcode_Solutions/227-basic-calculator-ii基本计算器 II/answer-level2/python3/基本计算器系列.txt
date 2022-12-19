### 解题思路
此题是基本计算器系列中较为简单的两道题之一，该题包含了加减乘除四种运算，但是还没有包含括号。
表达式是典型的利用栈进行求解的题目，这道题的解题思路如下：
1、将出入的字符串分解成表达式列表，为下一步运算做好准备：a、去除空格 b、处理非个位数的数字，例如 3 + 22
2、按照优先级进行运算
   1、先计算乘除  压栈，遇到乘除符号的下一个数字时，弹栈，将计算结果入栈，最后生成一个只包含加减运算的栈
   2、最后计算加减  逐个进行加减运算即可。

### 代码

```python3
class Solution:
    def calculate(self, s: str) -> int:
        list_input = self.get_legal_list(s)
        helper = []
        flag = ""
        for symbol in list_input:
            if symbol == "+":
                helper.append(symbol)
            elif symbol == "-":
                helper.append(symbol)
            elif symbol == "*":
                flag = "cheng"
            elif symbol == "/":
                flag = "chu"
            else:
                if flag == "cheng":
                    num1 = helper.pop()
                    num2 = symbol
                    a1=int(num1)
                    a2=int(num2)
                    helper.append(str(a1*a2))
                    flag = ""
                elif flag == "chu":
                    num1 = helper.pop()
                    num2 = symbol
                    helper.append(str(a1//a2))
                    flag=""
                else:
                    helper.append(symbol)
        result =int( helper[0])
        flag = ""
        for symbol in helper[1:]:
            if symbol == "+":
                flag = "+"
            elif symbol == "-":
                helper.append(symbol)
                flag = "-"
            else:
                if flag == "+":
                    print(symbol)
                    result += int(symbol)
                elif flag == "-":
                    result -= int(symbol)
        return result
    def get_legal_list(self,s):
        ret = []
        temp = ""
        for single in s:
            if single == " ":
                continue
            elif single == "+" or single == "-" or single == "*" or single == "/":
                ret.append(temp)
                ret.append(single)
                temp = ""
            else:
                temp += single
        ret.append(temp)
        return ret
```