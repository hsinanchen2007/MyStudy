### 解题思路
字符串数字相乘

### 代码

```csharp
public class Solution {
    public string Multiply(string num1, string num2)
    {
        if (string.IsNullOrEmpty(num1) || string.IsNullOrEmpty(num2))
            return string.Empty;

        var result = "0";
        for (int index = 0; index < num2.Length; index++)
        {
            var temp = Multiply(num1, num2[index]);
            if (temp != "0")
            {
                temp += string.Empty.PadRight(num2.Length - index - 1, '0');
                result = Plus(result, temp);
            }
        }
        return result;
    }

    public string Multiply(string num, char time)
    {
        if (num == "0" || time == '0') return "0";
        if (time == '1') return num;
        if (num == "1") return time.ToString();
        var numStack = new Stack<char>(num);
        var resultStack = new List<char>();
        var more = 0;
        var timeValue = time - '0';
        while (numStack.Count > 0)
        {
            int currentValue = more;
            int baseValue = numStack.Pop() - '0';
            currentValue += baseValue * timeValue;
            if (currentValue >= 10)
            {
                more = currentValue / 10;
                currentValue %= 10;
            }
            else
            {
                more = 0;
            }

            resultStack.Add((char)(currentValue + '0'));
        }
        if (more > 0) resultStack.Add((char)(more + '0'));
        return new string(resultStack.Reverse<char>().ToArray());
    }

    public string Plus(string num1, string num2)
    {
        if (num1 == "0") return num2;
        if (num2 == "0") return num1;
        var num1Stack = new Stack<char>(num1);
        var num2Stack = new Stack<char>(num2);
        var resultStack = new List<char>();
        var more = 0;
        while (num1Stack.Count > 0 || num2Stack.Count > 0)
        {
            int currentValue = more;
            if (num1Stack.Count > 0)
            {
                currentValue += num1Stack.Pop() - '0';
            }
            if (num2Stack.Count > 0)
            {
                currentValue += num2Stack.Pop() - '0';
            }
            if (currentValue >= 10)
            {
                more = currentValue / 10;
                currentValue %= 10;
            }
            else
            {
                more = 0;
            }

            resultStack.Add((char)(currentValue + '0'));
        }
        if (more > 0) resultStack.Add((char)(more + '0'));
        return new string(resultStack.Reverse<char>().ToArray());
    }
}
```