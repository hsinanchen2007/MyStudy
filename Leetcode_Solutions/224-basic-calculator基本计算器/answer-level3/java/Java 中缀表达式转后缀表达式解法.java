这一题与栈有关，我们可以首先将中缀表达式转化成后缀表达式（也即逆波兰表达式），然后求解后缀表达式的值。
以中缀表达式“2-1+2”为例，他的后缀表达式为“21-2+”。
以中缀表达式“(1+(4+5+2)-3)+(6+8)”为例，他的后缀表达式为“145+2++3-68++”。
（1）中缀表达式转后缀表达式
    我们首先初始化两个栈，一个是保存操作数的栈，这里称之为数字栈，另一个是保存运算符和括号的栈，称之为符号栈
    我们从左到右遍历表达式，根据遍历到的元素分成下面几种情况：
1、如果是操作数，那么直接压入操作数的栈
2、如果是“（”左括号的话，那么就直接压入存放运算符的栈
3、如果是“）”右括号的话，那么就从运算符栈中弹出数据，并压入到数字栈中，直到遇见“（”左括号 （注意，这里的左括号只是从栈中弹出，但是并不压入到数字栈中），右括号“）”不压入符号栈。
4、如果是算术运算符，也就是“+-*/”这些，那么就再分进一步判断：
    4-1：如果符号栈为空，则直接压入运算符的栈
    4-2：如果符号栈不为空且此时符号栈栈顶元素为左括号“（”，那么也是直接压入符号栈
    4-3：如果此时遍历的运算符的优先级比此时符号栈栈顶的运算符的优先级高， 则直接压入符号栈
    4-4：如果此时遍历的运算符的优先级小于等于此时符号栈栈顶的运算符的优先级，则将符号栈的栈顶元素弹出并且放到操作数栈中，并且将正在遍历的符号压入符号栈
5、重复上述操作，直到遍历到中缀表达式的最后一个符号。遍历完成后还需要把数字栈中的元素全部压入到符号栈中。此时符号栈中从栈顶到栈底的排列便是后缀表达式。
（2）后缀表达式求值
    后缀表达式的求解也需要一个存放数字的栈。用来存放中间结果
    求解后缀表达式的步骤为：
    遍历后缀表达式，根据遍历到的元素分成下面几种情况：
1、如果是数字，那么就直接压入数字栈
2、如果是符号，那么就从数字栈中弹出两个数字，并与当前运算符参与运算，将得到的结果压入到数字栈中
3、遍历完成后，数字栈中应该只剩一个数，这个数即为最终结果。

到这里，这道题就解完了。如有不足，欢迎大家指出，大家加油 ：）

```java
import java.util.Stack;


/**
* @author 木已成舟
* @date 2020/3/13
*/
public class Calculator {
    //计算表达式的值
    public int calculate(String s) {
        Stack<Object> numbers = new Stack<>();
        Stack<Object> operators = new Stack<>();
        int index = 0;
        while (index < s.length()) {
            char c = s.charAt(index);


            //如果是操作数，那么压入操作数的栈
            if (isDigital(c)) {
                //如果是最后一个字符,直接压入数组栈
                if (index == s.length() -1) {
                    numbers.push(c - '0');
                    //如果不是最后一个字符，并且后一个字符不是数字字符
                } else if (!isDigital(s.charAt(index + 1))) {
                    numbers.push(c - '0');
                    //说明是多位数字
                } else {
                    int p = index;
                    while (p < s.length() && isDigital(s.charAt(p)))
                        p++;


                    numbers.push(Integer.valueOf(s.substring(index, p)));
                    index = p;
                    continue;
                }
                //如果是左括号，则压入符号栈
            } else if (c == '(') {
                operators.push(c);
                //如果是右括号，则从符号栈中弹出符号，并将弹出的符号压入到数字栈中，一直到符号栈顶是左括号为止
            }  else if (c == ')') {
                while ((Character) operators.peek() != '(') {
                    numbers.push(operators.pop());
                }
                //弹出左括号
                operators.pop();
                //如果是运算符+ - * /
            } else if (isOperator(c)) {
                //如果符号栈为空，则直接压入符号栈
                if (operators.isEmpty()) {
                    operators.push(c);
                    //如果不为空，且此时运算符栈顶的符号是左括号，则直接压入栈
                } else if ((Character) operators.peek() == '(') {
                    operators.push(c);
                    //如果此时遍历到的运算符的优先级比栈顶的运算符优先级高，则直接压入栈
                } else if (priority(c) > priority((Character) operators.peek())) {
                    operators.push(c);
                    //如果此时遍历到的运算符的优先级小于等于栈顶的运算符优先级，则将符号栈的栈顶元素弹出并且放到操作数栈中，并且将正在遍历的符号压入符号栈
                } else if (priority(c) <= priority((Character) operators.peek())) {
                    numbers.push(operators.pop());
                    operators.push(c);
                }
            }


            index ++;
        }

        //遍历结束后，将数字栈中的元素全部弹出到符号栈中
        while (!numbers.isEmpty()) {
            operators.push(numbers.pop());
        }

        //此时符号栈里的元素从栈顶到栈底的排列即为逆波兰表达式
        //计算表达式的值
        while (!operators.isEmpty()) {
            Object o = operators.pop();
            //如果是数字
            if (o instanceof Integer) {
                numbers.push(o);
                //如果是字符
            } else if (o instanceof Character) {
                int num1 = (Integer) numbers.pop();
                int num2 = (Integer) numbers.pop();
                int res = 0;
                switch ((Character) o) {
                    case '+': res = num2 + num1; break;
                    case '-': res = num2 - num1; break;
                    case '*': res = num2 * num1; break;
                    case '/': res = num2 / num1; break;
                    default:
                }
                numbers.push(res);
            }
        }

        return (Integer) numbers.peek();
    }

    //判断是符号
    private boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    //判断是数字
    public boolean isDigital(char c) {
        return c >= '0' && c <= '9';
    }

    //运算符的优先级
    public int priority(char c) {
        switch (c) {
            case '+':
            case '-': return 1;
            case '*':
            case '/': return 2;
            default: throw new RuntimeException("Illegal operator:" + c);
        }
    }

}
```
