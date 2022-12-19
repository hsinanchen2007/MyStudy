### 解题思路
算术表达式系列最简单题...一个栈即可实现

### 代码

```csharp
public class Solution {
    public int EvalRPN(string[] tokens) {
        if ((tokens?.Length ?? 0) == 0) return 0;
        Stack<int> numbers = new Stack<int>();
        foreach (var token in tokens)
        {
            switch (token)
            {
                case "+":
                    {
                        var number = numbers.Pop();
                        var lastNumber = numbers.Pop();
                        numbers.Push(lastNumber + number);
                        break;
                    }
                case "-":
                    {
                        var number = numbers.Pop();
                        var lastNumber = numbers.Pop();
                        numbers.Push(lastNumber - number);
                        break;
                    }
                case "*":
                    {
                        var number = numbers.Pop();
                        var lastNumber = numbers.Pop();
                        numbers.Push(lastNumber * number);
                        break;
                    }
                case "/":
                    {
                        var number = numbers.Pop();
                        var lastNumber = numbers.Pop();
                        numbers.Push(lastNumber / number);
                        break;
                    }
                default:
                    {
                        numbers.Push(int.Parse(token));
                        break;
                    }
            }
        }
        return numbers.Pop();
    }
}
```