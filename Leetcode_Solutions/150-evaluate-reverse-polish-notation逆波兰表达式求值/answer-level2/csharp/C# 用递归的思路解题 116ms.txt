### 解题思路
用递归的思路，从数组的末端向前处理。

### 代码

```csharp
public class Solution {

    private int _index;
  
    private int Exp(string[] tokens){
        string str = tokens[_index--];
        int tmp;
        switch(str){
            case "+": return Exp(tokens) + Exp(tokens);
            case "-": tmp = Exp(tokens);
                      return Exp(tokens) - tmp;
            case "*": return Exp(tokens) * Exp(tokens);
            case "/": tmp = Exp(tokens);
                      return Exp(tokens) / tmp;
            default : return int.Parse(str);
        }
    }

    public int EvalRPN(string[] tokens) {
        _index = tokens.Length - 1;
        return Exp(tokens);
    }
}
```