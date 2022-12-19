### 解题思路
使用双阶递归：入口函数嵌套AndOrNot，AndOrNot又嵌套入口函数；

### 代码

```csharp
public class Solution {
    public bool ParseBoolExpr(string expression)
    {
        if (string.IsNullOrWhiteSpace(expression)) return false;
        var queue = new Queue<char>(expression);
        return ParseBoolExpr(queue);
    }

    public bool ParseBoolExpr(Queue<char> expression)
    {
        var lastFlag = char.MinValue;
        var result = true;
        while (expression.Count > 0)
        {
            var @char = expression.Dequeue();
            switch (@char)
            {
                case '&':
                case '|':
                case '!':
                    {
                        lastFlag = @char;
                        break;
                    }
                case '(':
                    {
                        switch (lastFlag)
                        {
                            case '&':
                                {
                                    return And(expression);
                                }
                            case '|':
                                {
                                    return Or(expression);
                                }
                            case '!':
                                {
                                    return Not(expression);
                                }
                        }
                        break;
                    }
                case 't':
                    {
                        return true;
                    }
                case 'f':
                    {
                        return false;
                    }
            }
        }

        return result;
    }

    private bool And(Queue<char> expression)
    {
        var result = true;
        while (expression.Count > 0)
        {
            var @char = expression.Peek();
            switch (@char)
            {
                case ',':
                    {
                        expression.Dequeue();
                        break;
                    }
                case ')':
                    {
                        expression.Dequeue();
                        return result;
                    }
                default:
                    {
                        var subResult = ParseBoolExpr(expression);
                        result &= subResult;
                        break;
                    }
            }
        }
        return result;
    }

    private bool Or(Queue<char> expression)
    {
        var result = false;
        while (expression.Count > 0)
        {
            var @char = expression.Peek();
            switch (@char)
            {
                case ',':
                    {
                        expression.Dequeue();
                        break;
                    }
                case ')':
                    {
                        expression.Dequeue();
                        return result;
                    }
                default:
                    {
                        var subResult = ParseBoolExpr(expression);
                        result |= subResult;
                        break;
                    }
            }
        }
        return result;
    }

    private bool Not(Queue<char> expression)
    {
        var subResult = ParseBoolExpr(expression);
        expression.Dequeue();
        return !subResult;
    }
}
```