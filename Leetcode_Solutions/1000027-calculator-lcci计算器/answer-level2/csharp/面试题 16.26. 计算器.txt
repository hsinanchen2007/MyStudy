### 解题思路
使用Stack处理运算符优先级；
Stack只存储+和-运算符的数据；
遇到*和/运算符时直接取Stack顶数字计算后再放回Stack；

### 代码

```csharp
public class Solution {
    public int Calculate(string s) {
        if (string.IsNullOrWhiteSpace(s)) return 0;

        var stack = new Stack<int>();
        var queue = new Queue<char>(s);
        var numberBuilder = new StringBuilder();
        var lastFlag = '+';
        while (queue.Count > 0)
        {
            var @char = queue.Dequeue();
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
                default:
                    {
                        numberBuilder.Append(@char);
                        break;
                    }
            }
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