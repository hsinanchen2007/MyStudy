# 在这里，我并不局限于本题，希望在求解本题的基础上，带给大家更大的提升和拓展。

**除了本文的介绍，个人认为在表达式的处理领域还有非常多经典和值得探讨的问题
大家可以参考[https://blog.csdn.net/qq_21515253/article/details/96484567]()
此文中对整个问题做了详细的分析和总结。**

### 逆波兰算法：

**核心思想**是将普通的中缀表达式转换为后缀表达式。（关于表达式的理解可以去查询DS中关于二叉树的遍历的描述，这里不再赘述）

**后缀表达式**：运算符在两个操作数的后面。后缀表达式虽然看起来奇怪，不利于人阅读，但利于计算机处理。

####  1、后缀表达式（逆波兰式）求值

比较简单，直接上伪代码：

```
function suffixToResult：
    for each element in suffix_expression
    {
        if(element is number)
        {
            stack.push(element)
        }
        else if(element is operator)
        {
            num1 = stack.pop()
            num2 = stack.pop()
			
			value = num1 + element + num2
            stack.push(value)   
        }
        return stack.pop()
    }
}
```

#### 2、中缀表达式转化为后缀表达式

这是算法的难点，也是重中之重

**算法思想：**

设置一个stack和一个linear list

其中stack临时存放运算符和左括号的

linear list存放后缀表达式

```
if number : list.add(number)
if (:	stack.push('(')
if ):	while(stack.pop == '(')
if operator:
	if stack.peek() is not operator:	stack.push(operator)
	else :	
		if operator > stack.peek():		stack.push(operator)
        else while(stack.peek() <= operator)  stack.pop()
```

**算法实现**

```java
class solution {	
	public void getVlaue(String string) {
        System.out.println(suffixToResult(infixToSuffix(string)));
    }
    
    private boolean isNumber(char character) {
        return character >= '0' && character <= '9';
    }
    
    private boolean isOperator(char character) {
        return !isNumber(character) && character != '(' && character != ')';
    }
    
    private int priority(char character) {
        if (character == '+' || character == '-') {
            return 1;
        } else {
            return 2;
        }
    }
    
    private Integer toNumber(String expr) {
        int flag = 0;
        //["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        if (expr.charAt(0) == '-') {
            expr = expr.substring(1);
            flag = 1;
        }
        int number = 0;
        int bit = 1;
        for (int i = expr.length() - 1; i >= 0; i--) {
            number = number + (expr.charAt(i) - '0') * bit;
            bit *= 10;
        }
        if (flag == 0) {
            return number;
        } else {
            return -1 * number;
        }
    }
    
    public List<String> infixToSuffix(String expr) {
        Stack<Character> stack = new Stack<>();
        ArrayList<String> list = new ArrayList<>();
        for (int i = 0; i < expr.length(); i++) {
            if (expr.charAt(i) >= '0' && expr.charAt(i) <= '9') {
                String numExpr = "";
                while (i < expr.length() && isNumber(expr.charAt(i))) {
                    numExpr = numExpr + expr.charAt(i);
                    i++;
                }
                i--;
                list.add(numExpr);
            } else if (expr.charAt(i) == '(') {
                stack.push(expr.charAt(i));
            } else if (expr.charAt(i) == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    list.add("" + stack.pop());
                }
                if (!stack.isEmpty()) {
                    stack.pop();
                }
            } else {
                
                while (!stack.isEmpty() && isOperator(stack.peek())
                        && priority(stack.peek()) >= priority(expr.charAt(i))) {
                    //System.out.println(priority(stack.peek()));
                    //System.out.println(priority(expr.charAt(i)));
                    list.add(stack.pop() + "");
                }
                stack.push(expr.charAt(i));
            }
            //System.out.println(stack);
            //System.out.println(list);
            //System.out.println("-----");
        }
        while (!stack.isEmpty()) {
            list.add(stack.pop() + "");
        }
        return list;
    }
    
    public int suffixToResult(List<String> list) {
        //System.out.println(list);
        Stack<Integer> stack = new Stack<>();
        
        for (String element : list) {
            if (isNumber(element.charAt(0)) || (element.length() > 1 && isNumber(element.charAt(1)))) {
                //System.out.println(toNumber(element));
                stack.push(toNumber(element));
            } else {
                //System.out.println(stack);
                Integer num1 = stack.pop();
                Integer num2 = stack.pop();
                Integer value = 0;
                if (element.charAt(0) == '+') {
                    value = num2 + num1;
                } else if (element.charAt(0) == '-') {
                    value = num2 - num1;
                } else if (element.charAt(0) == '*') {
                    value = num2 * num1;
                } else if (element.charAt(0) == '/') {
                    value = num2 / num1;
                }
                System.out.println(num2);
                System.out.println(num1);
                System.out.println("***" + value);
                stack.push(value);
            }
        }
        return stack.pop();
    }
}
```

### 

讨论完逆波兰，还有点意犹未尽，是不是想一起讨论下跟逆波兰有同样作用和地位的递归下降呀。
来了！！
### 递归下降算法

递归下降是编译原理中词法分析的重要方法，而利用递归下降进行表达式求值，也是一个强烈推荐的手段！！！思考简单！！逻辑清晰！！！

#### 核心思想

递归下降分析来求表达式的值。表达式的文法如下

```
expr = term {+、-} term
term = factor {*、/} factor
factor = (expr) or number
```

​	其实原理就这么简单，层层递归即可

#### 代码实现

直接上代码，一看就知

```java
class Solution {
    int cur = 0;
    String str = "";
    
    public double cal(String s) {
        this.str = s;
        return expression();
    }
    
    public double expression() {
        double num1 = term();
        double num2;
        while (cur < str.length() && (str.charAt(cur) == '+' || str.charAt(cur) == '-')) {
            char op = str.charAt(cur);
            cur++;
            num2 = term();
            if (op == '+') {
                num1 += num2;
            } else {
                num1 -= num2;
            }
        }
        if (cur < str.length() && str.charAt(cur) == ')') {
            cur++;
        }
        return num1;
    }
    
    public double term() {
        double num1 = factor();
        double num2;
        while (cur < str.length() && (str.charAt(cur) == '*' || str.charAt(cur) == '/')) {
            char op = str.charAt(cur);
            cur++;
            num2 = factor();
            if (op == '*') {
                num1 *= num2;
            } else {
                num1 /= num2;
            }
        }
        return num1;
    }
    
    public double factor() {
        double result;
        if (str.charAt(cur) == '(') {
            cur++;
            return expression();
        } else {
            String string = "";
            while (cur < str.length() && isNumber(str.charAt(cur)) ) {
                string = string + str.charAt(cur);
                cur++;
            }
            result = toNumber(string);
        }
        return result;
    }
    
    private boolean isNumber(char character) {
        return character >= '0' && character <= '9';
    }
    
    private Integer toNumber(String expr) {
        int flag = 0;
        //["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
        if (expr.charAt(0) == '-') {
            expr = expr.substring(1);
            flag = 1;
        }
        int number = 0;
        int bit = 1;
        for (int i = expr.length() - 1; i >= 0; i--) {
            number = number + (expr.charAt(i) - '0') * bit;
            bit *= 10;
        }
        if (flag == 0) {
            return number;
        } else {
            return -1 * number;
        }
    }
}
```

