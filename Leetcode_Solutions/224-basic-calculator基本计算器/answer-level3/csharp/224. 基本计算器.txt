### 解题思路
支持+、-、*、/、(、)；
使用Stack实现算术优先级；
使用递归实现小括号；

### 代码

```csharp
public class Solution {
    public int Calculate(string s)
    {
        if (string.IsNullOrWhiteSpace(s)) return 0;
        var expression = new Queue<char>(s);
        return Calculate(expression);
    }
    public int Calculate(Queue<char> expression)
    {
        var stack = new Stack<int>();
        var numberBuilder = new StringBuilder();
        var lastFlag = '+';
        while (expression.Count > 0)
        {
            var @char = expression.Dequeue();
            var exitWhile = false;

            switch (@char)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                    {
                        PushToStack(stack, numberBuilder, lastFlag);
                        lastFlag = @char;
                        break;
                    }
                case ' ':
                    {
                        break;
                    }
                case '(':
                    {
                        var subResult = Calculate(expression);
                        numberBuilder.Append(subResult);
                        break;
                    }
                case ')':
                    {
                        exitWhile = true;
                        break;
                    }
                default:
                    {
                        numberBuilder.Append(@char);
                        break;
                    }
            }

            if (exitWhile) break;
        }
        PushToStack(stack, numberBuilder, lastFlag);

        var result = 0;
        while (stack.Count > 0)
        {
            result += stack.Pop();
        }
        return result;
    }

    private void PushToStack(Stack<int> stack, StringBuilder numberBuilder, char lastFlag)
    {
        var number = int.Parse(numberBuilder.ToString());
        switch (lastFlag)
        {
            case '+':
                {
                    stack.Push(number);
                    break;
                }
            case '-':
                {
                    stack.Push(-number);
                    break;
                }
            case '*':
                {
                    var lastNumber = stack.Pop();
                    stack.Push(lastNumber * number);
                    break;
                }
            case '/':
                {
                    var lastNumber = stack.Pop();
                    stack.Push(lastNumber / number);
                    break;
                }
        }
        numberBuilder.Clear();
    }
}
```